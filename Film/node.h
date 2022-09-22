#ifndef NODO
#define NODO

#include <iostream>
using namespace std;

#include "Film.h"

class Node{
    private:
        Film f;
        Node* next;

    friend class List;
        
    public:
        Node(Film f) : f(f), next(nullptr){}
        friend ostream& operator<<(ostream& os, Node& n){
            os << n.f << endl;
            return os;
        }
};

#endif