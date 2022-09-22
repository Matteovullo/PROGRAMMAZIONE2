#ifndef LIST
#define LIST

#include<iostream>
using namespace std;

#include "node.h"

class List{
    private:
        Node* head;

    public:
        List() : head(nullptr){}
        bool isEmpty(){
            return head == nullptr;
        }
        void insert(Film f){
            if(isEmpty()) return;

            if(!head){
                head=new Node(f);
                return;
            }else{
                Node* ptr=head;
                while(ptr){
                    ptr=ptr->next;
                }
                ptr->next=new Node(f);
                return;
            }
        }
        friend ostream& operator<<(ostream& os, List& l){
            Node* ptr=l.head;
            while(ptr){
                os << *ptr << endl;
                ptr=ptr->l.next;
            }
            return os;
        }
};

#endif