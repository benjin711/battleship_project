#include "game.h"
#include <memory>
#include <QDebug>



//Constructor class Game

Game::Game(QObject *parent)
    : QObject(parent), _player1(Player()), _player2(Player())
{
    getPlayer1().getTurn()=0;
    getPlayer2().getTurn()=0;
}


Player& Game::getPlayer1()
{

    return _player1;
}


Player& Game::getPlayer2()
{
    return _player2;
}




void Game::attackPlayer2(std::pair<quint8,quint8> c)
{
    if(getPlayer1().getTurn() && getPlayer1().getMyBoard().getNoPlacedShips()==10){
         emit attackP2Coordinate(0x03, 0x02,{{c.first},{c.second}});
        _p1AttackCoordinate = c;
    }
}


void Game::processingSCOpponent(quint8 statusCode, std::vector<std::pair<quint8,quint8> > coordinatesOfSunkShip)
{

    switch(statusCode) {

    case 0:
        //We hit water/missed.
        setTurnOfBothPlayers(0);
        emit statusCodePlayer2ToGUI(0x00, coordinatesOfSunkShip, getP1AttackCoordinate());
        break;
    case 1:
        //Hit without sinking ship.
        setTurnOfBothPlayers(0);
        getPlayer2().getHealth()--;
        getPlayer2()(getP1AttackCoordinate()) = "hit";
        emit statusCodePlayer2ToGUI(0x01, coordinatesOfSunkShip, getP1AttackCoordinate());
        break;
    case 2:
        //Hit and ship has sunk.
        setTurnOfBothPlayers(0);
        getPlayer2().getHealth()--;
        getPlayer2()(getP1AttackCoordinate()) = "hit";
        getPlayer2().getMyBoard().getNoSunkShips()++;
        emit statusCodePlayer2ToGUI(0x02, coordinatesOfSunkShip, getP1AttackCoordinate());
        break;
    case 3:
        //Hit, ship has sunk and we won.
        getPlayer2().getHealth()--;
        getPlayer2()(getP1AttackCoordinate()) = "hit";
        getPlayer2().getMyBoard().getNoSunkShips()++;
        if(getPlayer2().getHealth()==0 && getPlayer2().getMyBoard().getNoSunkShips()==10){
            emit statusCodePlayer2ToGUI(0x03, coordinatesOfSunkShip, getP1AttackCoordinate());
        }
        break;
    case 16:
        //It was not our turn to attack.
        emit statusCodePlayer2ToGUI(0x10, coordinatesOfSunkShip, getP1AttackCoordinate());
        break;
    case 17:
        //The coordinate we attacked does not exist on opponents board.
        emit statusCodePlayer2ToGUI(0x11, coordinatesOfSunkShip, getP1AttackCoordinate());
        break;
    case 32:
        //Other errors.
        emit statusCodePlayer2ToGUI(0x20, coordinatesOfSunkShip, getP1AttackCoordinate());
        break;
    default:
        throw std::runtime_error("Received invalid status code from opponent");
        break;
    }
}





void Game::attackOnPlayer1(std::pair<quint8, quint8> c)
{
    //auto Sp1SpielfeldString = std::make_shared<std::string>(getSpieler1().getMeinSpielfeldLOGIK().getSpielfeldLOGIK(k));
    std::string p1BoardStringAtC = getPlayer1()(c);
    std::vector<Ship>& p1VectorOfShips = getPlayer1().getMyBoard().getVectorOfShips();

    //Check if it was player2's turn.
    if(getPlayer2().getTurn() == 1 && getPlayer1().getTurn() == 0){

        if(getPlayer1().getMyBoard().getNoPlacedShips()!=10){

            emit ourSCtoNetwork(0x11,0x01,{0x20}); //Error. Player1 has not placed all his ships yet.

        } else if(c.first>9 ||c.second>9){

            emit ourSCtoNetwork(0x11, 0x01, {0x11}); //Error. The coordinate chosen by player2 does not exist on our board.

        } else if(p1BoardStringAtC=="water"){

            emit ourSCtoNetwork(0x11,0x01,{0x00}); //Opponent hit water. To network.
            emit infoToGuiAttackP1(0,c);
            setTurnOfBothPlayers(1);

        } else if(p1BoardStringAtC!="water" && p1BoardStringAtC!="hit"){

            getPlayer1().getHealth()--;

            for(qint8 i=0; i<10; i++){

                if(p1VectorOfShips[i].getName() == p1BoardStringAtC){

                    p1VectorOfShips[i].getHp()--;

                    p1BoardStringAtC = "hit";

                    if(p1VectorOfShips[i].getHp()==0){
                        p1VectorOfShips[i].getSunk()=true;
                        getPlayer1().getMyBoard().getNoSunkShips()++;
                    }

                    if(getPlayer1().getMyBoard().getNoSunkShips()==10 && getPlayer1().getHealth()==0){

                        std::vector<quint8> coordinatesOfSunkShip = {0x03};
                        quint8 lengthOfSunkShip = static_cast<quint8>(p1VectorOfShips[i].getLength());

                        for(quint8 l=0; l<lengthOfSunkShip; l++){
                            coordinatesOfSunkShip.push_back(p1VectorOfShips[i].getCoordinates()[l].first);
                            coordinatesOfSunkShip.push_back(p1VectorOfShips[i].getCoordinates()[l].second);
                        }

                        emit ourSCtoNetwork(0x11, 1+lengthOfSunkShip*2, coordinatesOfSunkShip);
                        emit infoToGuiAttackP1(0x03,c);

                    } else if(p1VectorOfShips[i].getSunk()==true){

                        std::vector<quint8> coordinatesOfSunkShip = {0x02};
                        quint8 lengthOfSunkShip = static_cast<quint8>(p1VectorOfShips[i].getLength());

                        for(quint8 l=0; l<lengthOfSunkShip; l++){
                            coordinatesOfSunkShip.push_back(p1VectorOfShips[i].getCoordinates()[l].first);
                            coordinatesOfSunkShip.push_back(p1VectorOfShips[i].getCoordinates()[l].second);
                        }

                        emit ourSCtoNetwork(0x11,1+lengthOfSunkShip*2, coordinatesOfSunkShip);
                        emit infoToGuiAttackP1(0x02, c);
                        setTurnOfBothPlayers(1);

                    } else if(p1VectorOfShips[i].getSunk()!=true){

                        emit ourSCtoNetwork(0x11, 0x01, {0x01});
                        emit infoToGuiAttackP1(0x01, c);
                        setTurnOfBothPlayers(1);

                    }
                }
            }
        } else if (p1BoardStringAtC!="water" && p1BoardStringAtC=="hit"){
            emit ourSCtoNetwork(0x11, 0x01, {0x01});
            setTurnOfBothPlayers(1);
        }

    // It was not player2's turn.
    } else if(getPlayer2().getTurn() == 0 && getPlayer1().getTurn() == 1){
        emit ourSCtoNetwork(0x11,0x01,{0x10});
    }
}






void Game::setTurnOfBothPlayers(bool signal)
{
    getPlayer1().getTurn()=signal;
    getPlayer2().getTurn()=(!signal);
}


//            qDebug() << "Wir laufen hier rein, obwohl das Feld zerstört sein sollte";

//    qDebug() << "Größe der in verarbeiteSCGegner übergebenen Vektors"<< tmpVector.size();
//    if(tmpVector.size()!=0){
//        for(quint8 i=0;i<tmpVector.size();i++){
//            qDebug() << tmpVector[i].first << "-" << tmpVector[i].second;
//        }
//    }



//    qDebug() << tmpVector[0].first<< "-" << tmpVector[0].second << "-" << tmpVector[1].first << "-" << tmpVector[1].second <<"-"
//                                  <<tmpVector[2].first << "-" << tmpVector[2].second << "-"
//                << tmpVector[3].first<< "-" << tmpVector[3].second << "-" << tmpVector[4].first << "-" << tmpVector[4].second << "\n";



//  qDebug() << statusCode;

//        qDebug() << "Schauen, ob Leben von Spieler2 tatsächlich 0 ist: "<< getSpieler2().getLeben();

//  qDebug() << "Spiel::angriffAufSpieler1: shot= " << k.first << ", " << k.second;



//                qDebug() << "Schauen ob die Leben weggehen: " << getSpieler1().getLeben();
//                qDebug() << "Schauen, dass das Schiff auch gesunken ist. Falls ja wird 1 erwartet: "<<Sp1SpielfeldSchiffeArray[i].getGesunken();



//      qDebug() << "\tnot enemy turn";

