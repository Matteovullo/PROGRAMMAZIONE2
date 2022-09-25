#include<iostream>
using namespace std;

#include "list.h"
#include "bst.h"

int main(){
    BST<int>* t = new BST<int>;
    t->ins(3)->ins(7)->ins(1)->ins(8)->ins(2)->ins(4)->print();
    cout << t->altezza() << endl;
    t->printll();
}