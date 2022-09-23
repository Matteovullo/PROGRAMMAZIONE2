#include <iostream>
#include <fstream>
using namespace std;

#include "Comande.h"
#include "list.h"

int main(){
    //punto 1
    ifstream file("Comande.txt");
    List<Comande> l;
    for(int i=0; i<59; i++){
        Comande c;
        file >> c;
        cout << c << endl;
        l.insertTail(c);
    }

    cout << l << endl;

    //punto 2
    l.raggruppa("Ortis");

    //punto 3
    double d=l.cerca("Ortis");
    cout << d << endl << endl;

    //punto 4
    l.elimina();
    cout << l << endl << endl;

    //punto bonus 1


    //punto bonus 2
    l.classifica();
}