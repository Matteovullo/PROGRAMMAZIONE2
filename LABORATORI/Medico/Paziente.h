#ifndef PAZIENTE
#define PAZIENTE

#include<iostream>
using namespace std;

class Paziente{
    private:
        string nome, cognome, codice_fiscale;
        int urgenza;

    public:
        Paziente(){}
        int getUrgenza(){return urgenza;}
        bool operator==(Paziente p){
            return codice_fiscale==p.codice_fiscale;
        }
        string getCodiceFiscale(){return codice_fiscale;}
        friend ostream& operator<<(ostream& os,const Paziente& p){
            os << p.codice_fiscale << ";" << p.nome << ";" << p.cognome << ";" << p.urgenza << endl;
            return os;
        }
        friend istream& operator>>(istream& imput, Paziente& p){
            string n, c, u, cf;
            getline(imput, cf, ';');
            getline(imput, n, ';');
            getline(imput, c, ';');
            getline(imput, u, '\n');
            p.codice_fiscale=cf;
            p.nome=n;
            p.cognome=c;
            p.urgenza=atoi(u.c_str());
            return imput;
        }
};

#endif