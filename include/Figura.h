#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>
#include "Obiekt.h"
using namespace std;

class Figura
{

    string fileName;
    string color;
    string colorStroke;
    int x;
    int y;
    float skala;
    bool zmiana;
    int bold;
    int id;
    public:
        Figura();
        /**
        * Metoda zwraca informacje - czy zmienić położenie figury
        * @return bool
        */
        bool getZmiana();

        /**
        * Metoda zwraca informacje - o ile przeskalować plik
        * @return float
        */
        float getSkala();
        Figura (int id, float skala, string fileName);
        Figura(int id, float skala, bool zmiana, int x, int y,string fileName);
        Figura(int x, int y, int bold, int id, string color, string colorStroke, string fileName);
        virtual ~Figura();

        /**
        * Method return a file name/Metoda zwraca nazwê pliku
        * @return string
        **/
        string getFileName();

        /**
        * Method return a color square/Metoda zwraca kolor kwadratu
        * @return string
        **/
        string getColor();

        /**
        * Method return a stroke square color/Metoda zwraca kolor linii
        * @return string
        **/
        string getColorStroke();

        /**
        * Method return a x position left top corner/Metoda zwraca x lewego górnego rogu
        * @return int
        **/
        int getX();

        /**
        * Method return a y position left top corner/Metoda zwraca y lewego górnego rogu
        * @return int
        **/
        int getY();


        /**
        * Method return bold stroke square/Metoda zwraca gruboœæ linii kwadratu
        * @return int
        **/
        int getBold();

        int getID();
};

#endif // FIGURA_H
