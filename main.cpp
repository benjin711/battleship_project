#include "spielfeld.h"
#include "startfenster.h"
#include "client.h"
#include "server.h"
#include <QApplication>
#include "controls.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controls controller;
    //Startfenster startfenster;
//    client Client;
//    server Server;
//    Spielfeld spielfeld;

    //Startfenster w;
    //startfenster.show();

    return a.exec();
}


