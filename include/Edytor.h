#ifndef EDYTOR_H
#define EDYTOR_H
#include "Tablica.h"
#include <iostream>
#include <string>

class Edytor
{
    char a;
    Tablica *tablica;
    Obiekt *obiekt;

        /**
        * Metoda pobiera id
        * @return int
        */
        int setID();

        /**
        * Metoda pobiera informacje na temat skali
        * @return float
        */
        float skala();

        /**
        * Metoda przemieszcza figurę
        */
        void moveThis(bool &zmiana, int &x, int &y);

        /**
        * Metoda pobiera informacje potrzebne do modyfikacji
        */
        void setModify(bool &jest, int id, string name);

        /**
        * Metoda sprawdza figurę
        * @return bool
        */
        bool checkFigura(string dane, string id);

        /**
        * Metoda szuka figurę
        * @return bool
        */
        void searchFigura(bool &jest, string name, int a, bool &ktora);

        /**
        * Metoda wybiera figurę
        * @return bool
        */
        bool ktoraFigura();

        /**
        * Metoda sprawdza czy jest miejsce w pliku
        * @return bool
        */
        bool sprawdzMiejsce(string name, int &ilosc);


        /**
        * Metoda pobiera dane o istniejącym pliku
        * @return string
        */
        string setExisitsFileName();

        /**
        * Metoda wybiera jaką figurę należy wstawić
        */
        void  getInformation(bool ktora, int ilosc, string data);

        /**
        * Metoda odpowiada za wstawienie kwadratu do pliku
        */
        void wstawKwadrat(int ilosc, string data);

        /**
        * Metoda odpowiada za wstawienie trójkąta do pliku
        */
        void wstawTrojkat(int ilosc, string data);
        /**
        * Method convert data (string to int)/Metoda konwertuje dane ze stringa do integer'a
        * @return int
        **/
        int convert();

        /**
        * Method set param x/Metoda ustawia parametr x
        * @return int
        **/
        int setX();

        /**
        * Method set param y/Metoda ustawia parametr y
        * @return int
        **/
        int setY();

        /**
        * Method set param a/Metoda ustawia parametr a
        * @return int
        **/
        int setA();

        /**
        * Method set param bold/Metoda ustawia parametr bold (gruboœæ linii)
        * @return int
        **/
        int setBold();

        /**
        * Method check correctness introduced string (is a number)/Metoda sprawdza poprawoœæ wprowadzonego stringa (czy jest on liczb¹)
        * @return bool
        **/
        bool check(string data);

        /**
        * Method get data about new file and add him/Metoda pobiera dane o nowym pliku i dodaje go
        **/
        void dodajFigure();

        /**
        * Method delete file if exists/Metoda usuwa plik jeœli istnieje
        **/
        void usunFigure();

        void usunTablice();

        void modyfikujFigure();

        /**
        * Method directs to selected action/Metoda kieruje do wybranej akcji
        * @param a char
        **/
        void kieruj();

        /**
        * Method set param color/Metoda ustawia parametr color
        * @return string
        **/
        string setColor();

        /**
        * Method set param colorStroke/Metoda ustawia parametr colorStroke
        * @return string
        **/
        string setColorStroke();

        /**
        * Method set param fileName/Metoda ustawia parametr fileName
        * @return string
        **/
        string setFileName(bool method=false);
        /**
        * Metoda ustawia ilosc obrazów w pliku
        * @return int
        */

        public:
            Edytor();

            /**
            * Method start program/Metoda rozpoczyna program
            **/
            void menu();


            virtual ~Edytor();
};

#endif // EDYTOR_H
