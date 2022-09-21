/* pila dinamica per tipi generici*/

#include <iostream>
#include "List.h"
using namespace std;

template<typename T>
class Pila : protected List<T>{
    private:
        int dim=0;

    public:
        Pila() : List<T>(){}
        bool vuoto(){
            return dim == 0; 
        }
        void push(T val){
            List<T>::insertHead(val);
            dim++;
        }
        void pop(){
            if(vuoto()) return;
            List<T>::removeHead();
            dim--;
        }
        Node<T>* top(){
            if(vuoto()) return nullptr;
            else return List<T>::getHead();
        }
        friend ostream& operator<<(ostream& os, Pila<T> p){
            return os << (List<T>)p;
        }
};

int main(){
    Pila<int> p;
    p.push(1);
    p.push(2);
    p.push(3);
    cout << p << endl;
    p.pop();
    cout << p << endl;
    cout << *p.top() << endl;
}