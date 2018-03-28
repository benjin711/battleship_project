#ifndef CONTROLS_H
#define CONTROLS_H

#include "button.h"
#include "schiff.h"
#include "spiel.h"
#include "spieler.h"
#include "spielfeld.h"
#include "spielfeldLOGIK.h"
#include "spielfeld.h"
#include "startfenster.h"
#include "client.h"
#include "network.h"
#include "server.h"
#include "startfenster.h"
#include <QObject>




/**
 * @brief Klasse Controls
 */
class Controls : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor von Controls
     */
    Controls();    
    ~Controls() = default;

private slots:
    /**
     * @brief onConnectToServer: erstellt Client und verbindet zu Gui und Logik
     * @param host
     * @param port
     */
    void onConnectToServer(QString host, quint16 port);
    /**
     * @brief onNewConnection: erstellt Server und verbindet zu Gui und Logik
     * @param port
     */
    void onNewConnection(quint16 port);

private:
    /**
     * @brief establishConnection: verbindet Server/Client mit gemeinsamen Funktionen
     */
    void establishConnection();

    /**
     * @brief startfenster: erzeugt startfenster
     */
    Startfenster* startfenster;
    /**
     * @brief NeuesSpiel: erzeugt NeuesSpiel
     */
    Spiel* NeuesSpiel;
    /**
     * @brief Network: erzeugt Network
     */
    network* Network = nullptr;
};

#endif // CONTROLS_H
