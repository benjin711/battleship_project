#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <QObject>
#include <QtGlobal>

class Game: public QObject{

    Q_OBJECT
private:
	/**
     * @brief  Player1: That's us.
	 */
    Player _player1;


    /**
     * @brief  Player2: The opponent.
     */
    Player _player2;

    /**
     * @brief Saves coordinate that player1 currently attacks.
     */
    std::pair<qint8,qint8> _p1AttackCoordinate = {-1,-1};

public:
    /**
     * @brief Constructor. Both player's turn is initially set to 0.
     */
    Game(QObject *parent=nullptr);

    /**
     * @brief  Returns reference on _player1
     */
    Player& getPlayer1();

    /**
     * @brief  Returns reference on _player2.
     */
    Player& getPlayer2();

    /**
     * @brief Returns reference on _p1AttackCoordinate.
     */
    std::pair<qint8,qint8>& getP1AttackCoordinate(){return _p1AttackCoordinate;}


public slots:

    /**
     * @brief       Checks if we are allowed to attack.
     * @param [c]   Coordinate that's being attacked.
     */
    void attackPlayer2(std::pair<quint8, quint8> c);

    /**
     * @brief Receiving information from network. 1-> It's our turn.
     */
    void setTurnOfBothPlayers(bool signal);

    /**
     * @brief Receiving information from network. Processing the attack on us.
     */
    void attackOnPlayer1(std::pair<quint8,quint8> c);

    /**
     * @brief Processing status code of the opponent after our attack on him.
     */
    void processingSCOpponent(quint8 statusCode, std::vector<std::pair<quint8, quint8> > coordinatesOfSunkShip ={{-1,-1}});


signals:

    /**
     * @brief attackP2Coordinate   Passes coordinate that should be attacked to network.
     */
    void attackP2Coordinate(quint8,quint8,std::vector<quint8>);

    /**
     * @brief ourSCtoNetwork       Passes our status code to network after we have been attacked.
     */
    void ourSCtoNetwork(quint8,quint8,std::vector<quint8>);

    /**
     * @brief infoToGuiAttackP1    Passes information, if opponent has hit water or ship etc.
     */
    void infoToGuiAttackP1(quint8,std::pair<quint8,quint8>);

    /**
     * @brief statusCodePlayer2    Passes status code information of opponent to GUI.
     */
    void statusCodePlayer2ToGUI(quint8, std::vector<std::pair<quint8,quint8> >, std::pair<quint8,quint8>);

};

#endif // GAME_H
