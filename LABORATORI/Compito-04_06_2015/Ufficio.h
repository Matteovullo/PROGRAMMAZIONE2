#ifndef UFFICIO
#define UFFICIO

#include<iostream>
using namespace std;

#include "Dipendente.h"

class Ufficio{
    private:
        int ID;
        string nome_uff;
        Dipendenti** elenco;
        int n=0;

    public:
        Ufficio(string nome_uff, int ID) : nome_uff(nome_uff), ID(ID){
            elenco=new Dipendenti*[1000];
            for(int i=0; i<1000; i++){
                elenco[i]=nullptr;
            }
        }
        int getID(){return ID;}
        void ins(string s1, string s2, int ID){
            for(int i=0; i<1000; i++){
                if(elenco[i] == nullptr){
                    elenco[i]=new Dipendenti(s1, s2, ID);
                    n++;
                    return;
                }
            }
        }
        Dipendenti* get(int i){
            if(elenco[i]) return elenco[i];
            else nullptr;
        }
        void in_comune(Ufficio u){
            for(int i=0; i<1000; i++){
                Dipendenti* ptr=get(i);
                for(int j=i; j<1000; j++){
                    if(ptr != nullptr && u.get(j) != nullptr && u.get(j)->getID() == ptr->getID()){
                        cout << *get(i) << endl;
                    }
                }
            }
        }
        friend ostream& operator<<(ostream& os, Ufficio& u){
            cout << "NOME UFFICIO=" << u.nome_uff << ", ID=" << u.ID << endl;
            for(int i=0; i<u.n; i++){
                os << *u.elenco[i] << endl;
            }
            return os;
        }
};

#endif