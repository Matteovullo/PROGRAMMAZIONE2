#ifndef LIST
#define LIST

#include<iostream>
using namespace std;

template<typename H>
class Node{
    private:
        Node<H>* next;
        H val;

    public:
        Node(H val) : next(nullptr), val(val){}
        Node<H>* getNext() const {return next;}
        H getVal(){return val;}
        H* getPtr(){
            H* ptr;
            ptr=&val;
            return ptr;
        }

    template<typename Y>
    friend class LList;
};

template<typename H>
class LList{
    private:
        Node<H>* head;

    public:
        LList() : head(nullptr){}
        bool isEmpty(){return head == nullptr;}
        void insertHead(H val) {	
            Node<H> *temp = new Node<H>(val);
            temp->next = head;
            this->head = temp;
        }
        void insertTail(H val) {
            if(this->isEmpty()) {
                this->insertHead(val);
                return;
            }
            
            Node<H> * ptr = head;
            while(ptr->getNext() != nullptr) {
                ptr = ptr->getNext();
            }
            
            Node<H> * temp = new Node<H>(val);
            ptr->next = temp;
        }
        /*void insertTail(H val){
            if(isEmpty()) return;
            Node<H>* ptr=head;
            while(ptr->getNext()){
                ptr=ptr->getNext();
            }
            ptr=new Node<H>(val);
        }*/
        /*LList<H>* ins(H val){
            if(isEmpty()){
                head = new Node<H>(val);
                return this;
            }else{
                insertTail(val);
            }
            return this;
        }*/
        LList<H>* ins(H val) {
            if(this->isEmpty()) {
                this->insertHead(val);
                return this;
            }
            if(val <= head->val) {
                this->insertHead(val);
                return this;
            }
            
            Node<H> *ptr = head;
            while(ptr->getNext() && (val >= ptr->val)) {
                
                if(val <= ptr->next->val)
                    break;
                    ptr = ptr->getNext();
                }
                
                if(!(ptr->next)) {
                    this->insertTail(val);
                    return this;
                }
                
                Node<H> *toInsert = new Node<H>(val);
                toInsert->next = ptr->next;
                ptr->next = toInsert;
                return this;	
	    }
        void removeHead() {
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }
            
            Node<H> *temp = head;
            head = head->next;		
            delete temp;
        }
        
        void removeTail() {
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }
            
            Node<H> *cur = head;
            Node<H> *prev = nullptr;
            while(cur->next) {
                prev = cur;
                cur = cur->next;			
            }
            
            prev->next = nullptr;
            delete cur;
        }
        LList<H>* canc(H val) {
            
            if(this->isEmpty()) {
                //cout << "Empty list!" << endl;
                return this;
            }
            
            if(head->val == val) {
                this->removeHead();
                return this;
            }
            
            Node<H> *cur = head;
            Node<H> *prev = nullptr;
            while(cur->next && cur->val != val) {
                prev = cur;
                cur = cur->next;
            }
            
            if(!(cur->next) && cur->val != val) {
                //cout << "Element with value " << val << "not found" << endl;
                return this;
            }
            
            prev->next = cur->next;
            delete cur;
            return this;
        }
        H* search(H x){
            if(isEmpty()) return nullptr;
            Node<H>* ptr=head;
            while(ptr){
                if(x == ptr->getVal()) return ptr->getPtr();
                ptr=ptr->getNext();
            }
            return nullptr;
        }
        void print(){
            if(isEmpty()) return;
            Node<H>* ptr=head;
            while(ptr){
                cout << ptr->getVal() << " " << endl;
                ptr=ptr->getNext();
            }
        }
        Node<H>* getTail(){
            if(isEmpty()) return nullptr;
            Node<H>* ptr=head;
            while(ptr->getNext()){
                ptr=ptr->getNext();
            }
            return ptr;
        }
};

#endif