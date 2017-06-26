#include "Figura.h"
#include "Obiekt.h"
#include <iostream>
#include <string>

using namespace std;

Figura::Figura(int id, float skala, string fileName)
{
    this->id=id;
    this->skala=skala;
    this->fileName=fileName;
}

Figura::Figura(int id, float skala, bool zmiana, int x, int y,string fileName)
{
    this->id=id;
    this->skala=skala;
    this->zmiana=zmiana;
    this->x=x;
    this->y=y;
    this->fileName=fileName;
}

Figura::Figura(int x, int y, int bold, int id, string color, string colorStroke, string fileName)
{
    this->x=x;
    this->y=y;
    this->id=id;
    this->bold=bold;
    this->color=color;
    this->colorStroke=colorStroke;
    this->fileName=fileName;
}


Figura::~Figura()
{
    //dtor
}

string Figura::getFileName()
{
    return this->fileName;
}

string Figura::getColor()
{
    return this->color;
}

string Figura::getColorStroke()
{
    return this->colorStroke;
}

int Figura::getX()
{
    return this->x;
}
int Figura::getY()
{
    return this->y;
}
int Figura::getBold()
{
    return this->bold;
}

int Figura::getID()
{
    return this->id;
}

float Figura::getSkala()
{
    return this->skala;
}

bool Figura::getZmiana()
{
    return this->zmiana;
}
