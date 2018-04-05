#include "network.h"

network::network(QObject *parent) : QObject(parent){
    stream.setByteOrder(QDataStream::BigEndian);
    EnemyReady=false;
    qDebug() << "Constructed network at " << this;
}

void network::startToWaitForAnswer()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(sendTimeoutToEnemy()));

    timer->start(30000);
}

network::~network() {
    delete timer;
    delete socket;

    qDebug() << "Network deconstructed";
}

void network::sendTimeoutToEnemy()
{
   stream <<quint8(0x10) <<quint8(0x01)<<quint8(0x04);
   emit NoAnswer();
}



void network::receiveData()
{
    quint8 cmd,length,dummy;
    std::vector<quint8> data;


    qDebug() << "in receive";    


        stream >> cmd;
        qDebug()<<"CMD erhalten"<<cmd;
        stream >> length;
        qDebug()<<"Länge erhalten"<<length;





        for(int i=0;i<length;i++)
        {
            stream >> dummy;
            qDebug() << dummy;
            data.push_back(dummy);

        }


            switch(cmd)
            {
            case 0x01: if(length==6)
                       {
                         if(data[0]==10 && data[1]==10 && data[2]==1 && data[3]==2 && data[4]==3 && data[5]==4)
                         {

                             stream<<quint8(0x10) <<quint8(0x01) <<quint8(0x00); ///Spielfeldparameter in Ordnung
                         }
                        else
                         {
                             stream<< quint8(0x10) <<quint8(0x01) <<quint8(0x02); ///Spielfeldparameter nicht in Ordnung
                         }
                        }

                       break;

            case 0x02: if(length==0)
                       {

                        EnemyReady = true;

                       }
                       break;

            case 0x03: if(length==2)
                       {
                        std::pair<quint8,quint8> shot;
                        shot.first = data[0];
                        shot.second =data[1];
                        qDebug() << "Received shot: " << shot.first << ", " << shot.second;
                        emit Shot(shot);
                       }
                       break;

            case 0x10: timer->stop();
                       if(length==1)
                        {
                         emit GameState(data);

                       }
                       else
                       {
                        stream <<quint8(0x10) <<quint8(0x01)<<quint8(0x03); ///Nachricht unvollständig
                       }
                       break;

            case 0x11: if(length<12)
                       {
                        quint8 statuscode;

                        std::vector<std::pair<quint8,quint8>> koordinatenvector;

                        statuscode = data[0];
                        for(int i=1;i<length;i++)
                        {

                          koordinatenvector.push_back(std::make_pair(data[i],data[i+1]));

                          i++;

                        };


                        emit ShotAnswer(statuscode,koordinatenvector);



                }
                       break;


            default:

                qDebug() << "Wrong cmd" << QString::number(cmd);


                break;
            }





    }



void network::StartButtonPressed()
{

    qDebug() << "socket ptr = " << socket;
    if(EnemyReady == false)
    {
        emit GameStart(true);
        stream<<quint8(0x02)<<quint8(0x00); ///Anforderung Spielbeginn
    }


   if(EnemyReady == true)
    {
    emit GameStart(false);
       stream<<quint8(0x10)<<quint8(0x01)<<quint8(0x00); /// Bereit Spiel kann gestartet werden
     }

}




void network::onSocketError(QAbstractSocket::SocketError err) {
    qDebug() << "Socket error: " << err;
}

void network::send(quint8 cmd,quint8 length, std::vector<quint8> data)
{
    stream << cmd << length;
      qDebug()<<"CMD gesendet "<< cmd;
      qDebug()<<"Länge gesendet "<< length;

    for(quint8 x : data)
       { stream << x;
    qDebug() << "Daten gesendet" << x;
}
}
