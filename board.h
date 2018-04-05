/*
 * Deklaration Klasse SpielfeldLOGIK
 */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <QObject>
#include <QDebug>
#include <exception>

#include "ship.h"


/**
 * @brief Class Board. Most important attributes: A vector with all 10 ships and a 10x10 board of strings.
 */

class Board : public QObject{

    Q_OBJECT

private:
	/**
     * @brief  Board 10x10. Initialized with "water".
	 */
    std::vector<std::vector<std::string> > _board;

    /**
     * @brief  Vector with all 10 ships.
     */
    std::vector<Ship> _vectorOfShips;

    /**
     * @brief  Status Variable. Number of placed ships.
     */
    qint8 _noPlacedShips;

    /**
     * @brief  Status Variable. Number of sunk ships.
     */
    qint8 _noSunkShips;

    /**
     * @brief  Saves the length of the ship that is currently being placed.
     */
    qint8 _lengthOfCurrentShip;

    /**
     * @brief  Pair with the start and end coordinates of currently to be placed ship.
     */
    std::vector<std::pair<qint8,qint8> >_C1C2;




public:

    /**
     * @brief  Constructor. Initializes board with "water" and initializes the 10 ships in vector.
     */
    explicit Board(QObject *parent = nullptr);

    /**
     * @brief       Checks if coordinates from c1 to c2 excluding c1 are unoccupied.
     * @param[c1]   1. coordinate
     * @param[c2]   2. coordinate
     * @return      Bool. 0 -> Spaces not occupied. 1 -> Spaces are occupied.
     */
    bool spacesOccupied(std::pair<qint8,qint8> c1, std::pair<qint8,qint8> c2);

    /**
     * @brief       Getter.
     * @param[c]    Coordinate.
     * @return      Returns the string corresponding to the coordinate c.
     */
    std::string& getStringOnBoard(std::pair<qint8,qint8> c);

    /**
     * @brief           Returns reference of a ship in _vectorOfShips of length length that has not been placed yet
     * @param[length]   Length of the ship that is currently being placed.
     * @return          (see above)
     */
    Ship& getShipInVectorOfLength(qint8 length);

    /**
     * @brief           Gives reference. Attribute _vectorOfShips.
     */
    std::vector<Ship>& getVectorOfShips();

    /**
     * @brief           Gives reference. Attribute _noPlacedShips.
     */
    qint8& getNoPlacedShips();

    /**
     * @brief           Gives reference. Attribute _noSunkShips.
     */
    qint8& getNoSunkShips();

    /**
     * @brief                Returns 1->Ship is sunk, 0->Ship is afloat.
     * @param[nameShip]      Name of the ship of interest.
     */
    bool isShipSunk(std::string nameShip);

    /**
     * @brief   Gives referene. Attribute _lengthOfCurrentShip.
     */
    qint8& getLengthOfCurrentShip();

    /**
     * @brief       Gives reference. Attribute _C1C2.
     */
    std::vector<std::pair<qint8, qint8> > &getC1C2();

    /**
     * @brief       Places Ships on Board and in the vector of ships.
     * @param[c1]   Startcoordinate
     * @param[c2]   Endcoordinate
     */
    void setShip(std::pair<qint8,qint8> c1, std::pair<qint8,qint8> c2);


public slots:

    /**
     * @brief       Places Ships on the board of Player1 randomly.
     */
    void randomShipPlacement();

    /**
     * @brief       Setter. Attribute _lengthOfCurrentShip.
     */
    void setLengthOfCurrentShip(int lengthOfCurrentShip);

    /**
     * @brief       Calculates either the possible end coordinates (c2) of the ship or all it's coordinates it occupies, depending on if c is the start or end coordinate of ship.
     * @param[c]    Start or End coordinate of to be placed ship c1/c2
     */
    void coordinatesOfShip(std::pair<int,int> c);


signals:
    /**
     * @brief possibleC2             Gives possible end coordinates of ship to GUI.
     * @param [endCoordinates]       Vector of possible end coordiantes.
     * @param [c1]                   Start coordinate.
     * @param [lengthOfCurrentShip]  Length of the currently to be placed ship.
     */
    void possibleC2(std::vector<std::pair<qint8,qint8> > endCoordinates, std::pair<qint8,qint8> c1, qint8 lengthOfCurrentShip);

    /**
     * @brief coordinatesOfPlacedShip       Sends the final coordinates of the ship that is to be placed.
     * @param finalCoordinates              The coordinates of the placed ship.
     */
    void coordinatesOfPlacedShip(std::vector<std::pair<qint8,qint8> > finalCoordinates);

    /**
     * @brief allShipsPlaced            Signals GUI if all the ships have already been placed or not.
     * @param [signal]                  1-> all ships have been placed.
     */
    void allShipsPlaced(bool signal);

    /**
     * @brief coordinatesOfAllShips     Sends vector with all coordinates of all ships.
     * @param [allCoordinates]          (see brief)
     */
    void coordinatesOfAllShips(std::vector<std::pair<qint8,qint8> > allCoordinates);

};





#endif /* BOARD_H */
