/*
 * Deklaration Klasse Schiff
 */

#ifndef SHIP_H
#define SHIP_H


#include <iostream>
#include <vector>
#include <utility>
#include <QtGlobal>

/**
 * @brief   Class Ship.
 */

class Ship {

private:
	/**
     * @brief   Name of the ship (bspw. Zerstoerer 1)
	 */
    std::string _name;

    /**
     * @brief   Ship's healthpoints. Decremented when hit.
     */
    qint8 _hp;

    /**
     * @brief   Status attribute. 1->sunk. 0->Not yet sunk.
     */
    bool _sunk;

    /**
     * @brief   Status attribute. 1->Ship placed. 0->Ship not yet placed.
     */
    bool _placed;

    /**
     * @brief   Constant attribute. Length of the ship.
     */
    qint8 _length;

    /**
     * @brief   Vector with the coordinates of the placed ship.
     */
    std::vector<std::pair<qint8,qint8> > _coordinates;

public:

    /**
     * @brief           Constructor of class ship.
     * @param[Nname]    New name.
     * @param[Nhp]      New hp.
     * @param[Nlength]  New length.
     */
    Ship(std::string Nname, qint8 Nhp, qint8 Nlength);

    /**
     * @brief           Gives reference. Attribute _hp.
     */
    qint8& getHp();

    /**
     * @brief           Gives reference. Attribute _name.
     */
    std::string& getName();

    /**
    * @brief            Gives reference. Attribute _sunk.
    */
    bool& getSunk();

    /**
     * @brief           Gives reference. Attribute _placed.
     */
    bool& getPlaced();

    /**
     * @brief           Gives reference. Attribute _length.
     */
    qint8 getLength();

    /**
     * @brief           Gives reference. Attribute _coordinates.
     */
    std::vector<std::pair<qint8,qint8> >& getCoordinates();
};



#endif /* SHIP_H */

