/**
 * @file spielfeld.h
 * @brief Header von Spielfeld
 * @author V. Feierle
 * */


#ifndef SPIELFELD_H
#define SPIELFELD_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLayout>
#include <QPainter>
#include <QPaintEvent>
#include <memory>
#include <vector>
#include <utility>
#include <iostream>
#include <QColor>
#include <QPalette>

#include "button.h"


namespace Ui {
class Spielfeld;
}

/**
 * @brief Klasse Spielfeld
 */
class Spielfeld : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Spielfeld: Konstruktor von Spielfeld
     */
    Spielfeld(QObject *parent = 0);
    /**
     * @brief player1: 2D-Vektor Spieler1
     */
    std::vector<std::pair<int, int> > player1;
    /**
     * @brief player2: 2D-Vektor Spieler2
     */
    std::vector<std::pair<int, int> > player2;
    /**
     * @brief position1: Vektor mit Koordinaten der Buttons auf Spielfeld von Player1
     */
    std::vector<Button*> position1;
    /**
     * @brief position2: Vektor mit Koordinaten der Buttons auf Spielfeld von Player2
     */
    std::vector<Button*> position2;



private:
    Ui::Spielfeld *ui;
    /**
     * @brief akttmpVector: Vektor mit möglichen Endpositionen für ein zu setzendes Schiff
     */
    std::vector<std::pair<qint8, qint8> > akttmpVector;
    /**
     * @brief counterSchlachtschiff: Anzahl Klicks auf den QPushButton Schlachtschiff
     */
    int counterSchlachtschiff;
    /**
     * @brief counterKreuzer: Anzahl Klicks auf den QPushButton Kreuzer
     */
    int counterKreuzer;
    /**
     * @brief counterZerstoerer: Anzahl Klicks auf den QPushButton Zerstoerer
     */
    int counterZerstoerer;
    /**
     * @brief counterUboot: Anzahl Klicks auf den QPushButton Uboot
     */
    int counterUboot;


signals:
    /**
     * @brief buttonPressed1: schickt x-Koordinate und y-Koordinate, wenn ein Button in Spielfeld1 geklickt wird
     * @param int x-Koordinate
     * @param int y-Koordinate
     */
    void buttonPressed1(std::pair<int, int>);
    /**
     * @brief buttonPressed2: schickt x-Koordinate und y-Koordinate, wenn ein Button in Spielfeld2 geklickt wird
     */
    void buttonPressed2(std::pair<quint8, quint8>);
    /**
     * @brief emittet Länge von dem Schiff, das gesetzt wird
     */
    void length(int);
    /**
     * @brief disconnectButtonGame: emittet Signal, wenn im Spielfeld der Button Trennen geklickt wird
     */
    void disconnectButtonGame();
    /**
     * @brief StartSpielfeldPressed: emittet Signal, wenn im Spielfeld der Button Start geklickt wird
     */
    void StartSpielfeldPressed();
    /**
     * @brief ZufallsButtonclicked: emittet Signal, wenn im Spielfeld der Button Zufällige Positionen
     */
    void ZufallsButtonclicked();


public slots:
    /**
     * @brief start: disconnected alle Button auf Spielfeld 1
     */
    void start();
    /**
     * @brief setShip: setzt Schiffe
     * @param ship: x-Koordinaten und y-Koordinaten vom Schiff
     */
    void setShip( std::vector<std::pair<qint8, qint8>>ship);
    /**
     * @brief endposition: markiert mögliche Endpositionen für ein Schiff
     * @param tmpVector: Vektor mit möglichen Endpositionen
     * @param pos: x-Koordinate und y-Koordinate des als Anfangspunkt gedrückten Buttons
     * @param numbship: Länge des Schiffes
     */
    void endposition(std::vector<std::pair<qint8, qint8>>tmpVector, std::pair<qint8, qint8>pos, qint8 numbship);
    /**
     * @brief hitplayer1: signalisiert ob Treffer oder Fehlschlag bei Player1
     * @param statuscode1: Statuscode ob Treffer oder Fehlschlag
     * @param pos1: Koordinate wo Treffer oder Fehlschlag angezeigt werden soll
     */
    void hitplayer1(quint8 statuscode1, std::pair<quint8, quint8>pos1);
    /**
     * @brief hitplayer2: signalisiert ob Treffer oder Fehlschlag bei Player2
     * @param statuscode2: Statuscode ob Treffer oder Fehlschlag
     * @param sunkpos: Koordinaten eines gesunkenen Schiffes
     * @param pos2: Koordinaten des geklickten Buttons
     */
    void hitplayer2(quint8 statuscode2, std::vector<std::pair<quint8, quint8> >sunkpos, std::pair<quint8, quint8>pos2);
    /**
     * @brief startGame: enabled Button Start in Spielfeld, wenn alle Schiffe gesetzt wurden
     */
    void startGame(bool);
    /**
     * @brief randomPositions: setzt Schiffe auf zufällige Positionen
     * @param vector: enthält Koordinaten für alle Schiffe
     */
    void randomPositions(std::vector<std::pair<qint8, qint8> >vector);


private slots:
    /**
     * @brief on_pbSchlachtschiff_clicked: zählt Klicks auf Button Schlachtschiff
     */
    void on_pbSchlachtschiff_clicked();
    /**
     * @brief on_pbKreuzer_clicked: zählt Klicks auf Button Kreuzer
     */
    void on_pbKreuzer_clicked();
    /**
     * @brief on_pbZerstoerer_clicked: zählt Klicks auf Button Zerstoerer
     */
    void on_pbZerstoerer_clicked();
    /**
     * @brief on_pbUboot_clicked: zählt Klicks auf Button Uboot
     */
    void on_pbUboot_clicked();
    /**
     * @brief on_ZufallsButton_clicked: emittiert Signal wenn auf Zufällige Positionen geklickt wird
     */
    void on_ZufallsButton_clicked();
};



#endif // SPIELFELD_H


