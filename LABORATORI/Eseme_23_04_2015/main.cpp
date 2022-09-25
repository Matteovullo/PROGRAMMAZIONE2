#include <iostream>
using namespace std;

#include "BST.h"

int main(){
    BST<int> b;
    b.insert(10);
    b.insert(15);
    b.insert(20);
    b.insert(1);
    b.inorder();
    cout << endl;
    cout << b.search(20) << endl;
    b.minori(15);
    cout << b.min()->getKey() << endl;
    cout << b.max()->getKey() << endl;
}