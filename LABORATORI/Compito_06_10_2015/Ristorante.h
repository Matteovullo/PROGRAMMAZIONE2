#ifndef RISTORANTE
#define RISTORANTE

#include<iostream>
using namespace std;

class Ristorante{
    private:
        string nome;
        int tavoli, capienza;

    public:
        Ristorante(string nome, int tavoli, int capienza) : nome(nome), tavoli(tavoli), capienza(capienza){}
        bool operator<=(Ristorante& r){
            return capienza <= r.capienza;
        }
        bool operator>=(Ristorante& r){
            return capienza >= r.capienza;
        }
        bool operator!=(Ristorante& r){
            return capienza!=r.capienza;
        }
        bool operator==(Ristorante& r){
            return capienza==r.capienza;
        }
        void setNome(string n){
            this->nome=n;
        }
        void setCapienza(int capienza){
            this->capienza=capienza;
        }
        void setTavoli(int tavoli){
            this->tavoli=tavoli;
        }
        string getNome(){return nome;}
        int getCapienza(){return capienza;}
        int getTavoli(){return tavoli;}
        friend ostream& operator<<(ostream& os, Ristorante& r){
            os << "Nome: " << r.nome << ", numero tavoli:" << r.tavoli << ", capienza: " << r.capienza << endl;
            return os;
        }
};

#endif