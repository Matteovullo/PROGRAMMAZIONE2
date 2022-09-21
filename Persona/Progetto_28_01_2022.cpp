#include<iostream>
using namespace std;

#include "static_queue.h"
#include "static_stack.h"

class Persona{
    private:
        int eta;
        string nome;
        string cognome;

    public:
        Persona(string nome, string cognome, int eta) : nome(nome), cognome(cognome), eta(eta){}
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

int valori_medi(BST<Persona*> bst){
    int valore_s=0;
    int valore_l=0;
    int valore_p=0;
    for()
}

int main(){
    //punto 1
    int n;
    cout << "Inserire il numero di ogetti" << endl;
    cin >> n;
    Persona** array=new Persona*[n];
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
    StaticQueue<double> coda(1000);
    for(int i=0; i=2*n; i++){
        coda.enqueue()
    }

    //punto 3


    //punto 4
    int valore;
    cout << "Inserire il valore: " << endl;
    cin >> valore;
    for(int i=0; i<n; i++){
        double a=
    }
}