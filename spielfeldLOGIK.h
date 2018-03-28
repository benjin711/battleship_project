/*
 * Deklaration Klasse SpielfeldLOGIK
 */

#ifndef SPIELFELDLOGIK_H
#define SPIELFELDLOGIK_H

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <QObject>

#include "schiff.h"


/**
 * @brief SpielfeldLOGIK Klasse. Wichtigste Attribute: Das Spielfeld mit Strings und ein Vektor mit allen Schiffinstanzen.
 */

class SpielfeldLOGIK : public QObject{

    Q_OBJECT

private:
	/**
     * @brief  10x10 Spielfeld mit Strings als Element. Standard: "Wasser".
	 */
    std::vector<std::vector<std::string> > _spielfeldLOGIK;

    /**
     * @brief  Array der 10 Schiffinstanzen.
     */
    std::vector<Schiff> _schiffeArray;

    /**
     * @brief  Status Variable. Anzahl der gesetzten Schiffe.
     */
    int _anzSchiffeGesetzt;

    /**
     * @brief  Status Variable. Anzahl der gesunkenen Schiffe.
     */
    int _anzSchiffeGesunken;

    /**
     * @brief  Speichert die Länge des aktuell zu setzenden Schiffes.
     */
    int _aktLaengeSchiff;

    /**
     * @brief  Vektor mit der aktuellen Anfangs- und Endposition des Schiffes.
     */
    std::vector<std::pair<int,int> >_aktK1K2;




public:

    /**
     * @brief  Konstruktor. Initialisiert die Spielfelder mit "Wasser" und erstellt die 10 Standardschiffinstanzen.
     */
    explicit SpielfeldLOGIK(QObject *parent = nullptr);

    /**
     * @brief       Checkt, dass die Koordinaten von k1 bis k2 exklusive k1 unbesetzt sind.
     * @param[k1]   1.Koordinate
     * @param[k2]   2.Koordinate
     * @return      Bool. 0 -> Felder nicht besetzt. 1 -> Felder besetzt.
     */
    bool felderZwiBesetzt(std::pair<int,int> k1, std::pair<int,int> k2);

    /**
     * @brief       Getter. Gibt den String in den Spielfeldern zurück.
     * @param[k]    Koordinate.
     * @return      Der zur Koordinate k korrespondierende String.
     */
    std::string& getSpielfeldLOGIK(std::pair<int,int> k);

    /**
     * @brief           Gibt ein Schiff der Länge laenge zurück, welches noch nicht platziert wurde.
     * @param[laenge]   Länge des Schiffes welches platziert werden soll.
     * @return          (see above)
     */
    Schiff& getSchiffImArray(int laenge);

    /**
     * @brief           Getter. Attribut _schiffeArray.
     */
    std::vector<Schiff>& getSchiffeArray();

    /**
     * @brief           Getter. Attribut _anzSchiffeGesetzt.
     */
    int& getAnzSchiffeGesetzt();

    /**
     * @brief           Setter. Attribut _anzSchiffeGesetzt.
     */
    void setAnzSchiffeGesetzt();

    /**
     * @brief           Getter. Attribut _anzSchiffeGesunken
     */
    int& getAnzSchiffeGesunken();

    /**
     * @brief           Setter. Attribut _anzSchiffeGesunken. Zustandsvariable wird automatisch gesetzt.
     */
    void setAnzSchiffeGesunken();

    /**
     * @brief                Gibt zurück, ob ein Schiff gesunken ist.
     * @param[nameSchiff]    Name des zu überprüfenden Schiffes.
     */
    bool istSchiffGesunken(std::string nameSchiff);

    /**
     * @brief   Getter. Attribut _aktLaengeSchiff.
     */
    int& getAktLaengeSchiff();

    /**
     * @brief       Getter. Attribut _getAktK1K2.
     */
    std::vector<std::pair<int, int> > &getAktK1K2();

    /**
     * @brief       Setter _aktK1K2.
     */
    void setAktK1K2(std::vector<std::pair<int,int> > NK1K2);

    /**
     * @brief       Setzt zufällig Schiffe auf das Spielfeld von Spieler 1.
     */
    void zufaelligSchiffeSetzen();

public slots:

    /**
     * @brief       Setter. Attribut _aktLaengeSchiff. Slot für GUI Connect.
     */
    void setAktLaengeSchiff(int NAktLaengeSchiff);

    /**
     * @brief   Gibt mögliche 2.Koordinaten in einem Vector mit Pairs oder die Koordinaten eines gesetzen Schiffes an GUI.
     * @param   1.Koordinate (erhalten von GUI)
     * @param   Länge des einzusetzenden Schiffes (von GUI)
     */
    void moeglicheK2(std::pair<int,int> k);

    /**
     * @brief Setzt Schiff aufs Spielfeld ("Wasser" -> "Schiffname") und im Schiffe Array.
     * @param[k1]: Anfangskoordinate
     * @param[k2]: Endkoordinate
     */
    void setSchiff(std::pair<int,int> k1, std::pair<int,int> k2);


signals:
    /**
     * @brief sigMoeglicheK2    Gibt die möglichen 2.Koordinaten an GUI.
     * @param [tmpVector]       Vektor mit möglichen 2.Koordinaten.
     * @param [k1]              Von unserem Spieler ausgewähltes Feld.
     */
    void sigMoeglicheK2(std::vector<std::pair<int,int> > tmpVector, std::pair<int,int> k1, int bla);

    /**
     * @brief koordSchiff       Gibt die Koordinaten des zu setzenden Schiffes an GUI.
     * @param tmpVector         Enthält die Koordinaten des zu setzenden Schiffes.
     */
    void koordSchiff(std::vector<std::pair<int,int> > tmpVector);

    /**
     * @brief sigAlleSchiffeGesetzt     Signal an die GUI, ob alle Schiffe gesetzt wurden sind oder nicht.
     * @param Buul                      1-> alle Schiffe gesetzt.
     */
    void sigAlleSchiffeGesetzt(bool Buul);

    /**
     * @brief koordinatenAllerSchiffe   Sendet einen Vektor mit allen Schiffkoordinaten.
     */
    void koordinatenAllerSchiffe(std::vector<std::pair<int,int> > blub);

};





#endif /* SPIELFELDLOGIK_H */
