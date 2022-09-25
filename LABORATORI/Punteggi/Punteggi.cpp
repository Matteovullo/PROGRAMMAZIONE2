#include<iostream>
#include<fstream>
using namespace std;

#include "Giocatori.h"
#include "List.h"
#include "Recupero_informazioni.h"

int main(){
    //punto 1
    ifstream file("punteggi.txt");
    Giocatore array[21];
    for(int i=0; i<21; i++){
        file >> array[i];
        cout << array[i];
    }
    List l;
    r(array, l, 21);
    cout << endl;
    cout << l << endl;

    //punto 2
    char c1='c';
    char c2='d';
    ordinamento(l, c1);
    ordinamento(l, c2);
    cout << endl;

    //punto 4
    string s="Spoto";
    l.get_info(l, s);
    cout << endl;

    //punto 4
    rimozione(l, 25.8);
    cout << endl;
    cout << l << endl;
}