#include "player.h"

//Constructor class player

Player::Player() : _turn(0), _health(30)
{
}


///////////////////////////////////////////////////////////////////////////////////////////////////

bool& Player::getTurn()
{
    return _turn;
}


///////////////////////////////////////////////////////////////////////////////////////////////////

Board& Player::getMyBoard()
{
    return *_myBoard;
}


///////////////////////////////////////////////////////////////////////////////////////////////////

std::string& Player::operator()(std::pair<qint8,qint8> c)
{
    return getMyBoard().getStringOnBoard(c);
}


///////////////////////////////////////////////////////////////////////////////////////////////////

qint8& Player::getHealth()
{
    return _health;
}























