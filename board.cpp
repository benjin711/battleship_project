#include "board.h"

///Standard board parameter
qint8 boardWidth = 10,
    boardLength  = 10,
    noShips = 10;

/*
 * Constructor Class Board
 */
Board::Board(QObject *parent)
    : QObject(parent), _noPlacedShips(0), _noSunkShips(0), _lengthOfCurrentShip(0)
{

    //Initializing 10x10 board
    std::vector<std::string> tmpVector;
    for(qint8 i=0; i<boardLength; i++){
        tmpVector.push_back("water");
    }

    for(qint8 k=0; k<boardWidth; k++){
        _board.push_back(tmpVector);
    }

    //Initializing the vector of ships
    _vectorOfShips.push_back(Ship("Schlachtschiff", 5, 5));
    _vectorOfShips.push_back(Ship("Kreuzer 1", 4, 4));
    _vectorOfShips.push_back(Ship("Kreuzer 2", 4, 4));
    _vectorOfShips.push_back(Ship("Zerstoerer 1", 3, 3));
    _vectorOfShips.push_back(Ship("Zerstoerer 2", 3, 3));
    _vectorOfShips.push_back(Ship("Zerstoerer 3", 3, 3));
    _vectorOfShips.push_back(Ship("U-Boot 1", 2, 2));
    _vectorOfShips.push_back(Ship("U-Boot 2", 2, 2));
    _vectorOfShips.push_back(Ship("U-Boot 3", 2, 2));
    _vectorOfShips.push_back(Ship("U-Boot 4", 2, 2));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Board::coordinatesOfShip(std::pair<int,int> c)
{
    c = static_cast<std::pair<qint8,qint8>>(c);

    static size_t status = 1;
    std::vector<std::pair<qint8,qint8> > tmpVector;

    //If status%2 == 1 is true we need to process the start coordinate
    if(status%2 == 1){

        qint8 length = getLengthOfCurrentShip()-1;

        std::pair<qint8,qint8>  tmpPair1 = c,
                                tmpPair2 = c,
                                tmpPair3 = c,
                                tmpPair4 = c;

        if(getStringOnBoard(c)!="water"){
            tmpVector.push_back({-1,-1});
            emit possibleC2(tmpVector, c, 0);

        } else {

            _C1C2.push_back(c);

            //Indicates GUI, how many coordinates are valid
            tmpVector.push_back({-2,-2});

            //Checks the coordinates above c
            if(c.first-length>=0){
                tmpPair1.first-=length;
                if(!spacesOccupied(c,tmpPair1)){
                    tmpVector.push_back(tmpPair1);
                }
            }

            //Checks the coordinates beneath c
            if(c.first+length<boardLength){
                tmpPair2.first+=length;
                if(!spacesOccupied(c,tmpPair2)){
                    tmpVector.push_back(tmpPair2);
                }
            }

            //Checks the coordinates left of c
            if(c.second-length>=0){
                tmpPair3.second-=length;
                if(!spacesOccupied(c,tmpPair3)){
                    tmpVector.push_back(tmpPair3);
                }
            }

            //Checks the coordinates right of c
            if(c.second+length<boardWidth){
                tmpPair4.second+=length;
                if(!spacesOccupied(c,tmpPair4)){
                    tmpVector.push_back(tmpPair4);
                }
            }

            //Checking if c was a valid first coordinate (position might be surrounded by ships)
            if(tmpVector.size()>1){
                emit possibleC2(tmpVector, c, getLengthOfCurrentShip());
                status++;
            } else if(tmpVector.size()==1){
                emit possibleC2(tmpVector, c, getLengthOfCurrentShip());
                getC1C2().pop_back();
            }
        }

    } else if(status%2 == 0) {
        _C1C2.push_back(c);
        setShip(_C1C2[0], _C1C2[1]);
        _C1C2.pop_back();
        _C1C2.pop_back();
        status++;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Board::spacesOccupied(std::pair<qint8,qint8> c1, std::pair<qint8,qint8> c2)
{
    //checking vertically
    if(c1.second == c2.second) {
        while(c1.first != c2.first) {
            if(getStringOnBoard(c2) != "water") {
				return true;
			}
            if(c1.first > c2.first) {
                c2.first++;
			} else {
                c2.first--;
			}
		}
	}
    //checking horizontally
    if(c1.first == c2.first) {
        while(c1.second != c2.second) {
            if(getStringOnBoard(c2) != "water") {
				return true;
			}
            if(c1.second > c2.second) {
                c2.second++;
			} else {
                c2.second--;
			}
		}
	}
	return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string& Board::getStringOnBoard(std::pair<qint8,qint8> c)
{
    return _board[c.first][c.second];
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Board::setShip(std::pair<qint8,qint8> c1, std::pair<qint8,qint8> c2)
{
    qint8 length = getLengthOfCurrentShip();

    std::vector<std::pair<qint8,qint8> > coordinates;

    //Place ship on 10x10 board and collect the coordinates of the ship in coordinates
    while(c1.first!=c2.first || c1.second!=c2.second){
        _board[c2.first][c2.second] = getShipInVectorOfLength(length).getName();
        coordinates.push_back({c2.first,c2.second});
        if(c1.first < c2.first){
            c2.first--;
        } else if(c1.first > c2.first) {
            c2.first++;
		}
        if(c1.second < c2.second){
            c2.second--;
        } else if(c1.second > c2.second){
            c2.second++;
		}
	}
    _board[c1.first][c1.second] = getShipInVectorOfLength(length).getName();
    coordinates.push_back({c1.first,c1.second});

    //Save coordinates of ship in the vector of ships
    getShipInVectorOfLength(length).getCoordinates() = coordinates;

    //Set ships attribute _placed to true
    getShipInVectorOfLength(length).getPlaced() = true;

    //Increments attribute _noPlacedShips of board
    getNoPlacedShips()++;

    //Send the coordinates of the currently to be placed ship to GUI
    emit coordinatesOfPlacedShip(coordinates);

    //Signaling GUI if all ships have been placed yet or not
    emit allShipsPlaced(_noPlacedShips==10);

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Returns reference to a ship that has not been placed yet of length length
Ship& Board::getShipInVectorOfLength(qint8 length)
{
    try{
        for(qint8 i=0; i<noShips; i++)
        {
            if((_vectorOfShips[i].getLength() == length) && (_vectorOfShips[i].getPlaced() == 0))
            {
                return _vectorOfShips[i];
            }
        }

    throw std::runtime_error("All ships of this length have already been placed!");
    }
    catch(std::exception &e)
    {
        std::cout<<e.what();
    }

    return _vectorOfShips[0];
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<Ship>& Board::getVectorOfShips()
{
    return _vectorOfShips;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

qint8& Board::getNoPlacedShips()
{
    return _noPlacedShips;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

qint8& Board::getNoSunkShips()
{
    return _noSunkShips;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Board::isShipSunk(std::string nameShip)
{
    try{
        for(qint8 i=0; i<noShips; i++){
            if(getVectorOfShips()[i].getName() == nameShip){
                return getVectorOfShips()[i].getSunk();
            } else {
                throw std::runtime_error("The parameter (ship name) given to the function isShipSunk is invalid!");
                return 0;
            }
        }
    }
    catch(std::exception &e)
    {
        std::cout<<e.what();
    }

    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

qint8& Board::getLengthOfCurrentShip()
{
    return _lengthOfCurrentShip;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Board::setLengthOfCurrentShip(int lengthOfCurrentShip)
{
    _lengthOfCurrentShip = static_cast<qint8>(lengthOfCurrentShip);
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<std::pair<qint8,qint8> >& Board::getC1C2()
{
    return _C1C2;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Board::randomShipPlacement()
{
    srand(time(0));

    //Vector that holds all the coordinates of all ships
    std::vector<std::pair<qint8,qint8> > vectorCoordinatesOfAllShips;

    //Initializing variable called length
    int length = 0;

    //Mächtige for Loop, um Schiffe zu setzen
    for(qint8 i=0; i<noShips; i++){

        //Vector that holds all possible end coordinates given a start coordinate and length of ship
        std::vector<std::pair<qint8,qint8> > possibleC2Vector;

        //To go through all the ships with their specific number and length
        switch (i) {
        case 0:
            length =4;
            break;
        case 1:
        case 2:
            length =3;
            break;
        case 3:
        case 4:
        case 5:
            length =2;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            length =1;
            break;
        }

        //Creating start coordinate
        std::pair<qint8,qint8> C1;

        do{

            //Initializing C1, might be invalid
            do{
                C1 = {rand()%10, rand()%10};
            } while (getStringOnBoard(C1)!="water");

            std::pair<qint8,qint8>      tmpPair1 = C1,
                                        tmpPair2 = C1,
                                        tmpPair3 = C1,
                                        tmpPair4 = C1;

            //Checks coordinates above C1
            if(C1.first-length>=0){
                tmpPair1.first-=length;
                if(!spacesOccupied(C1,tmpPair1)){
                    possibleC2Vector.push_back(tmpPair1);
                }
            }

            //Checks coordinates under C1
            if(C1.first+length<boardLength){
                tmpPair2.first+=length;
                if(!spacesOccupied(C1,tmpPair2)){
                    possibleC2Vector.push_back(tmpPair2);
                }
            }

            //Checks coordinates left of C1
            if(C1.second-length>=0){
                tmpPair3.second-=length;
                if(!spacesOccupied(C1,tmpPair3)){
                    possibleC2Vector.push_back(tmpPair3);
                }
            }

            //Checks coordinates right of C1
            if(C1.second+length<boardWidth){
                tmpPair4.second+=length;
                if(!spacesOccupied(C1,tmpPair4)){
                    possibleC2Vector.push_back(tmpPair4);
                }
            }

        } while (possibleC2Vector.size()==0);

        srand(time(0));
        std::pair<qint8,qint8> C2 = {possibleC2Vector[rand()%possibleC2Vector.size()]};

        //So far we have calculated valid start and end positions of a ship (C1 and C2)

        length++;

        std::vector<std::pair<qint8,qint8> > coordinates;

        //Place ship on 10x10 board and save coordinates of ship in coordinates
        while(C1.first!=C2.first || C1.second!=C2.second){

            _board[C2.first][C2.second] = getShipInVectorOfLength(length).getName();

            coordinates.push_back({C2.first,C2.second});
            if(C1.first < C2.first){
                C2.first--;
            } else if(C1.first > C2.first) {
                C2.first++;
            }
            if(C1.second < C2.second){
                C2.second--;
            } else if(C1.second > C2.second){
                C2.second++;
            }
        }
        _board[C1.first][C1.second] = getShipInVectorOfLength(length).getName();
        coordinates.push_back({C1.first,C1.second});

        //Save coordinates in the vector of ships
        getShipInVectorOfLength(length).getCoordinates() = coordinates;

        //Set attribute _placed of ship to true
        getShipInVectorOfLength(length).getPlaced() = true;

        //Incrementing attribute of board _noPlacedShips
        getNoPlacedShips()++;

        //Copy elements of coordinates in vectorCoordinatesOfAllShips
        for(qint8 l=0; l<length; l++){
            vectorCoordinatesOfAllShips.push_back(coordinates.back());
            coordinates.pop_back();
        }

    }

    emit coordinatesOfAllShips(vectorCoordinatesOfAllShips);
    emit allShipsPlaced(getNoPlacedShips()==10);
}









//    for(quint16 i=0; i<koordinatenDerSchiffe.size(); i++){
//        qDebug() <<koordinatenDerSchiffe[i].first<< "-";
//        qDebug() <<koordinatenDerSchiffe[i].second<< "\n";
//    }




//        qDebug() <<"Anfangs und Endkoordinaten: "<< C1.first << "-"<< C1.second<< "----" << C2.first << "-" << C2.second;
//        qDebug() <<"Koordinaten des gesetzen Schiffes: " << tmpVector[0].first <<", "<< tmpVector[0].second << ", "<< tmpVector[1].first << ", "<< tmpVector[1].second << ", "
//                                                         << tmpVector[2].first <<", "<< tmpVector[2].second << ", "<< tmpVector[3].first << ", "<< tmpVector[3].second << ", "
//                                                         << tmpVector[4].first <<", "<< tmpVector[4].second;






//        qDebug() << possibleC2Vector[0].first<< "-" << possibleC2Vector[0].second << "-" << possibleC2Vector[1].first << "-" << possibleC2Vector[1].second <<"-"
//                    << possibleC2Vector[3].first<< "-" << possibleC2Vector[3].second << "-" << possibleC2Vector[4].first << "-" << possibleC2Vector[4].second << "\n";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//void Board::setAnzSchiffeGesunken()
//{
//	int anzahlGesunkeneSchiffe = 0;
//	for(int i=0; i<AnzahlSchiffe; i++){
//		if(getSchiffeArray()[i].getGesunken()==1){
//			anzahlGesunkeneSchiffe++;
//		}
//	}
//    _anzSchiffeGesunken = anzahlGesunkeneSchiffe;
//}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//void Board::setAnzSchiffeGesetzt()
//{
//	int anzahlGesetzteSchiffe = 0;
//	for(int i=0; i<AnzahlSchiffe; i++){
//		if(getSchiffeArray()[i].getGesetzt()==1){
//			anzahlGesetzteSchiffe++;
//		}
//	}
//    _anzSchiffeGesetzt = anzahlGesetzteSchiffe;
//}


//	///Die Länge des Schiffes aus den Koordinaten ableiten
//	int laenge = 0;
//	if(k1.first-k2.first != 0){
//		laenge = std::abs(k1.first -k2.first) + 1;
//	} else {
//		laenge = std::abs(k1.second -k2.second) + 1;
//	}





//    qDebug() <<"Koordinaten des gesetzen Schiffes: " << tmpVector[0].first <<", "<< tmpVector[0].second << ", "<< tmpVector[1].first << ", "<< tmpVector[1].second << ", "
//                                                     << tmpVector[2].first <<", "<< tmpVector[2].second << ", "<< tmpVector[3].first << ", "<< tmpVector[3].second << ", "
//                                                     << tmpVector[4].first <<", "<< tmpVector[4].second;


