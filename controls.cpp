#include "controls.h"
#include "client.h"
#include "network.h"
#include "ship.h"
#include "server.h"
#include "game.h"
#include "player.h"
#include "spielfeld.h"
#include "board.h"
#include "startfenster.h"


Controls::Controls()
    :QObject(nullptr)
{

    startfenster = new Startfenster(this);
    startfenster->show();
    NewGame = new Game(this);




    //Connects GUI-Netzwerk

    connect(startfenster, &Startfenster::ClientMode, this, &Controls::onConnectToServer);
    connect(startfenster, &Startfenster::ServerMode, this, &Controls::onNewConnection);




    //Connects Logik-GUI

    // GUI sendet die Länge des aktuell zu setzenden Schiffes an LOGIK.
    connect(startfenster->spielfeld, &Spielfeld::length, &NewGame->getPlayer1().getMyBoard(), &Board::setLengthOfCurrentShip);

    // GUI sendet K (K1 UND K2!) an LOGIK.
    connect(startfenster->spielfeld, &Spielfeld::buttonPressed1, &NewGame->getPlayer1().getMyBoard(), &Board::coordinatesOfShip);

    // LOGIK sendet mögliche K2 an GUI und K1.
    connect(&NewGame->getPlayer1().getMyBoard(), &Board::possibleC2, startfenster->spielfeld, &Spielfeld::endposition);

    // LOGIK sendet alle Koordinaten des gesetzen Schiffes an GUI.
    connect(&NewGame->getPlayer1().getMyBoard(), &Board::coordinatesOfPlacedShip, startfenster->spielfeld, &Spielfeld::setShip);

    // Angriff auf Player1: LOGIK sendet an GUI, den Status nach dem Anfgriff vom Gegner und die Koordinate auf die der Gegner geschossen hat
    connect(NewGame, &Game::infoToGuiAttackP1, startfenster->spielfeld, &Spielfeld::hitplayer1);


    // Anfgriff auf Player2. GUI gibt LOGIK die von Player1 geklickte Koordinate.
    connect(startfenster->spielfeld, &Spielfeld::buttonPressed2, NewGame, &Game::attackPlayer2);

    connect(&NewGame->getPlayer1().getMyBoard(), &Board::allShipsPlaced, startfenster->spielfeld, &Spielfeld::startGame);

    //Zufällige Positionen für Schiffe
    connect(&NewGame->getPlayer1().getMyBoard(), &Board::coordinatesOfAllShips, startfenster->spielfeld, &Spielfeld::randomPositions);
    connect(startfenster->spielfeld, &Spielfeld::ZufallsButtonclicked, &NewGame->getPlayer1().getMyBoard(), &Board::randomShipPlacement);


    // Angriff auf Player2. LOGIK gibt GUI StatusCode, Vektor und aktAngriffKoord weiter.
    connect(NewGame, &Game::statusCodePlayer2ToGUI, startfenster->spielfeld, &Spielfeld::hitplayer2);
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
    connect(Network,&network::GameStart, NewGame, &Game::setTurnOfBothPlayers);
    connect(Network,&network::ShotAnswer , NewGame, &Game::processingSCOpponent);
    connect(NewGame, &Game::attackP2Coordinate,Network, &network::send);
    connect(NewGame, &Game::ourSCtoNetwork,Network, &network::send);
  

     connect(Network, &network::Shot, NewGame, &Game::attackOnPlayer1);

     connect(startfenster->spielfeld, &Spielfeld::StartSpielfeldPressed, Network, &network::StartButtonPressed);
}


