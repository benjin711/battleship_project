/********************************************************************************
** Form generated from reading UI file 'startfenster.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTFENSTER_H
#define UI_STARTFENSTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Startfenster
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QRadioButton *Client;
    QRadioButton *Server;
    QLabel *lbHost;
    QLineEdit *HostEingabe;
    QLabel *lbPort;
    QLineEdit *PortEingabe;
    QPushButton *VerbindenButton;
    QPushButton *TrennenButton;
    QLabel *lbNachrichten;
    QTextBrowser *Verbindungsnachrichten;
    QPushButton *StartSpielfeld;
    QLabel *textLabel;
    QLabel *backgroundlabel;

    void setupUi(QDialog *Startfenster)
    {
        if (Startfenster->objectName().isEmpty())
            Startfenster->setObjectName(QStringLiteral("Startfenster"));
        Startfenster->resize(642, 548);
        formLayoutWidget = new QWidget(Startfenster);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(100, 80, 481, 391));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        Client = new QRadioButton(formLayoutWidget);
        Client->setObjectName(QStringLiteral("Client"));
        Client->setInputMethodHints(Qt::ImhNone);
        Client->setChecked(true);

        formLayout->setWidget(1, QFormLayout::LabelRole, Client);

        Server = new QRadioButton(formLayoutWidget);
        Server->setObjectName(QStringLiteral("Server"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Server);

        lbHost = new QLabel(formLayoutWidget);
        lbHost->setObjectName(QStringLiteral("lbHost"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lbHost);

        HostEingabe = new QLineEdit(formLayoutWidget);
        HostEingabe->setObjectName(QStringLiteral("HostEingabe"));

        formLayout->setWidget(2, QFormLayout::FieldRole, HostEingabe);

        lbPort = new QLabel(formLayoutWidget);
        lbPort->setObjectName(QStringLiteral("lbPort"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lbPort);

        PortEingabe = new QLineEdit(formLayoutWidget);
        PortEingabe->setObjectName(QStringLiteral("PortEingabe"));

        formLayout->setWidget(3, QFormLayout::FieldRole, PortEingabe);

        VerbindenButton = new QPushButton(formLayoutWidget);
        VerbindenButton->setObjectName(QStringLiteral("VerbindenButton"));
        VerbindenButton->setAutoDefault(true);

        formLayout->setWidget(4, QFormLayout::LabelRole, VerbindenButton);

        TrennenButton = new QPushButton(formLayoutWidget);
        TrennenButton->setObjectName(QStringLiteral("TrennenButton"));
        TrennenButton->setAutoDefault(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, TrennenButton);

        lbNachrichten = new QLabel(formLayoutWidget);
        lbNachrichten->setObjectName(QStringLiteral("lbNachrichten"));

        formLayout->setWidget(5, QFormLayout::LabelRole, lbNachrichten);

        Verbindungsnachrichten = new QTextBrowser(formLayoutWidget);
        Verbindungsnachrichten->setObjectName(QStringLiteral("Verbindungsnachrichten"));

        formLayout->setWidget(5, QFormLayout::FieldRole, Verbindungsnachrichten);

        StartSpielfeld = new QPushButton(Startfenster);
        StartSpielfeld->setObjectName(QStringLiteral("StartSpielfeld"));
        StartSpielfeld->setGeometry(QRect(540, 500, 88, 34));
        textLabel = new QLabel(Startfenster);
        textLabel->setObjectName(QStringLiteral("textLabel"));
        textLabel->setGeometry(QRect(238, 40, 201, 21));
        backgroundlabel = new QLabel(Startfenster);
        backgroundlabel->setObjectName(QStringLiteral("backgroundlabel"));
        backgroundlabel->setGeometry(QRect(-2, -3, 651, 561));
        backgroundlabel->raise();
        formLayoutWidget->raise();
        StartSpielfeld->raise();
        textLabel->raise();

        retranslateUi(Startfenster);

        VerbindenButton->setDefault(false);
        TrennenButton->setDefault(true);


        QMetaObject::connectSlotsByName(Startfenster);
    } // setupUi

    void retranslateUi(QDialog *Startfenster)
    {
        Startfenster->setWindowTitle(QApplication::translate("Startfenster", "Dialog", 0));
#ifndef QT_NO_STATUSTIP
        Client->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        Client->setText(QApplication::translate("Startfenster", "C&lient", 0));
        Server->setText(QApplication::translate("Startfenster", "Ser&ver", 0));
        lbHost->setText(QApplication::translate("Startfenster", "Host", 0));
        lbPort->setText(QApplication::translate("Startfenster", "Port", 0));
        VerbindenButton->setText(QApplication::translate("Startfenster", "Verbinden", 0));
        TrennenButton->setText(QApplication::translate("Startfenster", "Trennen", 0));
        lbNachrichten->setText(QApplication::translate("Startfenster", "Nachrichten", 0));
        StartSpielfeld->setText(QApplication::translate("Startfenster", "Start", 0));
        textLabel->setText(QApplication::translate("Startfenster", "Schiffe versenken", 0));
        backgroundlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Startfenster: public Ui_Startfenster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTFENSTER_H
