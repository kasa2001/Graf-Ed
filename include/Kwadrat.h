#ifndef KWADRAT_H
#define KWADRAT_H
#include "Figura.h"
#include "Obiekt.h"

class Kwadrat
    : public Figura, public Obiekt
{
    int a;

        /**
        * Metoda podmienia dane
        * @return string
        */
        string replaceThis(string data, string where, float liczba);

        /**
        * Metoda mnoży otrzymane wyniki i wywołuje metodę do podmieniania danych
        */
        void multiplication(string &dane, int j);

        /**
        * Metoda pobiera dane do modyfikacji
        * @return float
        */
        float getData(string dane, string where, int j, float a);

        /**
        * Metoda szuka figury
        * @return bool
        */
        bool searchFigura(string id,string dane);

        /**
        * Metoda g³ówna do skalowania figury
        */
        void skaluj();

        /**
        * Metoda odpowiada za przemieszczenie figury i zapisanie do niej
        * @return bool
        */
        void przemieszczenie();

        /**
        * Metoda ustawia wartości x i y
        * @return string
        */
        string setXAndY(string dane);
    public:
        /**
        * Method return length side/Metoda zwraca d³ugoœæ boku
        * @return int
        **/
        int getA();

        /**
        * Metoda do modyfikacji
        */
        virtual void modyfikuj();

        /**
        * Metoda do rysowania
        */
        virtual void rysuj();
        Kwadrat(int id, float skala, bool zmiana, int x, int y,string fileName);
        Kwadrat(int x, int y, int a, int bold, int ilosc, string color, string colorStroke, string data);
        virtual ~Kwadrat();

};

#endif // KWADRAT_H
