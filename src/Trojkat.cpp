#include "Trojkat.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <sstream>

using namespace std;

Trojkat::Trojkat(int x1,int y1,int x2,int y2,int x3,int y3, int bold, string color,string colorStroke,int ilosc, string data)
:Figura(x1,y1,bold,ilosc,color,colorStroke,data)
{
    this->x1=x2;
    this->y1=y2;
    this->x2=x3;
    this->y2=y3;
    this->rysuj();
}

Trojkat::Trojkat(int id, float skala,string name)
:Figura(id, skala,name)
{
    this->modyfikuj();
}

Trojkat::~Trojkat()
{
    //dtor
}

void Trojkat::rysuj()
{
string error="Brak uprawnien";
    ifstream is;
    ofstream os;
    string data;
    int i=-1;
    rename((this->getFileName()+".svg").c_str(), "temporary.svg");
    is.open("temporary.svg");
    if (is.good()){
        os.open((this->getFileName()+".svg").c_str());
        while (!is.eof()){
            getline(is,data);
            if (i==(this->getID())){
                os << "    <polygon id='" << this->getID() << "' points='" <<  this->getX() << "," << this->getY() << " " <<  this->getX1() << "," << this->getY1() << " " <<  this->getX2() << "," << this->getY2() << "' style='fill:" << this->getColor() <<"; stroke-width:" << this->getBold() <<"; stroke:"<< this->getColorStroke()<< "' />" << endl;
            }
            os << data;
            if (data != "</svg>") os << endl;
            i++;
        }
        is.close();
        os.close();
        remove("temporary.svg");
    }else {
        rename("temporary.svg",(this->getFileName()+".svg").c_str());
        throw error;
    }
}
void Trojkat::modyfikuj()
{
    if (this->getSkala()!=0)
        this->skaluj();
}

bool Trojkat::searchThis(string data)
{
    string zmienna="";
    size_t tu=data.find("id='");
    tu+=4;
    while(data.at(tu)!='\''){
        zmienna+=data.at(tu);
        tu++;
    }
    int a=this->convert(zmienna);
    return (a==(this->getID()));
}

string Trojkat::getData(string data, size_t &tutaj)
{
    string where="";
    while (data.at(tutaj)!=','){
        if (data.at(tutaj)==' ' || data.at(tutaj)=='\'') break;
        where+=data.at(tutaj);
        tutaj++;
    }
    return where;
}

int Trojkat::convert(string dane)
{
    istringstream iss(dane);
    int a;
    iss >> a;
    return a;
}

void Trojkat::oblicz(string data,float dane[6])
{
    string where="points";
    size_t tutaj= data.find(where);
    tutaj+=8;
    string table[6];
    for (int i=0;i<6; i++){
        table[i]=this->getData(data, tutaj);
        dane[i]=convert(table[i])*this->getSkala();
        tutaj++;
    }
}

string Trojkat::prepare(string data, float dane[6])
{
    size_t tu = data.find("points");
    tu+=8;
    for (int i=0;i<6;i++){
        while (data.at(tu)!=','){
            if (data.at(tu)==' ' || data.at(tu)=='\'') break;
            data.erase(tu,1);
        }
        stringstream FloatToStr;
        string str;
        FloatToStr << dane[i];
        FloatToStr >> str;
        FloatToStr.clear();
        data.insert((tu),(str).c_str());
        tu+=str.size()+1;
    }
    return data;
}

void Trojkat::skaluj()
{
    float dane[6];
    string data;
    string error="Blad otwarcia";
    ifstream plik;
    ofstream save;
    rename((this->getFileName()+".svg").c_str(),"temporary.svg");

    plik.open("temporary.svg");
    if (plik.good()){
        save.open((this->getFileName()+".svg").c_str());
        while(!plik.eof())
        {
            getline(plik,data);
            if (data!="</svg>" && this->searchThis(data)){
                this->oblicz(data,dane);
                data=this->prepare(data,dane);
                save << data << endl;
                continue;
            }
            save << data;
            if (data!="</svg>") save << endl;
        }
        plik.close();
        save.close();
        remove("temporary.svg");
    }else {
        rename("temporary.svg",(this->getFileName()+".svg").c_str());
        throw error;
    }
}

int Trojkat::getX1()
{
    return this->x1;
}

int Trojkat::getX2()
{
    return this->x2;
}

int Trojkat::getY1()
{
    return this->y1;
}

int Trojkat::getY2()
{
    return this->y2;
}
