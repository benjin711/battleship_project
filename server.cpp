#include "server.h"


server::server(QObject *parent) : network(parent)
{
       isServer = false;

    }

    void server::newConnection(quint16 port)
    {
        serverptr = new QTcpServer(this);
         connect(serverptr,&QTcpServer::newConnection, this , &server::OpenSocket);

        if(!serverptr->listen(QHostAddress::Any, port))
        {

          emit NetworkToGui("Server konnte nicht gestartet werden!");
            disconnect(serverptr,&QTcpServer::newConnection, this , &server::OpenSocket);
        }
         else
         {

              emit NetworkToGui("Server wurde gestartet!");





         }












}


    void server::Disconnection()
    {
        if(isServer==true)
        {
        qDebug() << " Verbindung beendet!";
        socket->disconnectFromHost();

        //serverptr->deleteLater();
        isServer=false;

}
    }

    void server::OpenSocket()
    {
        socket = serverptr->nextPendingConnection();
        isServer =true;
        stream.setDevice(socket);
        connect(socket, &QTcpSocket::readyRead, this, &network::receiveData);
        //connect(socketSERVER, &QTcpSocket::readyRead, [](){qDebug() << "Some server receive slot";});


        connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));

        emit NetworkToGui("Offener Socket am Server angenommen");
        qDebug() << socket->state();
        qDebug() << "socket ptr = " << socket;
        stream << quint8(0x01) << quint8(0x06) << quint8(0x0A) << quint8(0x0A) << quint8(0x01) << quint8(0x02) << quint8(0x03) << quint8(0x04); ///Senden der Standardspielfeldparameter.
    }
