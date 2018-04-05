/********************************************************************************
** Form generated from reading UI file 'spielfeld.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPIELFELD_H
#define UI_SPIELFELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Spielfeld
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_1;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *Start;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pbSchlachtschiff;
    QPushButton *pbKreuzer;
    QPushButton *pbZerstoerer;
    QPushButton *pbUboot;
    QPushButton *ZufallsButton;
    QPushButton *pbDisconnect;
    QLabel *picture;
    QLabel *labelwin;
    QLabel *lblose;

    void setupUi(QWidget *Spielfeld)
    {
        if (Spielfeld->objectName().isEmpty())
            Spielfeld->setObjectName(QStringLiteral("Spielfeld"));
        Spielfeld->resize(807, 593);
        gridLayoutWidget = new QWidget(Spielfeld);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 371, 331));
        gridLayout_1 = new QGridLayout(gridLayoutWidget);
        gridLayout_1->setSpacing(6);
        gridLayout_1->setContentsMargins(11, 11, 11, 11);
        gridLayout_1->setObjectName(QStringLiteral("gridLayout_1"));
        gridLayout_1->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(Spielfeld);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(410, 10, 371, 331));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        Start = new QPushButton(Spielfeld);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setGeometry(QRect(670, 360, 88, 34));
        verticalLayoutWidget = new QWidget(Spielfeld);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 360, 251, 220));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pbSchlachtschiff = new QPushButton(verticalLayoutWidget);
        pbSchlachtschiff->setObjectName(QStringLiteral("pbSchlachtschiff"));

        verticalLayout->addWidget(pbSchlachtschiff);

        pbKreuzer = new QPushButton(verticalLayoutWidget);
        pbKreuzer->setObjectName(QStringLiteral("pbKreuzer"));

        verticalLayout->addWidget(pbKreuzer);

        pbZerstoerer = new QPushButton(verticalLayoutWidget);
        pbZerstoerer->setObjectName(QStringLiteral("pbZerstoerer"));

        verticalLayout->addWidget(pbZerstoerer);

        pbUboot = new QPushButton(verticalLayoutWidget);
        pbUboot->setObjectName(QStringLiteral("pbUboot"));

        verticalLayout->addWidget(pbUboot);

        ZufallsButton = new QPushButton(verticalLayoutWidget);
        ZufallsButton->setObjectName(QStringLiteral("ZufallsButton"));

        verticalLayout->addWidget(ZufallsButton);

        pbDisconnect = new QPushButton(Spielfeld);
        pbDisconnect->setObjectName(QStringLiteral("pbDisconnect"));
        pbDisconnect->setGeometry(QRect(670, 500, 84, 34));
        pbDisconnect->setAutoDefault(true);
        picture = new QLabel(Spielfeld);
        picture->setObjectName(QStringLiteral("picture"));
        picture->setGeometry(QRect(8, 7, 791, 581));
        labelwin = new QLabel(Spielfeld);
        labelwin->setObjectName(QStringLiteral("labelwin"));
        labelwin->setGeometry(QRect(250, 80, 281, 171));
        lblose = new QLabel(Spielfeld);
        lblose->setObjectName(QStringLiteral("lblose"));
        lblose->setGeometry(QRect(270, 90, 261, 151));
        picture->raise();
        gridLayoutWidget->raise();
        gridLayoutWidget_2->raise();
        Start->raise();
        verticalLayoutWidget->raise();
        pbDisconnect->raise();
        labelwin->raise();
        lblose->raise();

        retranslateUi(Spielfeld);

        pbDisconnect->setDefault(true);


        QMetaObject::connectSlotsByName(Spielfeld);
    } // setupUi

    void retranslateUi(QWidget *Spielfeld)
    {
        Spielfeld->setWindowTitle(QApplication::translate("Spielfeld", "Spielfeld", 0));
        Start->setText(QApplication::translate("Spielfeld", "Start", 0));
        pbSchlachtschiff->setText(QApplication::translate("Spielfeld", "Schlachtschiff", 0));
        pbKreuzer->setText(QApplication::translate("Spielfeld", "Kreuzer", 0));
        pbZerstoerer->setText(QApplication::translate("Spielfeld", "Zerst\303\266rer", 0));
        pbUboot->setText(QApplication::translate("Spielfeld", "U-Boot", 0));
        ZufallsButton->setText(QApplication::translate("Spielfeld", "Zuf\303\244llige Positionen", 0));
        pbDisconnect->setText(QApplication::translate("Spielfeld", "Trennen", 0));
        picture->setText(QApplication::translate("Spielfeld", "TextLabel", 0));
        labelwin->setText(QString());
        lblose->setText(QApplication::translate("Spielfeld", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Spielfeld: public Ui_Spielfeld {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPIELFELD_H
