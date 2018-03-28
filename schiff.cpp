#include "schiff.h"

/*
 * Implementation Klasse Schiff
 */

Schiff::Schiff(std::string Nname, int Nleben, int Nlaenge)
    : _name(Nname), _leben(Nleben), _gesunken(0), _gesetzt(0), _laenge(Nlaenge)
{
    for(int i=0; i < Nlaenge; i++)
    {
        _koordinaten.push_back(std::pair<int, int> (0,0));
    }
}

int& Schiff::getLeben()
{
    return _leben;
}

void Schiff::setLeben(int Nleben)
{
    _leben = Nleben;
}

std::string& Schiff::getName()
{
    return _name;
}

void Schiff::setName(std::string Nname)
{
    _name = Nname;
}

bool& Schiff::getGesunken()
{
    return _gesunken;
}

void Schiff::setGesunken(bool Ngesunken)
{
    _gesunken = Ngesunken;
}

bool& Schiff::getGesetzt()
{
	return _gesetzt;
}

void Schiff::setGesetzt(bool Ngesetzt)
{
	_gesetzt = Ngesetzt;
}

int Schiff::getLaenge()
{
	return _laenge;
}

std::vector<std::pair<int,int> >& Schiff::getKoordinaten()
{
	return _koordinaten;
}

void Schiff::setKoordinaten(std::vector<std::pair<int,int> > Nkoordinaten)
{
	_koordinaten = Nkoordinaten;
}







