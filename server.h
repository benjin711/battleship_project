#ifndef SERVER_H
#define SERVER_H


#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include "network.h"

class server : public network
{
    Q_OBJECT
public:
    explicit server(QObject *parent = 0);

signals:

public slots:

    /**
    * @brief server::newConnection : Erstellt Server und hört auf übergeben Port.
    * @param port
    */
    void newConnection(quint16 port);

    /**
     * @brief server::Disconnection : Baut Verbindung zum Client ab.
     */
    void Disconnection();

    /**
     * @brief OpenSocket: Server hört auf nächste Verbindung und bestätigt erfolgreiche Verbindung.
     */
    void OpenSocket();

protected slots:
    //void receiveData();
    //void connectionState();

private:
    QTcpServer *serverptr;
    bool isServer;
};

#endif // SERVER_H
