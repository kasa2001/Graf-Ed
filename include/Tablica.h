#ifndef TABLICA_H
#define TABLICA_H
#include <iostream>
#include "Figura.h"
using namespace std;

class Tablica
{
        Figura *f;
        string fileName;


    public:
        Tablica();

        /**
        * Method add new svg file/Metoda dodaje nowy plik svg
        **/
        void addFile(string fileName, int ilosc);

        /**
        * Method remove svg file/Metoda usuwa plik svg
        **/
        void removeFile(string nazwa);

        /**
        * Method remove figura/Metoda usuwa figurê z pliku svg
        **/
        string deleteFigura(string data, int a);
        virtual ~Tablica();

};

#endif // TABLICA_H
