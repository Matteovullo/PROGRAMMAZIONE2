#include <iostream>
using namespace std;

#include "bst.h"

int main(){
    BST<int> bst;
    bst.insert(10);
    bst.insert(15);
    bst.insert(5);
    bst.insert(6);
    bst.insert(20);

    bst.visita(6);
}