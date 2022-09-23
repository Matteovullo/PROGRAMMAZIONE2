#include <iostream>
using namespace std;

#include "bst.h"

int main(){
    BST<int> b;
    b.insert(10);
    b.insert(1);
    b.insert(5);
    b.duplicati_insert(10);
    b.duplicati_insert(10);
    b.insert(50);
    b.insert(2);

    cout << b << endl;

    /*b.duplicati_insert(50);
    cout << b << endl;
    b.duplicati_insert(50);
    cout << b << endl;

    b.duplicati_insert(10);
    b.duplicati_insert(10);
    cout << b << endl;*/
}