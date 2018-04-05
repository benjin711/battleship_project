#ifndef COMMAND_H
#define COMMAND_H

#include <QtGlobal>
#include <vector>
#include <QString>

class command
{
public:
     command(quint8 cmd, quint8 length);

     quint8 getCMD(void);
     quint8 getLength(void);
     std::vector<quint8> getData(void);


private:
    const quint8 qui_cmdCMD;
    const quint8 qui_cmdLength;

protected:
    std::vector<quint8> vec_cmdData;

};



class GameStart : public command
{
  public:
    GameStart(std::vector<quint8> data);
};


/**
*   Byte 1  Feldgroeße X-Richtung (Norm 10)
*   Byte 2  Feldgroeße Y-Richtung (Norm 10)
*   Byte 3  Anzahl Schlachtschiffe (Norm 1)
*   Byte 4  Anzahl Kreuzer (Norm 2)
*   Byte 5  Anzahl Zerstörer (Norm 3)
*   Byte 6  Anzahl U-Boote (Norm 4)
*/
class GameParams : public command
{
   public:
    GameParams(std::vector<quint8> data);
};



/**
*   Byte 1  X-Koordinate
*   Byte 2  Y-Koordinate
*/
class Shoot : public command
{
   public:
    Shoot(std::vector<quint8> data);
};


/**
*   Byte 1  Statuscode
*           0x00 Ok
*           0x01 Abgelehnt oder nicht bereit
*           0x02 Nicht unterstuetzt
*           0x03 Nachricht unvollstaendig
*           0x04 Timeout beim Warten auf Bestaetigung
*           0x20 Sonstige Fehler
*/
class GameState : public command
{
   public:
    GameState(std::vector<quint8> data);
};


/**
*
*   Byte 1  Statuscode
*           0x00 Nicht getroffen
*           0x01 Getroffen
*           0x02 Getroffen und versenkt
*           0x03 Getroffen und versenkt,Spielende
*           0x10 Nicht an der Reihe
*           0x11 Ausserhalb des Feldes
*           0x20 Sonstige Fehler
*/
class ShootAnswer : public command
{
   public:
    ShootAnswer(std::vector<quint8> data);
};




#endif // COMMAND_H
