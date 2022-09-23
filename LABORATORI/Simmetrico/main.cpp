#include <iostream>
using namespace std;

#include "bst.h"

int main(){
    BST<int> bst;
    bst.insert(10);
    bst.insert(11);
    bst.insert(4);
    bst.insert(30);

    cout << bst << endl;

    BST<int> simme;
    bst.simmetrico(simme);

    cout << simme << endl;
}