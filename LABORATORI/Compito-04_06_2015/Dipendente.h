#ifndef DIPENTENTE
#define DIPENTENTE

#include<iostream>
using namespace std;

class Dipendenti{
    private:
        int ID;
        string nome;
        string cognome;
        Dipendenti* next;

    public:
        Dipendenti(string nome, string cognome, int ID){
            this->nome=nome;
            this->cognome=cognome;
            this->ID=ID;
            next=nullptr;
        }
        int getID(){return ID;}
        friend ostream& operator<<(ostream& os, Dipendenti& d){
            os << "Nome=" << d.nome << ", cognome=" << d.cognome << ", ID=" << d.ID << endl; 
            return os;
        }
};

#endif 