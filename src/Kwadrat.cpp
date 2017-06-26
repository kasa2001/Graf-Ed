#include "Kwadrat.h"
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Kwadrat::Kwadrat(int id, float skala, bool zmiana, int x, int y,string fileName)
:Figura(id, skala,zmiana,x,y,fileName)
{
    this->modyfikuj();
}

Kwadrat::Kwadrat(int x, int y, int a, int bold, int ilosc, string color, string colorStroke, string data)
:Figura(x,y,bold,ilosc,color,colorStroke,data)
{
    this->a=a;
    this->rysuj();
}

void Kwadrat::rysuj()
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
            if (i == (this->getID())){
                os << "    <rect id='" << this->getID() << "' x='" << this->getX() <<"' y='" << this->getY() <<"' width='" << this->getA() << "' height='" << this->getA() << "' style='fill:" << this->getColor() <<"; stroke-width:" << this->getBold() <<"; stroke:"<< this->getColorStroke()<< "' />" << endl;
            }
            os << data;
            if (data != "</svg>") os << endl;
            i++;
        }
        is.close();
        os.close();
        remove("temporary.svg");
    }else {
        rename ("temporary.svg",(this->getFileName()+".svg").c_str());
        throw error;
    }
}

void Kwadrat::modyfikuj()
{
    if(this->getSkala()!=0)
        this->skaluj();
    if (this->getZmiana())
        this->przemieszczenie();
}

bool Kwadrat::searchFigura(string id,string dane)
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

float Kwadrat::getData(string dane, string where, int j, float a=0)
{
    size_t tu = dane.find(where);
    int i=tu;
    where="";
    while(j!=3){
        if (dane.at(i)=='\'' || dane.at(i)=='=') j++;
        else if(dane.at(i)>='0' && dane.at(i)<='9')where += dane.at(i);
        i++;
    }
    istringstream iss(where);
    iss >> a;
    return a;
}

string Kwadrat::replaceThis(string data, string where, float liczba)
{
    size_t tutaj= data.find(where);
    ostringstream oss;
    oss << liczba;
    while (true){
        if (data.at(tutaj+where.size()+2)!='\'') data.erase(tutaj+where.size()+2,1);
        else{
            data.insert((tutaj+where.size()+2),oss.str());
            break;
        }
    }
    return data;
}

void Kwadrat::multiplication(string &dane, int j=0)
{
    float a,b;
    a= this->getData(dane, "width",j)*this->getSkala();
    b= this->getData(dane, "height",j)*this->getSkala();
    dane=this->replaceThis(dane,"width", a);
    dane=this->replaceThis(dane,"height", b);
}

void Kwadrat::skaluj()
{
    string dane;
    string error="Problem z otwarciem";
    ostringstream oss; // strumień do konwersji z floata/int/double na stringa
    oss << this->getID();//
    rename ((this->getFileName()+".svg").c_str(), "temporary.svg");
    ifstream plik;
    ofstream save;
    plik.open("temporary.svg");
    if (plik.good()){
        save.open((this->getFileName()+".svg").c_str());
        while(!plik.eof())
        {
            getline(plik,dane);
            if (this->searchFigura(oss.str(),dane)){
                this->multiplication(dane);
                save << dane << endl;
                continue;
            }
            save << dane;
            if (dane!="</svg>") save << endl;
        }
        plik.close();
        save.close();
    }else {
        rename ("temporary.svg",(this->getFileName()+".svg").c_str());
        throw error;
    }
    remove ("temporary.svg");
}

void Kwadrat::przemieszczenie()
{
    string dane;
    string error="Problem z otwarciem";
    ostringstream oss;
    oss << this->getID();
    rename ((this->getFileName()+".svg").c_str(), "temporary.svg");
    ifstream plik;
    ofstream save;
    plik.open("temporary.svg");
    if (plik.good()){
        save.open((this->getFileName()+".svg").c_str());
        while(!plik.eof())
        {
            getline(plik,dane);
            if (this->searchFigura(oss.str(),dane)){
                dane = this->setXAndY(dane);
                save << dane << endl;
                continue;
            }
            save << dane;
            if (dane!="</svg>") save << endl;
        }
        plik.close();
        save.close();
    }else {
        rename ("temporary.svg",(this->getFileName()+".svg").c_str());
        throw error;
    }

    remove ("temporary.svg");
}

int Kwadrat::getA()
{
    return this->a;
}
Kwadrat::~Kwadrat(){

}

string Kwadrat::setXAndY(string dane)
{
    dane=this->replaceThis(dane,"x", this->getX());
    dane=this->replaceThis(dane,"y", this->getY());
    return dane;
}
