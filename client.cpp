#include "client.h"
#include <QtNetwork>
#include <QDebug>

client::client(QObject *parent) : network(parent)
{
    isClient = false;
}


void client::connectToServer(QString host, quint16 port)
{


       if (port>=1024 && port<=65000)
      {
        socket = new QTcpSocket(this);
        isClient=true;
        connect(socket,&QTcpSocket::connected,this,&client::connectionInitialized);
        socket->connectToHost(host,port);



//        if(socket->state()!=QAbstractSocket::ConnectedState)
//        {

//           emit NetworkToGui("Verbindungsaufbau fehlgeschlagen(Socketfehler)");
//        }


       }
    else
    {

      emit NetworkToGui("Fehler: Servername oder Portnummer ungueltig");
       }
}


void client::connectionInitialized()
{

     stream.setDevice(socket);
     connect(socket,&QTcpSocket::readyRead, this,&network::receiveData);
     emit NetworkToGui("Verbindung zum Server hergestellt");
     qDebug() << "in connection initialized";
}



void client::disconnectFromServer()
{

    if(isClient==true)
    {

    emit NetworkToGui("Verbindung beendet");
    socket->disconnectFromHost();
   isClient= false;
}
}


