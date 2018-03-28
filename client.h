#ifndef CLIENT_H
#define CLIENT_H

#include <QDebug>
#include <QTcpSocket>
#include <QDataStream>
#include <QDataStream>
#include "network.h"


class client : public network
{
    Q_OBJECT
public:
    explicit client(QObject *parent = 0);

signals:

public slots:

    /**
     * @brief client::connectToServer : Erstellt Client und baut Verbindung zum Server auf.
     * @param host: Hostname
     * @param port: Port
     */
    void disconnectFromServer();


    /**
     * @brief client::disconnectFromServer : Baut Verbindung zum Server ab.
     */
    void connectToServer(QString, quint16);

private slots:

    /**
     * @brief client::connectionInitialized : Erfolgreicher Verbindungsaufbau wird bestätigt.
     */
    void connectionInitialized();




private:    
       ///Prüfbedingung ob Client oder Server Mode
    bool isClient;
};

#endif // CLIENT_H
