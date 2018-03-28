#ifndef SPIELER_H
#define SPIELER_H

#include <iostream>


#include "spielfeldLOGIK.h"


/**
 * @brief Klasse Spieler. Wichtigstes Attribut: Sein Spielfeld, seine Leben und Statusvariable, ob er am Zug ist.
 */

class Spieler{

private:
	/**
     * @brief  Spielfeld(LOGIK) vom Spieler.
	 */
    SpielfeldLOGIK * _meinSpielfeldLOGIK = new SpielfeldLOGIK();

    /**
     * @brief  ID vom Spieler.
     */
    int _id;

    /**
     * @brief  Bool. 1-> Spieler ist am Zug. 0-> Spieler ist nicht am Zug.
     */
    bool _amZug;

    /**
     * @brief  Insgesamt hat ein Spieler 30 Leben.
     */
    int _leben;


public:

    /**
     * @brief  Getter. Attribut _leben.
     */
    int& getLeben();

    /**
     * @brief  Setter. Attribut _leben.
     */
    void setLeben(int Nleben);

    /**
     * @brief           Konstruktor von Spielerobjekten.
     * @param[Nid]      ID von Spieler (Info von GUI)
     */
    Spieler(int Nid);

    /**
     * @brief       Getter. Attribut _id.
     */
    int& getId();

    /**
     * @brief       Setter. Attribut _id.
     */
    void setId(int Nid);

    /**
     * @brief       Getter. Attribut _amZug.
     */
    bool& getAmZug();

    /**
     * @brief       Setter. Attribut _amZug.
     */
    void setAmZug(bool NAmZug);

    /**
     * @brief       Getter. Attribut _meinSpielfeldLOGIK.
     */
    SpielfeldLOGIK& getMeinSpielfeldLOGIK();

    /**
     * @brief       () überladen. Gibt String von _meinSpielfeldLOGIK an der Stelle k wieder.
     * @param[k]    Koordinate k.
     * @return      (siehe brief)
     */
    std::string& operator()(std::pair<int,int> k);
};

#endif // SPIELER_H
