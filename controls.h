#ifndef CONTROLS_H
#define CONTROLS_H

#include "button.h"
#include "ship.h"
#include "game.h"
#include "player.h"
#include "spielfeld.h"
#include "board.h"
#include "spielfeld.h"
#include "startfenster.h"
#include "client.h"
#include "network.h"
#include "server.h"
#include "startfenster.h"
#include <QObject>




/**
 * @brief Class Controls
 */
class Controls : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor of Controls
     */
    Controls();    
    ~Controls() = default;

private slots:
    /**
     * @brief onConnectToServer: creates client and connects to GUI and logic
     * @param host
     * @param port
     */
    void onConnectToServer(QString host, quint16 port);
    /**
     * @brief onNewConnection: creates server and connects to GUI and logic
     * @param port
     */
    void onNewConnection(quint16 port);

private:
    /**
     * @brief establishConnection: connects server/client with common functions
     */
    void establishConnection();

    /**
     * @brief startfenster: creates startfenster
     */
    Startfenster* startfenster;
    /**
     * @brief NewGame: creates new Game
     */
    Game* NewGame;
    /**
     * @brief Network: creates Network
     */
    network* Network = nullptr;
};

#endif // CONTROLS_H
