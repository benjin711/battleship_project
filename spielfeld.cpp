#include "spielfeld.h"
#include "ui_spielfeld.h"
#include "button.h"

#include <QDebug>
#include <QTime>
#include <QPixmap>
#include <QIcon>
#include <QRect>
#include <QDesktopWidget>

    Spielfeld::Spielfeld(QObject *parent) :
        QWidget(dynamic_cast<QWidget*>(parent)),
    ui(new Ui::Spielfeld)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    QPixmap pixwin(":/win.jpg");
    pixwin = pixwin.scaled(QSize (ui->labelwin->size()));
    ui->labelwin->setPixmap(pixwin);
    ui->labelwin->hide();

    QPixmap pixlose(":/lose.jpeg");
    pixwin = pixlose.scaled(QSize (ui->lblose->size()));
    ui->lblose->setPixmap(pixlose);
    ui->lblose->hide();

    ui->Start->setDisabled(true);
    connect(ui->Start, &QPushButton::clicked, [=](){emit StartSpielfeldPressed();});

    counterSchlachtschiff = 0;
    counterKreuzer = 0;
    counterZerstoerer = 0;
    counterUboot = 0;

    //Bild einfügen
    QPixmap pix(":/battleship.jpg");
    pix = pix.scaled(QSize( ui->picture->size()));
    ui->picture->setPixmap(pix);

    connect(ui->Start, &QPushButton::clicked, this, &Spielfeld::start);


    //Eigenes Spielfeld erstellen

    for(int x=0; x<10; x++)
    {
        for (int y=0; y<10; y++)
        {

            Button *button = new Button(x, y);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

            position1.push_back(button);
            ui->gridLayout_1->addWidget(button, x, y);
            ui->gridLayout_1->setSpacing(0);

            button->setStyleSheet("background-color: rgb(0, 0, 160)");
            //button->setFixedSize(button->size());

            connect(button, &QPushButton::clicked, [=](){emit buttonPressed1({x, y});});
            button->setDisabled(true);

            player1.emplace_back(x, y);

        }
    }


    //Spielfeld für Gegner erstellen
    for(int x=0; x<10; x++)
    {
        for (int y=0; y<10; y++)
        {


            Button *button = new Button(x, y);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            position2.push_back(button);

            ui->gridLayout_2->addWidget(button, x, y);
            ui->gridLayout_2->setSpacing(0);

            button->setStyleSheet("background-color: rgb(0, 0, 160)");
            //button->setFixedSize(button->size());

            connect(button, &QPushButton::clicked,[=](){emit buttonPressed2({x, y});});
            button->setDisabled(true);

            player2.emplace_back(x, y);
        }

    }

    connect(ui->pbDisconnect, &QPushButton::clicked, [=](){
                                                           emit disconnectButtonGame();
                                                        });


    connect(ui->pbSchlachtschiff, &QPushButton::clicked, [=](){emit length(5);});
    connect(ui->pbKreuzer, &QPushButton::clicked, [=](){emit length(4);});
    connect(ui->pbZerstoerer, &QPushButton::clicked, [=](){emit length(3);});
    connect(ui->pbUboot, &QPushButton::clicked, [=](){emit length(2);});

}



void Spielfeld::startGame(bool number)
{
    if(number==1)
    {
        ui->Start->setEnabled(true);
    }
}


void Spielfeld::on_pbSchlachtschiff_clicked()
{
    counterSchlachtschiff++;
    ui->pbSchlachtschiff->setDisabled(true);
    ui->pbKreuzer->setDisabled(true);
    ui->pbZerstoerer->setDisabled(true);
    ui->pbUboot->setDisabled(true);
    ui->ZufallsButton->setDisabled(true);
    for(int x=0; x<10; x++)
    {
        for(int y=0; y<10; y++)
        {
            ui->gridLayout_1->itemAtPosition(x, y)->widget()->setDisabled(false);
        }
    }

}

void Spielfeld::on_pbKreuzer_clicked()
{
    counterKreuzer++;
    ui->pbSchlachtschiff->setDisabled(true);
    ui->pbKreuzer->setDisabled(true);
    ui->pbZerstoerer->setDisabled(true);
    ui->pbUboot->setDisabled(true);
    ui->ZufallsButton->setDisabled(true);
    for(int x=0; x<10; x++)
    {
        for(int y=0; y<10; y++)
        {
            ui->gridLayout_1->itemAtPosition(x, y)->widget()->setDisabled(false);
        }
    }

}

void Spielfeld::on_pbZerstoerer_clicked()
{

    counterZerstoerer++;
    ui->pbSchlachtschiff->setDisabled(true);
    ui->pbZerstoerer->setDisabled(true);
    ui->pbKreuzer->setDisabled(true);
    ui->pbUboot->setDisabled(true);
    ui->ZufallsButton->setDisabled(true);

    for(int x=0; x<10; x++)
    {
        for(int y=0; y<10; y++)
        {
            ui->gridLayout_1->itemAtPosition(x, y)->widget()->setDisabled(false);
        }
    }

}

void Spielfeld::on_pbUboot_clicked()
{

    counterUboot++;
    ui->pbSchlachtschiff->setDisabled(true);
    ui->pbZerstoerer->setDisabled(true);
    ui->pbKreuzer->setDisabled(true);
    ui->pbUboot->setDisabled(true);
    ui->ZufallsButton->setDisabled(true);
    for(int x=0; x<10; x++)
    {
        for(int y=0; y<10; y++)
        {
            ui->gridLayout_1->itemAtPosition(x, y)->widget()->setDisabled(false);
        }
    }


}



void Spielfeld::start()
{
    ui->Start->setDisabled(true);

    for(int x=0; x<10; x++)
    {
        for(int y=0; y<10; y++)
        {
            //ui->gridLayout_1->itemAtPosition(x, y)->widget()->disconnect();
            ui->gridLayout_1->itemAtPosition(x, y)->widget()->setDisabled(true);
        }
    }

    for(int x=0; x<10; x++)
    {
        for(int y=0; y<10; y++)
        {
            ui->gridLayout_2->itemAtPosition(x, y)->widget()->setDisabled(false);
        }
    }

}



void Spielfeld::endposition(std::vector<std::pair<qint8, qint8> > tmpVector, std::pair<qint8, qint8> pos, qint8 numbship)
{
    qDebug() << "numbships" << numbship;
    akttmpVector = tmpVector;
    static qint8 numberships = 0;
    numberships++;

    quint8 x = pos.first;
    quint8 y = pos.second;
    auto button = ui->gridLayout_1->itemAtPosition(x, y)->widget();

    if(tmpVector.size()==1)
    {
        button->clearFocus();
        button->setDisabled(true);
        ui->pbSchlachtschiff->setEnabled(true);
        ui->pbKreuzer->setEnabled(true);
        ui->pbZerstoerer->setEnabled(true);
        ui->pbUboot->setEnabled(true);
        button->clearFocus();


        if(numbship == 1)
        {
            counterSchlachtschiff = counterSchlachtschiff-1;
        }

        if(numbship == 2)
        {
            counterKreuzer = counterKreuzer-1;
        }

        if(numbship == 3)
        {
            counterZerstoerer = counterZerstoerer-1;
        }

        if(numbship == 4)
        {
            counterUboot = counterUboot -1;

        }
        qDebug() << "schlachtschiff" << counterSchlachtschiff;
        qDebug() << "kreuzer" << counterKreuzer;

        ui->pbSchlachtschiff->setEnabled(true);
        ui->pbKreuzer->setEnabled(true);
        ui->pbZerstoerer->setEnabled(true);
        ui->pbUboot->setEnabled(true);

        if(counterSchlachtschiff == 1)
        {
            ui->pbSchlachtschiff->setDisabled(true);
        }

        if(counterKreuzer == 2)
        {
            ui->pbKreuzer->setDisabled(true);
        }

        if(counterZerstoerer == 3)
        {
            ui->pbZerstoerer->setDisabled(true);
        }

        if(counterUboot == 4)
        {
            ui->pbUboot->setDisabled(true);

        }

    }


    else if (tmpVector[0].first!=(-1) && tmpVector[0].second!=(-1))
    {
        button->clearFocus();

        if(numberships==1)
        {
        button->setStyleSheet("background-color: rgb(179, 255, 230)");
        }

        if(numberships==2)
        {
        button->setStyleSheet("background-color: rgb(230, 255, 230)");
        }

        if(numberships==3)
        {
        button->setStyleSheet("background-color: rgb(230, 255, 247)");
        }

        if(numberships==4)
        {
        button->setStyleSheet("background-color: rgb(0, 153, 153)");
        }

        if(numberships==5)
        {
        button->setStyleSheet("background-color: rgb(0, 179, 179)");
        }

        if(numberships==6)
        {
        button->setStyleSheet("background-color: rgb(0, 204, 204)");
        }

        if(numberships==7)
        {
        button->setStyleSheet("background-color: rgb(0, 230, 172)");
        }

        if(numberships==8)
        {
        button->setStyleSheet("background-color: rgb(0, 204, 153)");
        }

        if(numberships==9)
        {
        button->setStyleSheet("background-color: rgb(0, 179, 134)");
        }

        if(numberships==10)
        {
        button->setStyleSheet("background-color: rgb(0, 153, 115)");
        }

        button->disconnect();

        for(qint8 x=0; x<10; x++)
        {
            for(qint8 y=0; y<10; y++)
            {

                ui->gridLayout_1->itemAtPosition(x, y)->widget()->setDisabled(true);
            }
        }

        for(quint8 i=1; i<tmpVector.size(); i++)
        {

            quint8 x2 = tmpVector[i].first;
            quint8 y2 = tmpVector[i].second;
            auto b = ui->gridLayout_1->itemAtPosition(x2, y2)->widget();
            b->setStyleSheet("background-color: rgb(0, 0, 0)");
            b->setDisabled(false);

        }
    }
}


void Spielfeld::setShip(std::vector<std::pair<qint8, qint8> > ship)

{
    if(akttmpVector.size()==1)
    {
        int x = akttmpVector[1].first;
        int y = akttmpVector[1].second;
        auto button = ui->gridLayout_1->itemAtPosition(x, y)->widget();
        button->setDisabled(true);

        for(int x=0; x<10; x++)
        {
            for (int y=0; y<10; y++)
            {
                ui->gridLayout_1->itemAtPosition(x, y)->widget()->setDisabled(true);
            }
        }
    }

    else
    {
    static int numberships = 0;
    numberships++;

    for(uint i=1; i<akttmpVector.size(); i++)
    {
            int x1 = akttmpVector[i].first;
            int y1 = akttmpVector[i].second;
            ui->gridLayout_1->itemAtPosition(x1, y1)->widget()->setStyleSheet("background-color: rgb(0, 0, 160)");
    }


    for(quint8 i=0; i<ship.size(); i++)
    {

        qint8 x2 = ship[i].first;
        qint8 y2 = ship[i].second;
        auto btn = ui->gridLayout_1->itemAtPosition(x2, y2)->widget();

        if(numberships==1)
        {
            btn->setStyleSheet("background-color: rgb(179, 255, 230)");
        }

        if(numberships==2)
        {
        btn->setStyleSheet("background-color: rgb(230, 255, 215)");
        }

        if(numberships==3)
        {
        btn->setStyleSheet("background-color: rgb(230, 255, 230)");
        }

        if(numberships==4)
        {
        btn->setStyleSheet("background-color: rgb(0, 153, 153)");
        }

        if(numberships==5)
        {
        btn->setStyleSheet("background-color: rgb(0, 179, 179)");
        }

        if(numberships==6)
        {
        btn->setStyleSheet("background-color: rgb(0, 204, 204)");
        }

        if(numberships==7)
        {
        btn->setStyleSheet("background-color: rgb(0, 230, 172)");
        }

        if(numberships==8)
        {
        btn->setStyleSheet("background-color: rgb(0, 204, 153)");
        }

        if(numberships==9)
        {
        btn->setStyleSheet("background-color: rgb(0, 179, 134)");
        }

        if(numberships==10)
        {
        btn->setStyleSheet("background-color: rgb(0, 153, 115)");
        }

        btn->disconnect();
        for(int x=0; x<10; x++)
        {
            for(int y=0; y<10; y++)
            {
                ui->gridLayout_1->itemAtPosition(x, y)->widget()->setDisabled(true);
            }
        }

    }
    }

    ui->pbSchlachtschiff->setEnabled(true);
    ui->pbKreuzer->setEnabled(true);
    ui->pbZerstoerer->setEnabled(true);
    ui->pbUboot->setEnabled(true);

    qDebug() << "schlachtschiff" << counterSchlachtschiff;
    qDebug() << "kreuzer" << counterKreuzer;

    if(counterSchlachtschiff == 1)
    {
        ui->pbSchlachtschiff->setDisabled(true);
    }

    if(counterKreuzer == 2)
    {
        ui->pbKreuzer->setDisabled(true);
    }

    if(counterZerstoerer == 3)
    {
        ui->pbZerstoerer->setDisabled(true);
    }

    if(counterUboot == 4)
    {
        ui->pbUboot->setDisabled(true);

    }

}


void Spielfeld::hitplayer1(quint8 statuscode1, std::pair<quint8, quint8> pos1)
{
    quint8 x = pos1.first;
    quint8 y = pos1.second;

    auto button = ui->gridLayout_2->itemAtPosition(x, y)->widget();

    if(statuscode1==0)
    {

        button->clearFocus();
        QPixmap pix(":/water.jpg");
        QIcon IconButton(pix);
        position1[x*10+y]->setFixedSize(position1[x*10+y]->size());
        position1[x*10+y]->setIconSize(0.9*(position1[x*10+y]->size()));
        position1[x*10+y]->setIcon(IconButton);
    }

    if(statuscode1==1)
    {
        button->clearFocus();       
        QPixmap pix(":/feuer.jpeg");
        QIcon IconButton(pix);
        position1[x*10+y]->setFixedSize(position1[x*10+y]->size());
        position1[x*10+y]->setIconSize(0.9*(position1[x*10+y]->size()));
        position1[x*10+y]->setIcon(IconButton);
        //button->setStyleSheet("background-color: rgb(204, 0, 0)");

    }

    if(statuscode1==2)
    {
        button->clearFocus();
        QPixmap pix(":/feuer.jpeg");
        QIcon IconButton(pix);
        position1[x*10+y]->setFixedSize(position1[x*10+y]->size());
        position1[x*10+y]->setIconSize(0.9*(position1[x*10+y]->size()));
        position1[x*10+y]->setIcon(IconButton);
        //button->setStyleSheet("background-color: rgb(255, 0, 0)");
        //button->disconnect();
    }

    if(statuscode1==3)
    {
        button->clearFocus();
        QPixmap pix(":/feuer.jpeg");
        QIcon IconButton(pix);
        position1[x*10+y]->setFixedSize(position1[x*10+y]->size());
        position1[x*10+y]->setIconSize(0.9*(position1[x*10+y]->size()));
        position1[x*10+y]->setIcon(IconButton);

        ui->lblose->show();

        for(int x=0; x<10; x++)
        {
            for(int y=0; y<10; y++)
            {

                ui->gridLayout_1->itemAtPosition(x, y)->widget()->setDisabled(true);
            }
        }

        for(int x2=0; x2<10; x2++)
        {
            for(int y2=0; y2<10; y2++)
            {

                ui->gridLayout_2->itemAtPosition(x2, y2)->widget()->setDisabled(true);
            }
        }

    }
}





void Spielfeld::hitplayer2(quint8 statuscode2, std::vector<std::pair<quint8, quint8> >sunkpos, std::pair<quint8, quint8> pos2)
{
    qDebug() << statuscode2 << "hitplayer statuscode2";
    quint8 x = pos2.first;
    quint8 y = pos2.second;
    auto button = ui->gridLayout_2->itemAtPosition(x, y)->widget();

    if(statuscode2==3)
    {
        for(quint8 i=0; i<sunkpos.size(); i++)
        {
            quint8 x2 = sunkpos[i].first;
            quint8 y2 = sunkpos[i].second;
            auto b = ui->gridLayout_2->itemAtPosition(x2, y2)->widget();

            b->clearFocus();
            QPixmap pix(":/zerstört.jpeg");
            QIcon IconButton(pix);
            position2[x2*10+y2]->setFixedSize(position2[x2*10+y2]->size());
            position2[x2*10+y2]->setIconSize(0.9*(position2[x2*10+y2]->size()));
            position2[x2*10+y2]->setIcon(IconButton);
        }
        ui->labelwin->show();

        for(int x=0; x<10; x++)
        {
            for(int y=0; y<10; y++)
            {

                ui->gridLayout_1->itemAtPosition(x, y)->widget()->setDisabled(true);
            }
        }

        for(int x2=0; x2<10; x2++)
        {
            for(int y2=0; y2<10; y2++)
            {

                ui->gridLayout_2->itemAtPosition(x2, y2)->widget()->setDisabled(true);
            }
        }


    }

    if(statuscode2==2)
    {
        for(quint8 i=0; i<sunkpos.size(); i++)
        {
            quint8 x2 = sunkpos[i].first;
            quint8 y2 = sunkpos[i].second;
            qDebug() << "x2: " << x2 << "; y2: " << y2 << "\n";
            auto b = static_cast<Button*>(ui->gridLayout_2->itemAtPosition(x2, y2)->widget());

            b->clearFocus();
            QPixmap pix(":/zerstört.jpeg");
            QIcon IconButton(pix);
            b->setFixedSize(b->size());
            b->setIconSize(0.9*(b->size()));
            b->setIcon(IconButton);
            /*
            position2[x2*10+y2]->setFixedSize(position2[x2*10+y2]->size());
            position2[x2*10+y2]->setIconSize(0.9*(position2[x2*10+y2]->size()));
            position2[x2*10+y2]->setIcon(IconButton);
*/
            //b->setStyleSheet("background-color: rgb(0, 0, 150)");
            //b->setDisabled(false);
         }

     }

     if(statuscode2==0)
        {

            button->clearFocus();
            QPixmap pix(":/water.jpg");
            QIcon IconButton(pix);
            position2[x*10+y]->setFixedSize(position2[x*10+y]->size());
            position2[x*10+y]->setIconSize(0.9*(position2[x*10+y]->size()));
            position2[x*10+y]->setIcon(IconButton);
            //button->setStyleSheet("background-color: rgb(0, 0, 255)");
            //button->disconnect();

        }

     if(statuscode2==1)
        {

            button->clearFocus();
            QPixmap pix(":/feuer.jpeg");
            QIcon IconButton(pix);
            position2[x*10+y]->setFixedSize(position2[x*10+y]->size());
            position2[x*10+y]->setIconSize(0.9*(position2[x*10+y]->size()));
            position2[x*10+y]->setIcon(IconButton);
            //button->setStyleSheet("background-color: rgb(204, 0, 0)");
            //button->disconnect();
        }

}


void Spielfeld::on_ZufallsButton_clicked()
{
    ui->pbSchlachtschiff->setDisabled(true);
    ui->pbKreuzer->setDisabled(true);
    ui->pbZerstoerer->setDisabled(true);
    ui->pbUboot->setDisabled(true);
    emit ZufallsButtonclicked();
}


void Spielfeld::randomPositions(std::vector<std::pair<qint8, qint8> > vector)
{

    for(quint8 j=0; j<(vector.size()-25); j++)
    {
        qint8 x = vector[j].first;
        qint8 y = vector[j].second;
        auto btn = ui->gridLayout_1->itemAtPosition(x, y)->widget();
        btn->setStyleSheet("background-color: rgb(179, 255, 230)");
    }

    for(quint8 j=(vector.size()-25); j<(vector.size()-21); j++)
    {
        qint8 x = vector[j].first;
        qint8 y = vector[j].second;
        auto btn = ui->gridLayout_1->itemAtPosition(x, y)->widget();
        btn->setStyleSheet("background-color: rgb(230, 255, 215)");
    }

    for(quint8 j=9; j<13; j++)
    {
        qint8 x = vector[j].first;
        qint8 y = vector[j].second;
        auto btn = ui->gridLayout_1->itemAtPosition(x, y)->widget();
       btn->setStyleSheet("background-color: rgb(230, 255, 230)");
    }

    for(quint8 j=13; j<16; j++)
    {
        qint8 x = vector[j].first;
        qint8 y = vector[j].second;
        auto btn = ui->gridLayout_1->itemAtPosition(x, y)->widget();
        btn->setStyleSheet("background-color: rgb(0, 153, 153)");
    }

    for(quint8 j=16; j<19; j++)
    {
        qint8 x = vector[j].first;
        qint8 y = vector[j].second;
        auto btn = ui->gridLayout_1->itemAtPosition(x, y)->widget();
        btn->setStyleSheet("background-color: rgb(0, 179, 179)");
    }

    for(quint8 j=19; j<22; j++)
    {
        qint8 x = vector[j].first;
        qint8 y = vector[j].second;
        auto btn = ui->gridLayout_1->itemAtPosition(x, y)->widget();
        btn->setStyleSheet("background-color: rgb(0, 204, 204)");
    }

    for(quint8 j=22; j<24; j++)
    {
        qint8 x = vector[j].first;
        qint8 y = vector[j].second;
        auto btn = ui->gridLayout_1->itemAtPosition(x, y)->widget();
       btn->setStyleSheet("background-color: rgb(0, 230, 172)");
    }

    for(quint8 j=24; j<26; j++)
    {
        qint8 x = vector[j].first;
        qint8 y = vector[j].second;
        auto btn = ui->gridLayout_1->itemAtPosition(x, y)->widget();
        btn->setStyleSheet("background-color: rgb(0, 204, 153)");
    }

    for(quint8 j=26; j<28; j++)
    {
        qint8 x = vector[j].first;
        qint8 y = vector[j].second;
        auto btn = ui->gridLayout_1->itemAtPosition(x, y)->widget();
        btn->setStyleSheet("background-color: rgb(0, 179, 134)");
    }

    for(quint8 j=28; j<30; j++)
    {
        qint8 x = vector[j].first;
        qint8 y = vector[j].second;
        auto btn = ui->gridLayout_1->itemAtPosition(x, y)->widget();
        btn->setStyleSheet("background-color: rgb(0, 153, 115)");
    }

    ui->ZufallsButton->setDisabled(true);
}

