#ifndef SPIEL_H
#define SPIEL_H

#include "spieler.h"
#include <QObject>
#include <QtGlobal>

class Spiel: public QObject{

    Q_OBJECT
private:
	/**
     * @brief  Spieler1: Wir.
	 */
    Spieler _spieler1;


    /**
     * @brief Spieler2: Gegner.
     */
    Spieler _spieler2;

    /**
     * @brief Zwischenspeicher für Angriffskoordinate von Spieler1.
     */
    std::pair<int,int> _aktAngrKoord = {-1,-1};

public:
    /**
     * @brief Konstruktor. Zwei Spieler mit entsprechender ID werden initialisiert. Spieler1 ist per default am Zug.
     */
    Spiel(QObject *parent=nullptr);

    /**
     * @brief  Gibt Referenz auf _spieler1 zurück.
     */
    Spieler& getSpieler1();

    /**
     * @brief  Gibt Referenz auf _spieler2 zurück.
     */
    Spieler& getSpieler2();

    /**
     * @brief Getter. Attribut _aktAngrKoord.
     */
    std::pair<quint8,quint8> getAktAngrKoord(){return _aktAngrKoord;}


public slots:

    /**
     * @brief       Checkt, ob unser Angriff gerade gültig ist und gibt die Koordinate an das Netzwerk weiter.
     * @param[k]    Angriffskoordinate.
     * @return      1-> geglueckter Angriff. 0 -> Angriff fehlgeschlagen.
     */
    bool angriffAufSpieler2(std::pair<quint8, quint8> k);

    /**
     * @brief Empfängt von NW. 1-> Spieler1 (Wir) sind dran. 0-> Spieler2 ist dran.
     */
    void setAmZugBeideSpieler(bool tmpBool);

    /**
     * @brief Empfängt vom NW die Koordinate die bei uns angegriffen werden soll. Überprüfung von _amZug etc.
     */
    void angriffAufSpieler1(std::pair<quint8,quint8> k);

    /**
     * @brief Gibt den Status Code und den Vector vom Netzwerk (vom Gegner) einfach an GUI weiter.
     */
    void verarbeiteSCGegner(quint8 statusCode, std::vector<std::pair<quint8, quint8> > tmpVector ={{-1,-1}});


signals:

    /**
     * @brief koordWeitergabeAnNW   Gibt die Koordinate zum Angriff auf Spieler2 weiter an das Netzwerk.
     */
    void koordWeitergabeAnNW(quint8, quint8, std::vector<quint8>);

    /**
     * @brief rueckgabeAnNW         Gibt unseren Statuscode nach Angriff auf uns dem Netzwerk zurück.
     */
    void rueckgabeAnNW(quint8,quint8,std::vector<quint8>);

    /**
     * @brief weitergabeAnGUI       Gibt an GUI weiter, ob der Gegner getroffen hat und die Koordinaten, falls ein Schiff von uns gesunken ist.
     */
    void weitergabeAnGUI(quint8,std::pair<quint8,quint8>);

    /**
     * @brief statusCodeVonGegner   Verarbeitet den StatusCode vom Gegner. Gibt GUI den StatusCode vom Gegner weiter.
     */
    void statusCodeVonGegner(quint8, std::vector<std::pair<quint8,quint8> >, std::pair<quint8,quint8>);

};

#endif // SPIEL_H
