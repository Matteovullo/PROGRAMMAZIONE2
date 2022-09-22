#include <iostream>
#include <fstream>
using namespace std;

#include "List.h"
#include "bst.h"
#include "film.h"

int main(){
    List l;
    ifstream file("film.txt");
    for(int i=0; i<1002; i++){
        Film f;
        file >> f;
        cout << f;
        l.insert(f);
    }
    cout << endl;

    cout << l << endl;

    Bst<Film> bst;
    for(int i=0; i<1002; i++){
        Film f=l.getHead();
        bst.insert(f);
        l.remove();
    }

    
    cout << bst << endl;
}