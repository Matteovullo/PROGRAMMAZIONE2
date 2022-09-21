/*pila per tipi generici*/

#include <iostream>
#include "list.h"

using namespace std;

template<class T>
class Pila : protected List<T>{
    private:
        int dim=0;

    public:
        Pila() : List<T>(){}
        Node<T>* cima(){
            if(vuota()) return nullptr;

            return List<T>::getHead();
        }
        bool vuota(){
            return dim==0;
        }
        int getDim(){return dim;}
        void push(T val){
            List<T>::insertHead(val);
            dim++;
        }
        void pop(){
            if(vuota()) return;

            List<T>::removeHead();
            dim--;
        }
        friend ostream& operator<<(ostream& os, Pila<T> p){
            return os << (List<T>)p;
        }
};

int main(){
    Pila<int> p;
    p.push(1);
    p.push(5);
    cout << p << endl;
    cout << *p.cima() << endl;
    p.pop();
    cout << p << endl;
    cout << p.getDim() << endl;
}