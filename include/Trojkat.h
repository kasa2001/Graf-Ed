#ifndef TROJKAT_H
#define TROJKAT_H
#include "Figura.h"

class Trojkat : public Obiekt, public Figura
{
    int x1;
    int y1;
    int x2;
    int y2;
    /**
    * Metoda g³ówna do modyfikacji
    */
    void modyfikuj();
    /**
    * Metoda g³ówna do rysowania
    */
    void rysuj();

    /**
    * Metoda oblicza o ile ma byæ powiêkszony trójk¹t
    */
    void oblicz(string data,float dane[6]);

    /**
    * Metoda przygotowuje do zapisania do pliku
    * @return string
    */
    string prepare(string data, float dane[6]);

    /**
    * Metoda szuka trójk¹ta po id
    * @return bool
    */
    bool searchThis(string data);

    /**
    * Metoda g³ówna do skalowania figury
    */
    void skaluj();

    /**
    * Metoda konwertuje zmienn¹ typu string na int
    */
    int convert(string dane);

    /**
    * Metoda pobiera dane dot. trójk¹ta (po³o¿enie punktów)
    */
    string getData(string data, size_t &tutaj);
    public:
        Trojkat(int id, float skala, string name);
        Trojkat(int x1,int y1,int x2,int y2,int x3,int y3, int bold, string color,string colorStroke,int ilosc, string data);
        virtual ~Trojkat();

    /**
    * Metoda zwaca x1
    * @return x1
    */
    int getX1();
    /**
    * Metoda zwaca x2
    * @return x2
    */
    int getX2();
    /**
    * Metoda zwaca y1
    * @return y1
    */
    int getY1();
    /**
    * Metoda zwaca y2
    * @return y2
    */
    int getY2();
};

#endif // TROJKAT_H
