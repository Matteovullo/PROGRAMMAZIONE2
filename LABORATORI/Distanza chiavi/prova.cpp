#include <iostream>
using namespace std;

#include "bst.h"

int main(){
    BST<int> b;
    b.insert(6);
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(13);
    b.insert(22); 
    b.insert(7);
    cout << b << endl;
    cout << b.distanzaChiavi(6, 5) << endl;
    cout << b.distanzaChiavi(5, 6) << endl;
    cout << b.distanzaChiavi(7, 15) << endl; 
    cout << b.distanzaChiavi(15, 7) << endl;
    cout << b.distanzaChiavi(22, 13) << endl;
    cout << b.distanzaChiavi(13, 22) << endl;
    cout << b.distanzaChiavi(15, 10) << endl;
    cout << b.distanzaChiavi(10, 15) << endl;
    cout << b.distanzaChiavi(7, 22) << endl;
    cout << b.distanzaChiavi(22, 7) << endl;
}