#ifndef LIST
#define LIST

#include<iostream>
using namespace std;

#include "node.h"

class List{
    protected:
        Node* head;

    public:
        List() : head(nullptr){}
        bool isEmpty(){
            return head == nullptr;
        }
        Film get_head(){return this->head->f;}
        void insert(Film val) {
            if(this->isEmpty()) {
                head = new Node(val);
                return;
            }
        }
        void insertHead(Film val) {	
            Node*temp = new Node(val);
            temp->next = head;
            this->head = temp;
        }
        void insertTail(Film val) {
            if(this->isEmpty()) {
                this->insertHead(val);
                return;
            }
            Node* ptr = head;
            while(ptr->get_next() != nullptr) {
                ptr = ptr->get_next();
            }
            Node* temp = new Node(val);
            ptr->next = temp;
        }
        void removeHead() {
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }
            
            Node*temp = head;
            head = head->next;
            delete temp;
        }
        
        void removeTail() {
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }
            
            Node*cur = head;
            Node*prev = nullptr;
            while(cur->next) {
                prev = cur;
                cur = cur->next;			
            }
            
            prev->next = nullptr;
            delete cur;
        }
        
        void remove(Film val) {
            
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }
            
            if(head->f == val) {
                this->removeHead();
                return;
            }
            
            Node *cur = head;
            Node *prev = nullptr;
            while(cur->next && cur->f != val) {
                prev = cur;
                cur = cur->next;
            }
            
            if(!(cur->next) && cur->f != val) {
                cout << "Element with value " << val << "not found" << endl;
                return;
            }
            
            prev->next = cur->next;
            delete cur;
        }        
        friend ostream& operator<<(ostream& os, List& l){
            Node* ptr=l.head;
            while(ptr){
                os << *ptr << endl;
                ptr=ptr->get_next();
            }
            return os;
        }
        friend class film;
};

#endif