#ifndef OBIEKT_H
#define OBIEKT_H
#include "Figura.h"
#include <iostream>

class Figura;

class Obiekt
{
    public:
        /**
        * Wirtualna metoda modyfikacji
        */
        virtual void modyfikuj()=0;
        /**
        * Wirtualna metoda rysowania
        */
        virtual void rysuj()=0;
};

#endif // OBIEKT_H
