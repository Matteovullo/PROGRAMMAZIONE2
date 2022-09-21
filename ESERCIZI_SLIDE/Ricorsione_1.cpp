/*1. Sommare gli elementi di una lista*/

#include <iostream>
#include "list.h"
using namespace std;

/*template<typename T>
T somma_ricorsiva(T v[], int dim){
    if(dim==1)
        return v[0];
    else
        return v[dim-1]+somma_ricorsiva(v[dim], dim-2);
}*/

int somma_ricorsiva(int v[],int dim){
    if(dim == 1){
        return v[0];
    }else{
        return v[dim-1]+somma_ricorsiva(v, dim-1);
    }
}

template<typename T>
T somma_lista(List<T> l){
    T somma=0;
    if(l.isEmpty()) return -1;
    else{
        Node<T> *ptr = l.getHead();
		while(ptr != nullptr) {
            somma+=ptr->getVal();
			ptr = ptr->getNext();
		}
        return somma;
    }
}

int main(){
    int array[9]={1, 2, 3, 4, 5, 1, 1, 1, 1};
    cout << somma_ricorsiva(array, 9) << endl;

    List<int> l;
    cout << somma_lista<int>(l) << endl;
    l.insert(1);
    l.insertTail(2);
    l.insertTail(10);
    cout << l << endl;
    cout << somma_lista<int>(l) << endl;
}