#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "board.h"


/**
 * @brief Class Player. Important attributes: His board, his health, status variable turn.
 */

class Player{

private:
	/**
     * @brief  Player's board.
	 */
    Board* _myBoard = new Board();

    /**
     * @brief  Bool. 1-> It's the player's turn. 0-> It's not the player's turn.
     */
    bool _turn;

    /**
     * @brief  A player has 30 healthpoints.
     */
    qint8 _health;


public:

    /**
     * @brief  Returns reference. Attribute _health.
     */
    qint8& getHealth();

    /**
     * @brief       Constructor of class player.
     */
    Player();

    /**
     * @brief       Gives reference. Attribute _turn.
     */
    bool& getTurn();

    /**
     * @brief       Gives reference. Attribute _turn.
     */
    Board& getMyBoard();

    /**
     * @brief       () overloading. Returns reference on string in the 10x10 board.
     * @param[c]    coordinate c.
     * @return      (see brief)
     */
    std::string& operator()(std::pair<qint8,qint8> c);
};

#endif // PLAYER_H
