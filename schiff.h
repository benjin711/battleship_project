/*
 * Deklaration Klasse Schiff
 */

#ifndef SCHIFF_H
#define SCHIFF_H


#include <iostream>
#include <vector>
#include <utility>

/**
 * @brief   Klasse Schiff.
 */

class Schiff {

private:
	/**
     * @brief   Name des Schiffes (bspw. Zerstoerer 1)
	 */
    std::string _name;

    /**
     * @brief   Lebenspunkte. Werden bei Treffer dekrementiert.
     */
    int _leben;

    /**
     * @brief   Status Attribut. 1->gesunken. 0->Noch nicht gesunken.
     */
    bool _gesunken;

    /**
     * @brief   Status Attribut. 1->Schiff gesetzt. 0->Schiff noch nicht gesetzt.
     */
    bool _gesetzt;

    /**
     * @brief   Konstantes Attribut.
     */
    int _laenge;

    /**
     * @brief   Vektor der Koordinaten des Schiffes.
     */
    std::vector<std::pair<int,int> > _koordinaten;

public:

    /**
     * @brief           Konstruktor von Klasse Schiff. Initialisiert mit Name, Leben und Länge.
     * @param[Nname]    Name.
     * @param[Nleben]   Lebenspunkte.
     * @param[Nlaenge]  Länge.
     */
    Schiff(std::string Nname, int Nleben, int Nlaenge);

    /**
     * @brief           Getter. Attribut _leben.
     */
    int& getLeben();

    /**
     * @brief           Setter. Attribut _leben.
     */
    void setLeben(int Nleben);

    /**
     * @brief           Getter. Attribut _name.
     */
    std::string& getName();

    /**
     * @brief:          Setter. Attribut _name.
     */
    void setName(std::string Nname);

    /**
    * @brief            Getter. Attribut _gesunken.
    */
    bool& getGesunken();

    /**
     * @brief           Setter. Attribut _gesunken.
     */
    void setGesunken(bool Ngesunken);

    /**
     * @brief           Getter. Attribut _gesetzt.
     */
    bool& getGesetzt();

    /**
     * @brief           Setter. Attribut _gesetzt.
     */
    void setGesetzt(bool Ngesetzt);

    /**
     * @brief           Getter. Attribut _laenge.
     */
    int getLaenge();

    /**
     * @brief           Getter. Attribut _koordinaten.
     */
    std::vector<std::pair<int,int> >& getKoordinaten();

    /**
     * @brief:          Setter. Attribut _koordinaten.
     */
    void setKoordinaten(std::vector<std::pair<int,int> > Nkoordinaten);
};



#endif /* SCHIFF_H */

