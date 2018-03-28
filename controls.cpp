#include "controls.h"
#include "client.h"
#include "network.h"
#include "schiff.h"
#include "server.h"
#include "spiel.h"
#include "spieler.h"
#include "spielfeld.h"
#include "spielfeldLOGIK.h"
#include "startfenster.h"


Controls::Controls()
    :QObject(nullptr)
{

    //Instanz von Klasse Spiel (Logik)
    //Spiel* NeuesSpiel = new Spiel();

    //Instanz von Klasse Spielfeld (GUI)
    //Spielfeld* NeuesSpielfeldGUI = new Spielfeld();

    //Instanz von Klasse "Netzwerk" (Netzwerk)
    //???


    startfenster = new Startfenster(this);
    startfenster->show();
    NeuesSpiel = new Spiel(this);




    //Connects GUI-Netzwerk

    connect(startfenster, &Startfenster::ClientMode, this, &Controls::onConnectToServer);
    connect(startfenster, &Startfenster::ServerMode, this, &Controls::onNewConnection);




    //Connects Logik-GUI

    // GUI sendet die Länge des aktuell zu setzenden Schiffes an LOGIK. Parameter: int
    connect(startfenster->spielfeld, &Spielfeld::length, &NeuesSpiel->getSpieler1().getMeinSpielfeldLOGIK(),&SpielfeldLOGIK::setAktLaengeSchiff);

    // GUI sendet K (K1 UND K2!) an LOGIK. Parameter: std::pair
    connect(startfenster->spielfeld, &Spielfeld::buttonPressed1, &NeuesSpiel->getSpieler1().getMeinSpielfeldLOGIK(), &SpielfeldLOGIK::moeglicheK2);

    // LOGIK sendet mögliche K2 an GUI und K1. Paramter: std::vector<std::pair<int,int>> und std::pair<int,int>
    connect(&NeuesSpiel->getSpieler1().getMeinSpielfeldLOGIK(), &SpielfeldLOGIK::sigMoeglicheK2, startfenster->spielfeld, &Spielfeld::endposition);

    // LOGIK sendet alle Koordinaten des gesetzen Schiffes an GUI. Parameter: std::vector<std::pair<int,int> >
    connect(&NeuesSpiel->getSpieler1().getMeinSpielfeldLOGIK(), &SpielfeldLOGIK::koordSchiff, startfenster->spielfeld, &Spielfeld::setShip);

    // Angriff auf Player1: LOGIK sendet an GUI, den Status nach dem Anfgriff vom Gegner und die Koordinate auf die der Gegner geschossen hat
    connect(NeuesSpiel, &Spiel::weitergabeAnGUI, startfenster->spielfeld, &Spielfeld::hitplayer1);


    // Anfgriff auf Player2. GUI gibt LOGIK die von Player1 geklickte Koordinate.
    connect(startfenster->spielfeld, &Spielfeld::buttonPressed2, NeuesSpiel, &Spiel::angriffAufSpieler2);

    connect(&NeuesSpiel->getSpieler1().getMeinSpielfeldLOGIK(), &SpielfeldLOGIK::sigAlleSchiffeGesetzt, startfenster->spielfeld, &Spielfeld::startGame);

    //Zufällige Positionen für Schiffe
    connect(&NeuesSpiel->getSpieler1().getMeinSpielfeldLOGIK(), &SpielfeldLOGIK::koordinatenAllerSchiffe, startfenster->spielfeld, &Spielfeld::randomPositions);
    connect(startfenster->spielfeld, &Spielfeld::ZufallsButtonclicked, &NeuesSpiel->getSpieler1().getMeinSpielfeldLOGIK(), &SpielfeldLOGIK::zufaelligSchiffeSetzen);

    //


    // Angriff auf Player2. LOGIK gibt GUI StatusCode, Vektor und aktAngriffKoord weiter.
    connect(NeuesSpiel, &Spiel::statusCodeVonGegner, startfenster->spielfeld, &Spielfeld::hitplayer2);



    //Connects Logik-Netzwerk

    // NW sendet ein Bool, das der LOGIK sagt, ob Spieler 1 oder Spieler 2 anfängt

    // NW sendet LOGIK die Koordinate auf die der Gegner schießt

    // LOGIK sendet NW die Antwort auf den Anfgriff vom Gegner (getroffen, nicht getroffen, Spiel zu Ende etc)

    // Angriff auf Player2. LOGIK sendet NW die zu beschießende Koordinate.

    // Angriff auf Player2. NW sendet mir StatusCode und Vector mit versenkten Schiffkoordinaten vom Gegner



}


void Controls::onConnectToServer(QString host, quint16 port) {
    Network = new client(this);
    auto Client = dynamic_cast<client*>(Network);
 connect(Client, &client::NetworkToGui, startfenster, &Startfenster::readFromNetwork);
    Client->connectToServer(host, port);


    connect(startfenster, &Startfenster::disconnectButton, Client, &client::disconnectFromServer);
    connect(startfenster->spielfeld, &Spielfeld::disconnectButtonGame, Client, &client::disconnectFromServer);

    establishConnection();
}

void Controls::onNewConnection(quint16 port) {
    Network = new server(this);
    auto Server = dynamic_cast<server*>(Network);
    connect(Server, &server::NetworkToGui, startfenster, &Startfenster::readFromNetwork);
    Server->newConnection(port);

    connect(startfenster, &Startfenster::disconnectButton, Server, &server::Disconnection);
    connect(startfenster->spielfeld, &Spielfeld::disconnectButtonGame, Server, &server::Disconnection);


    establishConnection();
}

void Controls::establishConnection() {
    qDebug() << "Controls::establishConnection";
    connect(Network,&network::GameStart, NeuesSpiel, &Spiel::setAmZugBeideSpieler);
    connect(Network,&network::ShotAnswer , NeuesSpiel, &Spiel::verarbeiteSCGegner);
    connect(NeuesSpiel, &Spiel::koordWeitergabeAnNW,Network, &network::send);
    connect(NeuesSpiel, &Spiel::rueckgabeAnNW,Network, &network::send);
  

     connect(Network, &network::Shot, NeuesSpiel, &Spiel::angriffAufSpieler1);

     connect(startfenster->spielfeld, &Spielfeld::StartSpielfeldPressed, Network, &network::StartButtonPressed);
}


