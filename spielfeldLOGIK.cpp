#include "spielfeldLOGIK.h"

#include "button.h"
#include "spielfeld.h"

#include <cmath>
#include <QDebug>
/*
 * Implementation Klasse SpielfeldLOGIK
 */

///Standardfeldparameter
int feldbreite = 10,
    feldlaenge  = 10,
    AnzahlSchiffe = 10;

///SpielfeldLOGIK mit Wasser initialisieren und alle Schiffe im schiffeArray anlegen
SpielfeldLOGIK::SpielfeldLOGIK(QObject *parent)
    : QObject(parent), _anzSchiffeGesetzt(0), _anzSchiffeGesunken(0), _aktLaengeSchiff(0)
{

    std::vector<std::string> tmpVector;
    for(int i=0; i<feldlaenge; i++){
        tmpVector.push_back("Wasser");
    }

    for(int k=0; k<feldbreite; k++){
        _spielfeldLOGIK.push_back(tmpVector);
    }

    _schiffeArray.push_back(Schiff("Schlachtschiff", 5, 5));
    _schiffeArray.push_back(Schiff("Kreuzer 1", 4, 4));
    _schiffeArray.push_back(Schiff("Kreuzer 2", 4, 4));
    _schiffeArray.push_back(Schiff("Zerstoerer 1", 3, 3));
    _schiffeArray.push_back(Schiff("Zerstoerer 2", 3, 3));
    _schiffeArray.push_back(Schiff("Zerstoerer 3", 3, 3));
    _schiffeArray.push_back(Schiff("U-Boot 1", 2, 2));
    _schiffeArray.push_back(Schiff("U-Boot 2", 2, 2));
    _schiffeArray.push_back(Schiff("U-Boot 3", 2, 2));
    _schiffeArray.push_back(Schiff("U-Boot 4", 2, 2));
}




void SpielfeldLOGIK::moeglicheK2(std::pair<int,int> k)
{
    static int status = 1;
    std::vector<std::pair<int,int> > tmpVector;
    if(status%2 == 1){
        _aktK1K2.push_back(k);
        int laenge = getAktLaengeSchiff()-1;

        std::pair<int,int>  tmpPair1 = k,
                            tmpPair2 = k,
                            tmpPair3 = k,
                            tmpPair4 = k;
        if(getSpielfeldLOGIK(k)!="Wasser"){
            tmpVector.push_back({-1,-1});
            emit sigMoeglicheK2(tmpVector, k, 0);
            tmpVector.pop_back();
        } else {
        //Zeigt GUI, wie viele Koordinaten gültig sind
        tmpVector.push_back({-2,-2});

        //Checkt die Koordinaten oberhalb k
        if(k.first-laenge>=0){
            tmpPair1.first-=laenge;
            if(!felderZwiBesetzt(k,tmpPair1)){
                tmpVector.push_back(tmpPair1);
            }
        }

        //Checkt die Koordianten unterhalb k
        if(k.first+laenge<feldlaenge){
            tmpPair2.first+=laenge;
            if(!felderZwiBesetzt(k,tmpPair2)){
                tmpVector.push_back(tmpPair2);
            }
        }


        if(k.second-laenge>=0){
            tmpPair3.second-=laenge;
            if(!felderZwiBesetzt(k,tmpPair3)){
                tmpVector.push_back(tmpPair3);
            }
        }
        if(k.second+laenge<feldbreite){
            tmpPair4.second+=laenge;
            if(!felderZwiBesetzt(k,tmpPair4)){
                tmpVector.push_back(tmpPair4);
            }
        }
        if(tmpVector.size()>1){
            emit sigMoeglicheK2(tmpVector, k, getAktLaengeSchiff());
            status++;
        } else {
            emit sigMoeglicheK2(tmpVector, k, getAktLaengeSchiff());
            getAktK1K2().pop_back();
        }

        }
    } else if(status%2 == 0) {
        _aktK1K2.push_back(k);
        setSchiff(_aktK1K2[0], _aktK1K2[1]);
        _aktK1K2.pop_back();
        _aktK1K2.pop_back();
        status++;
    }
}


bool SpielfeldLOGIK::felderZwiBesetzt(std::pair<int,int> k1, std::pair<int,int> k2)
{
	///horizontal checken
	if(k1.second == k2.second) {
		while(k1.first != k2.first) {
            if(getSpielfeldLOGIK(k2) != "Wasser") {
				return true;
			}
			if(k1.first > k2.first) {
				k2.first++;
			} else {
				k2.first--;
			}
		}
	}
	///vertical checken
	if(k1.first == k2.first) {
		while(k1.second != k2.second) {
            if(getSpielfeldLOGIK(k2) != "Wasser") {
				return true;
			}
			if(k1.second > k2.second) {
				k2.second++;
			} else {
				k2.second--;
			}
		}
	}
	return false;
}

///Gibt String aus dem SpielfeldLOGIK aus
std::string& SpielfeldLOGIK::getSpielfeldLOGIK(std::pair<int,int> k)
{
    return _spielfeldLOGIK[k.first][k.second];
}


///
void SpielfeldLOGIK::setSchiff(std::pair<int,int> k1, std::pair<int,int> k2)
{
	///Die Länge des Schiffes aus den Koordinaten ableiten
	int laenge = 0;
	if(k1.first-k2.first != 0){
		laenge = std::abs(k1.first -k2.first) + 1;
	} else {
		laenge = std::abs(k1.second -k2.second) + 1;
	}
	///Speichern der Koordinaten des Schiffes in tmpVector
	std::vector<std::pair<int,int> > tmpVector;
    ///Je nach Länge des Schiffes die Felder im SpielfeldLOGIK auf den Namen des Schiffes setzen
	while(k1.first!=k2.first || k1.second!=k2.second){
        _spielfeldLOGIK[k2.first][k2.second] = getSchiffImArray(laenge).getName();
		tmpVector.push_back({k2.first,k2.second});
		if(k1.first < k2.first){
			k2.first--;
		} else if(k1.first > k2.first) {
			k2.first++;
		}
		if(k1.second < k2.second){
			k2.second--;
		} else if(k1.second > k2.second){
			k2.second++;
		}
	}
    _spielfeldLOGIK[k1.first][k1.second] = getSchiffImArray(laenge).getName();
	tmpVector.push_back({k1.first,k1.second});


//    qDebug() <<"Koordinaten des gesetzen Schiffes: " << tmpVector[0].first <<", "<< tmpVector[0].second << ", "<< tmpVector[1].first << ", "<< tmpVector[1].second << ", "
//                                                     << tmpVector[2].first <<", "<< tmpVector[2].second << ", "<< tmpVector[3].first << ", "<< tmpVector[3].second << ", "
//                                                     << tmpVector[4].first <<", "<< tmpVector[4].second;

	getSchiffImArray(laenge).setKoordinaten(tmpVector);

	///Attribut des gesetzten Schiffes im Array _gesetzt auf true stellen
	getSchiffImArray(laenge).setGesetzt(1);

    ///Attribut anzSchiffeGesetzt aktualisieren bzw inkrementieren
    setAnzSchiffeGesetzt();

    ///emit tmpVector mit allen Koordinaten des Schiffes an GUI
    emit koordSchiff(tmpVector);

    ///emit Bool, ob alle Schiffe schon gesetzt wurden. 1-> Ja. 0-> Nein.
    emit sigAlleSchiffeGesetzt(_anzSchiffeGesetzt==10);

}


///Returned ein noch unplatziertes Schiffobjekt der Länge laenge aus dem Array
Schiff& SpielfeldLOGIK::getSchiffImArray(int laenge)
{

	for(int i=0; i<AnzahlSchiffe; i++)
	{
		if((_schiffeArray[i].getLaenge() == laenge) && (_schiffeArray[i].getGesetzt() == 0))
		{
			return _schiffeArray[i];
		}
	}

    throw std::runtime_error("Schiff not found");
}



std::vector<Schiff>& SpielfeldLOGIK::getSchiffeArray()
{
	return _schiffeArray;
}


int& SpielfeldLOGIK::getAnzSchiffeGesetzt()
{
    return _anzSchiffeGesetzt;
}



void SpielfeldLOGIK::setAnzSchiffeGesetzt()
{
	int anzahlGesetzteSchiffe = 0;
	for(int i=0; i<AnzahlSchiffe; i++){
		if(getSchiffeArray()[i].getGesetzt()==1){
			anzahlGesetzteSchiffe++;
		}
	}
    _anzSchiffeGesetzt = anzahlGesetzteSchiffe;
}



int& SpielfeldLOGIK::getAnzSchiffeGesunken()
{
    return _anzSchiffeGesunken;
}

void SpielfeldLOGIK::setAnzSchiffeGesunken()
{
	int anzahlGesunkeneSchiffe = 0;
	for(int i=0; i<AnzahlSchiffe; i++){
		if(getSchiffeArray()[i].getGesunken()==1){
			anzahlGesunkeneSchiffe++;
		}
	}
    _anzSchiffeGesunken = anzahlGesunkeneSchiffe;
}

bool SpielfeldLOGIK::istSchiffGesunken(std::string nameSchiff)
{
	for(int i=0; i<AnzahlSchiffe; i++){
		if(getSchiffeArray()[i].getName() == nameSchiff){
			return getSchiffeArray()[i].getGesunken();
            ///Nur wenn nameSchiff nicht dem möglichen Namen entspricht
		} else {
			return 0;
		}
	}
    return 0;
}



int& SpielfeldLOGIK::getAktLaengeSchiff()
{
    return _aktLaengeSchiff;
}

void SpielfeldLOGIK::setAktLaengeSchiff(int NAktLaengeSchiff)
{
    _aktLaengeSchiff=NAktLaengeSchiff;
}


std::vector<std::pair<int,int> >& SpielfeldLOGIK::getAktK1K2(){
    return _aktK1K2;
}



void SpielfeldLOGIK::setAktK1K2(std::vector<std::pair<int,int> > NK1K2){
    _aktK1K2 = NK1K2;
}





/////////////////////////////////////////////////////

void SpielfeldLOGIK::zufaelligSchiffeSetzen()
{
    //Vektor mit allen Koordinaten der Schiffe
    std::vector<std::pair<int,int> > koordinatenDerSchiffe;

    //Länge des Schiffes erstellen
    int laenge = 0;

    //Mächtige for Loop, um Schiffe zu setzen
    for(int i=0; i<10; i++ ){

        //Vector mit allen möglichen K2 Koordinaten
        std::vector<std::pair<int,int> > moeglicheK2Vector;

        //Länge des Schiffes festlegen
        switch (i) {
        case 0:
            laenge =4;
            break;
        case 1:
        case 2:
            laenge =3;
            break;
        case 3:
        case 4:
        case 5:
            laenge =2;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            laenge =1;
            break;
        }

        //Anfangskoordinate erstellen
        std::pair<int,int> Anfang;

        do{

            //Anfangskoordinate initialisieren, könnte, wenn umzingelt, ungültig sein
            do{
                Anfang = {rand()%10, rand()%10};
            } while (getSpielfeldLOGIK(Anfang)!="Wasser");

            //Erstelle 4 Kopien der wahrscheinlich gültigen Anfangskoordinate
            std::pair<int,int>       tmpPair1 = Anfang,
                                     tmpPair2 = Anfang,
                                     tmpPair3 = Anfang,
                                     tmpPair4 = Anfang;

            //Checkt die Koordinaten oberhalb Anfang
            if(Anfang.first-laenge>=0){
                tmpPair1.first-=laenge;
                if(!felderZwiBesetzt(Anfang,tmpPair1)){
                    moeglicheK2Vector.push_back(tmpPair1);
                }
            }

            //Checkt die Koordianten unterhalb Anfang
            if(Anfang.first+laenge<feldlaenge){
                tmpPair2.first+=laenge;
                if(!felderZwiBesetzt(Anfang,tmpPair2)){
                    moeglicheK2Vector.push_back(tmpPair2);
                }
            }

            //Checkt die Koordinaten links von Anfang
            if(Anfang.second-laenge>=0){
                tmpPair3.second-=laenge;
                if(!felderZwiBesetzt(Anfang,tmpPair3)){
                    moeglicheK2Vector.push_back(tmpPair3);
                }
            }

            //Checkt die Koordinaten rechts von Anfang
            if(Anfang.second+laenge<feldbreite){
                tmpPair4.second+=laenge;
                if(!felderZwiBesetzt(Anfang,tmpPair4)){
                    moeglicheK2Vector.push_back(tmpPair4);
                }
            }

        } while (moeglicheK2Vector.size()==0);

//        qDebug() << moeglicheK2Vector[0].first<< "-" << moeglicheK2Vector[0].second << "-" << moeglicheK2Vector[1].first << "-" << moeglicheK2Vector[1].second <<"-"
//                    << moeglicheK2Vector[3].first<< "-" << moeglicheK2Vector[3].second << "-" << moeglicheK2Vector[4].first << "-" << moeglicheK2Vector[4].second << "\n";

        srand(time(0));
        std::pair<int,int> Ende = {moeglicheK2Vector[rand()%moeglicheK2Vector.size()]};

        //////////////Hier haben wir die gültigen Anfangs und Endpositionen des Schiffes erhalten in Anfang und Ende

        laenge++;

        std::vector<std::pair<int,int> > tmpVector;
        //Je nach Länge des Schiffes die Felder im SpielfeldLOGIK auf den Namen des Schiffes setzen
        while(Anfang.first!=Ende.first || Anfang.second!=Ende.second){
            //Name des Schiffes wird ins Array
            _spielfeldLOGIK[Ende.first][Ende.second] = getSchiffImArray(laenge).getName();

            //qDebug() << tmpVector.size();


            tmpVector.push_back({Ende.first,Ende.second});
            if(Anfang.first < Ende.first){
                Ende.first--;
            } else if(Anfang.first > Ende.first) {
                Ende.first++;
            }
            if(Anfang.second < Ende.second){
                Ende.second--;
            } else if(Anfang.second > Ende.second){
                Ende.second++;
            }
        }
        _spielfeldLOGIK[Anfang.first][Anfang.second] = getSchiffImArray(laenge).getName();
        tmpVector.push_back({Anfang.first,Anfang.second});

//        qDebug() <<"Anfangs und Endkoordinaten: "<< Anfang.first << "-"<< Anfang.second<< "----" << Ende.first << "-" << Ende.second;
//        qDebug() <<"Koordinaten des gesetzen Schiffes: " << tmpVector[0].first <<", "<< tmpVector[0].second << ", "<< tmpVector[1].first << ", "<< tmpVector[1].second << ", "
//                                                         << tmpVector[2].first <<", "<< tmpVector[2].second << ", "<< tmpVector[3].first << ", "<< tmpVector[3].second << ", "
//                                                         << tmpVector[4].first <<", "<< tmpVector[4].second;


        //Koordinaten des Schiffes im SchiffeArray setzen
        getSchiffImArray(laenge).setKoordinaten(tmpVector);

        //Attribut des gesetzten Schiffes im Array _gesetzt auf true stellen
        getSchiffImArray(laenge).setGesetzt(1);

        //Attribut anzSchiffeGesetzt aktualisieren bzw inkrementieren
        setAnzSchiffeGesetzt();


        //tmpVector Elemente in koordinatenDerSchiffe setzen
        for(int l=0; l<laenge; l++){
            koordinatenDerSchiffe.push_back(tmpVector.back());
            tmpVector.pop_back();
        }

    }


//    for(quint16 i=0; i<koordinatenDerSchiffe.size(); i++){
//        qDebug() <<koordinatenDerSchiffe[i].first<< "-";
//        qDebug() <<koordinatenDerSchiffe[i].second<< "\n";
//    }


    emit koordinatenAllerSchiffe(koordinatenDerSchiffe);
    emit sigAlleSchiffeGesetzt(getAnzSchiffeGesetzt()==10);
}















