#include<iostream>
using namespace std;

#include "list.h"
#include "bst.h"

int main(){
    //punto 1
    LList<int>* l = new LList<int>;
    l->ins(3)->ins(7)->ins(1)->ins(8)->ins(2)->ins(4)->print();
    l->canc(3)->canc(9)->canc(5)->canc(1)->ins(10)->ins(5)->print();
    if(l->search(5)) cout << "elemento 5 presente" << endl; else cout << "elemento 5 non presente" << endl;
    if(l->search(3)) cout << "elemento 3 presente" << endl; else cout << "elemento 3 non presente" << endl;

    cout << endl << endl << endl;

    //punto 2
    BST<int>* t = new BST<int>;
    t->ins(3)->ins(7)->ins(1)->ins(8)->ins(2)->ins(4)->print();
    t->canc(3)->canc(9)->canc(5)->canc(1)->ins(10)->ins(5)->print();
    if(l->search(5)) cout << "elemento 5 presente" << endl; else cout << "elemento 5 non presente" << endl;
    if(l->search(3)) cout << "elemento 3 presente" << endl; else cout << "elemento 3 non presente" << endl;
    int *r = t->minimum();
    if(r) cout << "il valore pi`u piccolo `e " << *r << endl;
    if(r=t->successor(5)) cout << "il successore di 5 `e " << *r << endl;
    //r=t->successor(3);
    //if(r) cout << "il successore di 3 `e " << *r << endl;

    //punto 3
    
}