#ifndef GIOCATORE
#define GIOCATORE

#include<iostream>
using namespace std;

class Giocatore{
    private:
        string nome;
        string cognome;
        string circolo;
        double punteggio;
        int data;

    public:
        Giocatore(){}
        string get_cognome(){return cognome;}
        double get_punteggio(){return punteggio;}
        bool operator<(Giocatore& g){
            return punteggio < g.punteggio;
        }
        bool operator>(Giocatore& g){
            return punteggio > g.punteggio;
        }
        bool operator==(Giocatore& g){
            return punteggio==g.punteggio;
        }
        bool operator!=(Giocatore& g){
            return punteggio!=g.punteggio;
        }
        friend istream& operator>>(istream& imput, Giocatore& g){
            string n, m, c, p, d;
            getline(imput, n, ';');
            getline(imput, m, ';');
            getline(imput, c, ';');
            getline(imput, p, ';');
            getline(imput, d, '\n');
            g.nome=m;
            g.cognome=n;
            g.circolo=c;
            g.punteggio=atof(p.c_str());
            g.data=atoi(d.c_str());
            return imput;
        }
        friend ostream& operator<<(ostream& os, Giocatore& g){
            os << g.cognome << ";" << g.nome << ";" << g.circolo << ";" << g.punteggio << ";" << g.data << endl;
            return os;
        }
};

#endif