#include <iostream>
using namespace std;

#include "list.h"
#include "Dipendente.h"
#include "Ufficio.h"

int main(){
    int x=1000;
    int y=1001;

    /*Dipendenti d1("Matteo", "Vullo", 100);
    Dipendenti d2("Alfio", "Spoto", 101);
    Dipendenti d3("Federico", "Vitle", 102);
    Dipendenti d4("Valentino", "Vacirca", 103);*/

    List<Ufficio> l;
    //punto 1
    Ufficio u1("u", x);
    l.insert(u1);
    Node<Ufficio>* ptr=l.search(u1);
    if(!ptr){
        Ufficio u2("Nuovo", x);
        u2.ins("Nuovo", "Dipendente", y);
        l.insert(u2);
    }else{
        //punto 2
        ptr->getVal().ins("Nuvo", "dipendente", y);
    }

    cout << l << endl;

            
    Ufficio u2("Nuovo", x);
    u2.ins("Nuovo", "Dipendente", y);
    Ufficio u3("Nuovo", x);
    u3.ins("Nuovo", "Dipendente", y);
    l.insert(u3);
    u3.in_comune(u2);
}