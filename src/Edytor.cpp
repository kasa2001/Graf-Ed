#include "Edytor.h"
#include "Tablica.h"
#include "Trojkat.h"
#include "Kwadrat.h"
#include <iostream>
#include <conio.h>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#define WAIT 6000
#define sleep Sleep
#endif
#ifdef __gnu_linux__
#include <unistd.h>
#define WAIT 2
#endif
using namespace std;

// Constructor
Edytor::Edytor()
{
    Edytor::menu();
}

//Destructor
Edytor::~Edytor()
{

}

// G³ówne menu
void Edytor::menu()
{
    do{
        system("cls");
        cout << "Menu" << endl;
        cout << "1. Dodaj tablice" << endl;
        cout << "2. Usun tablice" << endl;
        cout << "3. Dodaj figure" << endl;
        cout << "4. Usun figure" << endl;
        cout << "5. Modyfikuj figure" << endl;
        cout << "0. Zakoncz program" << endl;
        cout << "Wybierz opcje: ";
        Edytor::kieruj();
    }while(this->a!='0');
}

// Kieruje do odpowiedniej metody (usuniêcie, dodanie lub koniec)
void Edytor::kieruj()
{
    int zmienna;
    cin >> this->a;
    system("cls");
    cin.sync();
    switch (a)
    {
    case '1':
        this->tablica=new Tablica();
        cout << "Podaj maksymalna ilosc figur: ";
        zmienna=this->convert();
        this->tablica->addFile(this->setFileName(false),zmienna);
        delete tablica;
        break;
    case '2':
            Edytor::usunTablice();
        break;
    case '3':
        try{
            Edytor::dodajFigure();
        }catch (string e){
            cout << e << endl;
            sleep(WAIT);
        }
        break;
    case '4':
        try{
            Edytor::usunFigure();
        }catch (string e){
            cout << e << endl;
            sleep(WAIT);
        }
        break;
    case '5':
        try{
            Edytor::modyfikujFigure();
        }catch (string e){
            cout << e << endl;
            sleep(WAIT);
        }
        break;
    case '0':
        break;
    default:
        cout << "Zly wybor" << endl;
        sleep(WAIT);
        break;
    }
}

void Edytor::dodajFigure(){
    string info = "Plik nie istnieje";
    string error = "Brak miejsca";
    string data=this->setExisitsFileName();
    int ilosc=0;
    bool ktora = this->ktoraFigura();
    ifstream f;
    f.open((data+".svg").c_str());
    if (f.good()){
        f.close();
        if (this->sprawdzMiejsce((data+".svg"),ilosc)){
            this->getInformation(ktora,ilosc,data);
        }else throw error;
    }else throw info;
}
bool Edytor::ktoraFigura(){
    cout << "Czy chcesz wstawic kwadrat czy trojkat?[0/1]: ";
    return (bool)this->convert();
}

void Edytor::getInformation(bool ktora, int ilosc,string data)
{
    if (ktora) this->wstawTrojkat(ilosc, data);
    else this->wstawKwadrat(ilosc, data);
}

void Edytor::wstawTrojkat(int ilosc, string data)
{
    this->obiekt = new Trojkat(this->setX(), this->setY(), this->setX(), this->setY(), this->setX(), this->setY(), this->setBold(), this->setColor(), this->setColorStroke(), ilosc, data);
    delete this->obiekt;
}

void Edytor::wstawKwadrat(int ilosc, string data)
{
    this->obiekt = new Kwadrat(this->setX(),this->setY(), this->setA(), this->setBold(), ilosc, this->setColor(), this->setColorStroke(), data);
    delete this->obiekt;
}

bool Edytor::sprawdzMiejsce(string name, int &ile){
    string dane;
    string liczba="";
    ifstream f;
    f.open(name.c_str());
    bool found=false;
    if (f.good()){
        while (!f.eof()){
            getline(f,dane);
            if (!found) {
                for (int i=0; i<dane.length(); i++){
                    if(found) break;
                    if (dane.at(i)=='i' && dane.at(i+1)=='d'){
                        int j=0;
                        i+=2;
                        while(j!=3){
                            if (dane.at(i)=='\'' || dane.at(i)=='=') j++;
                            else liczba+=dane.at(i);
                            i++;
                        }
                        found=true;
                    }
                }
            }
            ile++;
        }
        f.close();
    }else{
        cout << "Skopalo sie" << endl;
    }

    stringstream iss(liczba);
    int zmienna;
    iss >> zmienna;
    ile-=2;
    return ile<zmienna;
}


string Edytor::setExisitsFileName(){
    string data;
    cout << "Podaj nazwe pliku: ";
    getline(cin, data);
    return data;
}



void Edytor::usunFigure(){
    string name, dane;
    string info = "plik nie istnieje";
    string error="Brak figury";
    cout << "Podaj nazwe pliku: ";
    getline(cin,name);
    ifstream f;
    ofstream save;
    rename ((name+".svg").c_str(),"temporary.svg");
    f.open("temporary.svg");
    save.open((name+".svg").c_str());
    if (f.good()){
        bool jest=false;
        cout << "Podaj id: ";
        int id=convert();
        this->tablica=new Tablica();
        while (!f.eof()){
            getline(f,dane);
            dane = this->tablica->deleteFigura(dane , id);
            if (dane!=""){
                save << dane;
                if (dane!="</svg>") save << endl;
            }else{
                jest=true;
            }
        }
        f.close();
        save.close();
        remove ("temporary.svg");
        if (!jest)throw error;
    }else throw info;
}


bool Edytor::checkFigura(string dane, string id)
{
    string licz="";
    for (int i=0; i<dane.length(); i++){
        if (dane.at(i)=='i' && dane.at(i+1)=='d'){
            int j=0;
            i+=3;
            while(j!=2){
                if (dane.at(i)=='\'') j++;
                else licz+=dane.at(i);
                i++;
            }
            if (id==licz) return true;
            else return false;
        }
    }
    return false;
}

void Edytor::searchFigura(bool &jest, string name, int a, bool &ktora)
{
    ifstream plik;
    string data;
    string fraza="rect";
    size_t zmienna=0;
    ostringstream id;
    id << a;
    plik.open((name+".svg").c_str());
    if (plik.good()){
            while (!plik.eof()){
                getline(plik,data);
                if (this->checkFigura(data, id.str())){
                    jest=true;
                    plik.close();
                    zmienna= data.find(fraza);
                    if (zmienna==5) ktora=false;
                    else ktora=true;
                    return;
                }
            }
        plik.close();
    }else return;
}

void Edytor::setModify(bool &jest, int id,string name)
{
    bool ktora,zmiana;
    int x,y;
    x=y=0;
    this->searchFigura(jest, name, id, ktora);
    if (!jest) return;
    if (ktora) this->obiekt = new Trojkat(id, this->skala(), name);
    else{
        this->moveThis(zmiana,x,y);
        this->obiekt = new Kwadrat(id, this->skala(),zmiana,x,y,name);
    }
    delete obiekt;
}

float Edytor::skala()
{
    string data;
    cout << "Zmiana skali?[0-nie]: ";
    getline(cin, data);
    return atof(data.c_str());
}

void Edytor::moveThis(bool &zmiana, int &x, int &y)
{
    cout << "Zmiana polozenia?(0/1): ";
    zmiana = (bool)this->convert();
    if (zmiana){
        x=this->setX();
        y=this->setY();
    }
}


void Edytor::modyfikujFigure(){
    string name;
    string info = "Plik nie istnieje";
    string error="Brak figury";
    cout << "Podaj nazwe pliku: ";
    getline(cin,name);
    ifstream f;
    f.open((name+".svg").c_str());
    if (f.good()){
        f.close();
        bool jest=false;
        this->setModify(jest, this->setID(), name);
        if (!jest)throw error;
    }else throw info;
}
void Edytor::usunTablice()
{
    cout << "Podaj nazwe pliku: ";
    string nazwa;
    getline(cin,nazwa);
    this->tablica = new Tablica();
    try{
        this->tablica->removeFile(nazwa);
    }catch (string error){
        cout << error << endl;
        sleep(WAIT);
    }
    delete this->tablica;

}
// Konwersja danych. Potrzebne by nie wykrzaczy³ siê program przy pobieraniu liczby
int Edytor::convert()
{
    string data;
    int a;
    do{
        getline(cin, data);
        system("cls");
    }while(check(data)!=true);
    istringstream iss(data);
    iss >> a;
    return a;
}

// Sprawdzenie czy wprowadzony string jest liczb¹
bool Edytor::check(string data){
    for (int i=0; i<data.size();i++){
        if (data.at(i)<'0' || data.at(i)>'9'){
            cout << "Blad: Podaj liczbe!: ";
            return false;
        }
    }
    return true;
}


// Ustaw Kolor
string Edytor::setColor()
{
    string a;
    system("cls");
    cout << "Jaki kolor figury? (in English): ";
    getline (cin, a);
    return a;
}

// Ustaw X
int Edytor::setX()
{
    system("cls");
    cout << "Podaj polozenie X: ";
    return convert();
}

// Ustaw Y
int Edytor::setY()
{
    system("cls");
    cout << "Podaj polozenie y: ";
    return convert();
}

//Ustaw A
int Edytor::setA()
{
    system("cls");
    cout << "Podaj bok a: ";
    return convert();
}

// Ustaw gruboœæ czczionki
int Edytor::setBold()
{
    system("cls");
    cout << "Podaj grubosc linii w pikselach: ";
    return convert();
}

//Ustaw nazwê pliku
string Edytor::setFileName(bool method)
{
    string a;
    do{
        system("cls");
        cout << "Podaj nazwe pliku: ";
        getline(cin, a);
        ifstream f;
        f.open((a+".svg").c_str());
        if (f.good() && !method){
            cout << "Plik istnieje juz." << endl;
            f.close();
            sleep(WAIT);
        }else if (!f.good() && method){
            return NULL;
        }
        else break;
    }while(true);
    return a;
}

string Edytor::setColorStroke()
{
    string a;
    system("cls");
    cout << "Podaj kolor obramowania (in English): ";
    getline(cin, a);
    return a;
}

int Edytor::setID()
{
    system("cls");
    cout << "Podaj id: ";
    return convert();
}
