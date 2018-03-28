#include "spieler.h"

///Implementation Klasse Spieler


Spieler::Spieler(int Nid) :_id(Nid), _amZug(0), _leben(30)
{

}


int& Spieler::getId()
{
	return _id;
}

void Spieler::setId(int Nid)
{
	_id = Nid;
}


bool& Spieler::getAmZug()
{
	return _amZug;
}

void Spieler::setAmZug(bool NAmZug)
{
	_amZug = NAmZug;
}


SpielfeldLOGIK& Spieler::getMeinSpielfeldLOGIK()
{
    return *_meinSpielfeldLOGIK;
}



std::string& Spieler::operator()(std::pair<int,int> k)
{
    return getMeinSpielfeldLOGIK().getSpielfeldLOGIK(k);
}


int& Spieler::getLeben()
{
    return _leben;
}



void Spieler::setLeben(int Nleben)
{
    _leben = Nleben;
}






















