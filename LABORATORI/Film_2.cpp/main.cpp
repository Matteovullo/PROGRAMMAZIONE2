#include <iostream>
#include <fstream>
using namespace std;

#include "list.h"
#include "Film.h"

int main(){
    //punto 1
    ifstream file("imput.txt");
    List<Film> l;
    for(int i=0; i<3; i++){
        Film f;
        file >> f;
        cout << f << endl;
        l.insertInOrder(f);
    }
    cout << endl << endl;
    cout << l << endl;
    cout << endl << endl;

    //punto 2
    l.nuovo();
    cout << endl << endl;
    l.vecchio();
    cout << endl << endl;

    //punto 3
    l.estrazione("commedia");
}