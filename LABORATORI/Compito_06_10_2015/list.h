#ifndef LIST
#define LIST

#include <iostream>
using namespace std;

template<typename T>
class Node{
    private:
        T val;
        Node<T>* next;

    public:
        Node(T val) : val(val), next(nullptr){}
        Node<T>* getNext(){return next;}
        T getVal(){return val;}
        friend ostream& operator<<(ostream& os, Node<T>& n){
            os << "Valore = " << n.val << ", next = " << n.next << endl;
            return os;
        }

    template<typename Y>
    friend class List;
};

template<typename T>
class List{
    private:
        Node<T>* head;
        int size=0;

    public:
        //punto 1
        List() :  head(nullptr){}
        bool isEmpty(){return head == nullptr;}
        void insertHead(T val){
            Node<T>* temp=new Node<T>(val);
            temp->next=head;
            head=temp;
            size++;
        }
        //punto 2
        void insertTail(T val){
            if(isEmpty()){
                insertHead(val);
                return;
            }

            Node<T>* ptr=head;
            while(ptr->getNext() != nullptr){
                ptr=ptr->getNext();
            }

            Node<T>* temp=new Node<T>(val);
            ptr->next=temp;
            size++;
        }
        void insert(T val){
            if(isEmpty()){
                insertHead(val);
                return;
            }
            if(val <= head->val){
                insertHead(val);
                return;
            }

            Node<T>* ptr=head;
            while(ptr->getNext() && (val >= ptr->val)){
                if(val <= ptr->next->val){
                    break;
                }
                ptr=ptr->getNext();
            }

            if(!(ptr->next)){
                insertTail(val);
                return;
            }

            Node<T> *toInsert = new Node<T>(val);
            toInsert->next=ptr->next;
            ptr->next=toInsert;
            size++;
        }
        void removeHead() {
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }
            
            Node<T> *temp = head;
            head = head->next;
            
            size--;
            
            delete temp;
        }
        
        void removeTail() {
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }
            
            Node<T> *cur = head;
            Node<T> *prev = nullptr;
            while(cur->next) {
                prev = cur;
                cur = cur->next;			
            }
            
            prev->next = nullptr;
            size--;
            delete cur;
        }
        
        void remove(T val) {
            
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }
            
            if(head->getVal() == val) {
                this->removeHead();
                return;
            }
            
            Node<T> *cur = head;
            Node<T> *prev = nullptr;
            while(cur->next && cur->val != val) {
                prev = cur;
                cur = cur->next;
            }
            
            if(!(cur->next) && cur->val != val) {
                cout << "Element with value " << val << "not found" << endl;
                return;
            }
            
            prev->next = cur->next;
            size--;
            delete cur;
        }
        //punto 4
        void visualizza_maggiori(int n){
            if(isEmpty()) return;

            Node<T>* ptr=head;
            while(ptr){
                if(ptr->getVal().getCapienza() >= n){
                    cout << *ptr << endl;
                }
                ptr=ptr->getNext();
            }
        }
        //punto 5
        void cambia(string s){
            if(isEmpty()) return;

            Node<T>* ptr=head;
            while(ptr){
                if(ptr->getVal().getNome() == s){
                    cout << "eee" <<endl;
                    ptr->getVal().setNome("Ristorante chiuso");
                    ptr->getVal().setCapienza(0);
                    ptr->getVal().setTavoli(0);
                }
                ptr=ptr->getNext();
            }
        }
        //punto 6
        void elimina(string s){
            if(isEmpty()) return;

            Node<T>* ptr=head;
            while(ptr){
                if(ptr->getVal().getNome() == s){
                    remove(ptr->getVal());
                }
                ptr=ptr->getNext();
            }
        }
        //punto 3
        friend ostream& operator<<(ostream& os, List<T>& l){
            if(l.isEmpty()) os << "Lista vuota!" << endl;

            Node<T>* ptr=l.head;
            while(ptr){
                os << *ptr << endl;
                ptr=ptr->getNext();
            }
            return os;
        }

};

#endif