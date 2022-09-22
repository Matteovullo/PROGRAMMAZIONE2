#ifndef NODO
#define NODO

#include <iostream>
using namespace std;

#include "Film.h"

class Node{
    private:
        Film f;
        Node* next;
        
    public:
        Node(Film f) : f(f), next(nullptr){}
        Film getFilm(){return f;}
        Node* get_next(){

			return this->next;
		}
        friend ostream& operator<<(ostream& os, Node& n){
            os << n.f << endl;
            return os;
        }
        friend class List;
};

#endif