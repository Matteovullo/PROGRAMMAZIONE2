/*2. Trovare il massimo in una lista*/

#include <iostream>
#include "List.h"

using namespace std;

int massimo(int v[], int dim){
    if(dim == 1){
        return v[0];
    }else{
        int max=INT_MIN;
        for(int i=0; i<dim; i++){
            if(v[i] > max){
                max = v[i];
            }
        }
        return max;
    }
}

template<typename T>
T massimo_lista(List<T> l){
    T max=INT_MIN;
    if(l.isEmpty()) return -1;
    else{
        Node<T> *ptr = l.getHead();
		while(ptr != nullptr) {
            if(max < ptr->getVal()){
                max=ptr->getVal();
            }
			ptr = ptr->getNext();
		}
        return max;
    }
}

int main(){
    int array[6]={1, 2, 3, 4, 5, 6};
    cout << massimo(array, 6);
    cout << endl;

    List<int> l;
    l.insert(1);
    l.insertTail(3);
    l.insertTail(10);
    cout << massimo_lista<int>(l) << endl;
}