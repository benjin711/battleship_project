#include "spiel.h"
#include <memory>
#include <QDebug>


///Implementation Klasse Spiel

Spiel::Spiel(QObject *parent)
    : QObject(parent), _spieler1(Spieler(1)), _spieler2(Spieler(2))
{
    getSpieler1().setAmZug(0);
    getSpieler1().setAmZug(0);
}


Spieler& Spiel::getSpieler1()
{

    return _spieler1;
}


Spieler& Spiel::getSpieler2()
{
    return _spieler2;
}




bool Spiel::angriffAufSpieler2(std::pair<quint8,quint8> k)
{
    if(getSpieler1().getAmZug() && getSpieler1().getMeinSpielfeldLOGIK().getAnzSchiffeGesetzt()==10){
         emit koordWeitergabeAnNW(0x03, 0x02,{{k.first},{k.second}}); //emit Koordinate an Netzwerk
        _aktAngrKoord = k;
        return 1;
    }
    return 0;
}


void Spiel::verarbeiteSCGegner(quint8 statusCode, std::vector<std::pair<quint8,quint8> > tmpVector)
{
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
    switch(statusCode) {

    case 0:
        //Wasser getroffen
        //Ändern des SpielfeldsLOGIK des Gegners bringt nichts. GUI soll dafür sorgen,
        //dass nicht mehr auf das selbe Feld geklickt wird.
        emit statusCodeVonGegner(0x00, tmpVector, getAktAngrKoord());//emit irgendwas an GUI, sodass Daneben! geprintet wird.
        setAmZugBeideSpieler(0);
        break;
    case 1:
        //Einfacher Treffer
        //emit irgendwas an GUI, sodass Treffer geprintet wird und emit _aktAngrKoord.

        emit statusCodeVonGegner(0x01, tmpVector, getAktAngrKoord());
        setAmZugBeideSpieler(0);
        getSpieler2().getLeben()--;
        break;
    case 2:
        //Treffer und Schiff des Gegners gesunken.
        //emit irgendwas an GUI, sodass Treffer geprintet wird und emit den Vector mit pairs,
        //sodass GUI die Felder markieren kann
        emit statusCodeVonGegner(0x02, tmpVector, getAktAngrKoord());
        setAmZugBeideSpieler(0);
        getSpieler2().getLeben()--;
        break;
    case 3:
        //Treffer, Schiff gesunken und Spiel gewonnen.
        //emit irgendwas an GUI, sodass Treffer geprintet wird und emit den Vector mit pairs,
        //sodass GUI die Felder markieren kann und emit Wir haben gewonnen! falls
        getSpieler2().getLeben()--;

        qDebug() << "Schauen, ob Leben von Spieler2 tatsächlich 0 ist: "<< getSpieler2().getLeben();

        if(getSpieler2().getLeben()==0){
            //emit Wir haben gewonnen!
            emit statusCodeVonGegner(0x03, tmpVector, getAktAngrKoord());
        }
        break;
    case 16:
        //emit irgendwas an GUI, um zu printen, dass wir nicht an der Reihe sind.
        emit statusCodeVonGegner(0x10, tmpVector, getAktAngrKoord());
        break;
    case 17:
        //emit irgendwas an GUI, um zu printen, dass k außerhalb vom Spielfeld ist.
        emit statusCodeVonGegner(0x11, tmpVector, getAktAngrKoord());
        break;
    case 32:
        // emit sonstiger fehler
        emit statusCodeVonGegner(0x20, tmpVector, getAktAngrKoord());
        break;
    default:
        throw std::runtime_error("Received invalid status code from opponent");
        break;
    }
}





void Spiel::angriffAufSpieler1(std::pair<quint8, quint8> k)
{
//  qDebug() << "Spiel::angriffAufSpieler1: shot= " << k.first << ", " << k.second;
    int AnzahlSchiffe = 10;
    auto Sp1SpielfeldString = std::make_shared<std::string>(getSpieler1().getMeinSpielfeldLOGIK().getSpielfeldLOGIK(k));


    std::vector<Schiff>& Sp1SpielfeldSchiffeArray = getSpieler1().getMeinSpielfeldLOGIK().getSchiffeArray();

    if(getSpieler2().getAmZug() == 1){


    if(getSpieler1().getMeinSpielfeldLOGIK().getAnzSchiffeGesetzt()!=10){

        emit rueckgabeAnNW(0x11,0x01,{0x20}); //Sonstiger Fehler. Noch nicht alle Schiffe gesetzt

    } else if(getSpieler2().getAmZug() == 0){
//      qDebug() << "\tnot enemy turn";
        emit rueckgabeAnNW(0x11,0x01,{0x10}); // an NW. Gegner ist nicht dran.

    } else if(k.first>9 ||k.second>9){

        emit rueckgabeAnNW(0x11, 0x01, {0x11}); // an NW. Gegner setzt außerhalb des Feldes.

    } else if(*Sp1SpielfeldString=="Wasser"){
//      qDebug() << "\twater";
        emit rueckgabeAnNW(0x11,0x01,{0x00}); //an NW. Gegner hat nicht getroffen.
        emit weitergabeAnGUI(0,k); //an GUI. Gegner hat nicht getroffen + k
        setAmZugBeideSpieler(1);
    } else if(*Sp1SpielfeldString!="Wasser" && *Sp1SpielfeldString!="Zerstoert!"){

        qDebug() << "Wir laufen hier rein, obwohl das Feld zerstört sein sollte";
        getSpieler1().getLeben()--;

        for(int i=0; i<AnzahlSchiffe; i++){

            if(Sp1SpielfeldSchiffeArray[i].getName() == *Sp1SpielfeldString){

                Sp1SpielfeldSchiffeArray[i].getLeben()--;


                *Sp1SpielfeldString = "Zerstoert!";



                if(Sp1SpielfeldSchiffeArray[i].getLeben()==0){
                    Sp1SpielfeldSchiffeArray[i].setGesunken(1);
                    getSpieler1().getMeinSpielfeldLOGIK().getAnzSchiffeGesunken()++;
                }

                qDebug() << "Schauen ob die Leben weggehen: " << getSpieler1().getLeben();
                qDebug() << "Schauen, dass das Schiff auch gesunken ist. Falls ja wird 1 erwartet: "<<Sp1SpielfeldSchiffeArray[i].getGesunken();


                if(Sp1SpielfeldSchiffeArray[i].getGesunken()==true && getSpieler1().getLeben()==0){

                    if(getSpieler1().getLeben()==0){
                        std::vector<quint8> tmpVector = {0x03};
                        quint8 tmpLaenge = static_cast<quint8>(Sp1SpielfeldSchiffeArray[i].getLaenge());
                        for(int l=0; l<tmpLaenge; l++){
                            tmpVector.push_back(Sp1SpielfeldSchiffeArray[i].getKoordinaten()[l].first);
                            tmpVector.push_back(Sp1SpielfeldSchiffeArray[i].getKoordinaten()[l].second);
                        }
                        emit rueckgabeAnNW(0x11, 1+tmpLaenge*2, tmpVector); // 3 zur GUI und NW, dass wir verloren haben und Koordinaten an NW
                        emit weitergabeAnGUI(0x03,k);
                    }

                    emit rueckgabeAnNW(0x11,0x01,{0x11}); //NW

                } else if(Sp1SpielfeldSchiffeArray[i].getGesunken()==1){
                    std::vector<quint8> tmpVector = {0x02};
                    quint8 tmpLaenge = static_cast<quint8>(Sp1SpielfeldSchiffeArray[i].getLaenge());
                    for(int l=0; l<tmpLaenge; l++){
                        tmpVector.push_back(Sp1SpielfeldSchiffeArray[i].getKoordinaten()[l].first);
                        tmpVector.push_back(Sp1SpielfeldSchiffeArray[i].getKoordinaten()[l].second);
                    }
                    emit rueckgabeAnNW(0x11,1+tmpLaenge*2, tmpVector); //2 und *Sp1SpielfeldSchiffeArray[i].getKoordinaten()
                    emit weitergabeAnGUI(0x02, k);//GUI, dass Gegner getroffen hat und *Sp1SpielfeldSchiffeArray[i].getName() gesunken ist
                    setAmZugBeideSpieler(1);

                } else {

                    emit rueckgabeAnNW(0x11, 0x01, {0x01});//1 NW
                    emit weitergabeAnGUI(0x01, k);//Gegner hat *Sp1SpielfeldSchiffeArray[i].getName() getroffen
                    setAmZugBeideSpieler(1);

                }
            }
        }
    } else if (*Sp1SpielfeldString!="Wasser" && *Sp1SpielfeldString=="Zerstoert!"){
        emit rueckgabeAnNW(0x11, 0x01, {0x01});
        setAmZugBeideSpieler(1);
    }





}
    else
    {
//      qDebug() << "\tnot enemy turn";
        emit rueckgabeAnNW(0x11,0x01,{0x10}); // an NW. Gegner ist nicht dran.
    }
}






void Spiel::setAmZugBeideSpieler(bool tmpBool)
{
    getSpieler1().setAmZug(tmpBool);
    getSpieler2().setAmZug(!tmpBool);
}


















