#include "Tablica.h"
#include "Figura.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Tablica::Tablica()
{

}

Tablica::~Tablica()
{
    //dtor
}

string Tablica::deleteFigura(string data, int a)
{
    string licz="";
    int liczby;
    ostringstream id, liczba;
    id << a;
    for (int i=0; i<data.length(); i++){
        if (data.at(i)=='i' && data.at(i+1)=='d'){
            int j=0;
            i+=3;
            int temp=i+1;
            while(j!=2){
                if (data.at(i)=='\'') j++;
                else licz+=data.at(i);
                i++;
            }
            if (id.str()==licz) return "";
            istringstream iss(licz);
            iss >> liczby;
            if (liczby<a) return data;
            else{
                liczby--;
                liczba << liczby;
                licz = liczba.str();
                for (int z=0; z<licz.size(); z++){
                    data.at(temp) = licz.at(z);
                }
                return data;
            }
        }
    }
    return data;
}

void Tablica::addFile(string fileName, int ilosc)
{
    ofstream file;
    string name=fileName+".svg";
    file.open(name.c_str());
    file << "<svg id='" << ilosc << "' xmlns='http://www.w3.org/2000/svg'>" << endl;
    file << "</svg>";
    file.close();
}

void Tablica::removeFile(string nazwa){
    ifstream f;
    string info = "plik nie istnieje";
    string error="nie mozna usunac pliku";
    f.open((nazwa+".svg").c_str());
    if (f.good()){
        f.close();
        if (remove((nazwa+".svg").c_str())==0);
        else throw error;
    }else throw info;
}
