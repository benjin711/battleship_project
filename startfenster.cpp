#include "startfenster.h"
#include "ui_startfenster.h"
#include <QLabel>
#include <QFont>
#include <QLayout>

Startfenster::Startfenster(QObject *parent) :
    QDialog(dynamic_cast<QWidget*>(parent)),
    ui(new Ui::Startfenster)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    spielfeld = new Spielfeld();

    ui->StartSpielfeld->setDisabled(true);

    connect(ui->TrennenButton, &QPushButton::clicked, [=](){
                                                           emit disconnectButton();
                                                        });

    // Schriftart und Schriftgröße einstellen
    QFont label( "Arial", 14, QFont::Bold);
    ui->textLabel->setFont( label);

    QPixmap background(":/back.jpg");
    background = background.scaled(QSize( ui->backgroundlabel->size()));
    ui->backgroundlabel->setPixmap(background);

    connect(ui->VerbindenButton, &QPushButton::clicked, this, &Startfenster::state);
    connect(ui->Server, &QRadioButton::clicked, this, &Startfenster::disableHost);
    connect(ui->Client, &QRadioButton::clicked, this, &Startfenster::enableHost);

}


Startfenster::~Startfenster()
{
    delete ui;
}



void Startfenster::disableHost()
{
    ui->HostEingabe->setDisabled(true);
}

void Startfenster::enableHost()
{
    ui->HostEingabe->setDisabled(false);
}

void Startfenster::state()
{
    if(ui->Client->isChecked())
    {
        port = ui->PortEingabe->text().toUShort();
        host = ui->HostEingabe->text();
        emit ClientMode(host, port);
        ui->StartSpielfeld->setDisabled(false);
    }

    if(ui->Server->isChecked())
    {
        port = ui->PortEingabe->text().toUShort();
        emit ServerMode(port);
        ui->StartSpielfeld->setDisabled(false);
    }
}



void Startfenster::readFromNetwork(QString message)
{
    ui->Verbindungsnachrichten->append(message);
}



void Startfenster::on_StartSpielfeld_clicked()
{
    spielfeld->show();
    this->close();
}
