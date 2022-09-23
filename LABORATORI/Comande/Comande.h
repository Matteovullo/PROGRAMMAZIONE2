#ifndef COMANDE
#define COMANDE

#include<iostream>
#include <fstream>
using namespace std;

class Comande{
    private:
        string cognome, pizza;
        int quantita;
        double prezzo;

    public:
        Comande(){
            cognome=pizza="";
            quantita=0;
            prezzo=0;
        }
        string getCognome(){return cognome;}
        string getPizza(){return pizza;}
        double getPrezzo(){return prezzo;}
        bool operator==(Comande c){
            return prezzo == c.prezzo;
        }
        bool operator!=(Comande c){
            return prezzo != c.prezzo;
        }
        friend istream& operator>>(istream& imput, Comande& c){
            string co, p, q, pr;
            getline(imput, co, ',');
            getline(imput, p, ',');
            getline(imput, q, ',');
            getline(imput, pr, '\n');
            c.cognome=co;
            c.pizza=p;
            c.quantita=atoi(q.c_str());
            c.prezzo=atof(pr.c_str());
            return imput;
        }
        friend ostream& operator<<(ostream& os,const Comande& c){
            os << c.cognome << "," << c.pizza << "," << c.quantita << "," << c.prezzo << endl;
            return os;
        }
};

#endif