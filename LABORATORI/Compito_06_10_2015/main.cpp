#include <iostream>
using namespace std;

#include "Ristorante.h"
#include "list.h"

int main(){
    List<Ristorante> l;
    Ristorante r1("Toto e peppino", 20, 100);
    Ristorante r2("Vecchio Mulino", 15, 70);
    Ristorante r3("La saporita", 50, 500);
    Ristorante r4("Toto", 25, 150);
    Ristorante r5("Peppino", 100, 1000);


    l.insert(r1);
    l.insert(r2);
    l.insert(r3);
    l.insert(r4);
    l.insert(r5);

    cout << l << endl;

    l.visualizza_maggiori(110);
    cout << endl << endl;

    l.cambia("Toto");
    cout << l << endl;

    cout << endl << endl;
    l.elimina("Peppino");
    cout << l << endl;

}