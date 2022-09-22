#include<iostream>
using namespace std;

#include "bst.h"

class Persona{
    private:
        int eta;
        string nome;
        string cognome;

    public:
        Persona(string nome, string cognome, int eta) : nome(nome), cognome(cognome), eta(eta){}
        int getEta(){return eta;}
};

class Studente : public Persona{
    public:
        Studente(string nome, string cognome, int eta) : Persona(nome, cognome, eta){}
};

class Lavoratore : public Persona{
    public:
        Lavoratore(string nome, string cognome, int eta) : Persona(nome, cognome, eta){}
};

class Pensionato : public Persona{
    public:
        Pensionato(string nome, string cognome, int eta) : Persona(nome, cognome, eta){}
};

int main(){
    //punto 1
    int n=10;
    //cout << "Inserire il numero di ogetti" << endl;
    //cin >> n;
    Persona* array[n];
    string nomi[n];
    string cognomi[n];
    for(int i=0; i<n; i++){
        nomi[i]="Matteo";
        cognomi[i]="Vullo";
    }
    for(int i=0; i<n; i++){
        int r=rand()%(3-1+1)+1;
        if(r==1) {
            array[i]=new Studente(nomi[i], cognomi[i], rand()%(30-5+1)+5);
        }
        if(r==2){
            array[i]=new Lavoratore(nomi[i], cognomi[i], rand()%(70-20+1)+20); 
        }
        if(r==3){
            array[i]=new Pensionato(nomi[i], cognomi[i], rand()%(95-65+1)+65);
        }
    }

    //punto 2
    BST<int> persona;
    for(int i=0; i<n; i++){
        persona.insert(array[i]->getEta());
    }
    cout << persona << endl;

    //punto 3
    cout << persona.getMediaStudenti() << endl;
    cout << persona.getMediaLavoratori() << endl;
    cout << persona.getMediaPensionati() << endl;

    //punto 4
    int valore=50;
    //cout << "Inserire il valore: " << endl;
    //cin >> valore;
    persona.remove_below(valore);
    cout << persona << endl;
}