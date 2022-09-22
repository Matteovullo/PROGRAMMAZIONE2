#ifndef LIST
#define LIST

#include <iostream>
using namespace std;

class Node{
    private:
        Giocatore val;
        Node* next;

    public:
        Node(Giocatore val) : val(val), next(nullptr){}
        Node* get_next(){return next;}
        Giocatore get_giocatore(){return val;}
        friend ostream& operator<<(ostream& os, Node& n){
            os << "val = " << n.val << ", next = " << n.next;
            return os;
        }
        friend class List;
};

class List{
    private:
        Node* head;
        int dim=0;

    public:
        List() : head(nullptr){}
        bool isEmpty(){return head==nullptr;}
        void insertHead(Giocatore val) {	
            Node*temp = new Node(val);
            temp->next = head;
            this->head = temp;
            dim++;
        }
        void insertTail(Giocatore val) {
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
            dim++;
        }

        void crescente(){
            if(isEmpty()) return;            
            Giocatore array[dim];
            Node* ptr=head;
            for(int i=0; i<dim; i++){
                if(ptr){
                    array[i]=ptr->get_giocatore();
                    ptr=ptr->get_next();
                }
            }
            Giocatore temp;
            int j;
            
            for(int i=1; i < dim; i++) {
                temp = array[i];
                for(j=i; j > 0; j--) {
                    if(temp < array[j-1])
                        array[j] = array[j-1];
                    else 
                        break;
                }
                array[j] = temp;
            }

            for(int i=0; i<dim; i++){
                cout << array[i] << endl;
            }
        }

        void decrescente(){
            if(isEmpty()) return;
            Giocatore array[dim];
            Node* ptr=head;
            for(int i=0; i<dim; i++){
                if(ptr){
                    array[i]=ptr->get_giocatore();
                    ptr=ptr->get_next();
                }
            }
            Giocatore temp;
            int j;
            
            for(int i=1; i < dim; i++) {
                temp = array[i];
                for(j=i; j > 0; j--) {
                    if(temp > array[j-1])
                        array[j] = array[j-1];
                    else 
                        break;
                }
                array[j] = temp;
            }
            for(int i=0; i<dim; i++){
                cout << array[i] << endl;
            }            
        }
		static void get_info (List& l, string key){

			bool found = false;

			Node* tmp = l.head;
			while(tmp->next)
			{
				if(tmp->val.get_cognome() == key)
				{	
					found = true;
					break;
					cout << *tmp << endl;
				}

				tmp = tmp->next;
			}

			if(!found)
			{
				cerr << "Void list or Element with key " << key << " not found!" << endl;
				return;
			}
			else
				cout << *tmp << endl;

			cout << "Others players with same score are: " << endl;

			Node* ptr = l.head;  
			while(ptr->next)
			{
				if (ptr->val.get_punteggio() == tmp->val.get_punteggio())
				{
					if(ptr != tmp)
						cout << *ptr << endl;
				}

				ptr = ptr->next;
			}

			return;
		}
        void removeHead() {
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }
            
            Node *temp = head;
            head = head->next;
            
            dim--;
            
            delete temp;
        }
        
        void removeTail() {
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }
            
            Node *cur = head;
            Node *prev = nullptr;
            while(cur->next) {
                prev = cur;
                cur = cur->next;			
            }
            
            prev->next = nullptr;
            dim--;
            delete cur;
        }
        
        void remove(Giocatore val) {
            
            if(this->isEmpty()) {
                cout << "Empty list!" << endl;
                return;
            }
            
            if(head->val == val) {
                this->removeHead();
                return;
            }
            
            Node *cur = head;
            Node *prev = nullptr;
            while(cur->next && cur->val != val) {
                prev = cur;
                cur = cur->next;
            }
            
            if(!(cur->next) && cur->val != val) {
                cout << "Element with value " << val << "not found" << endl;
                return;
            }
            
            prev->next = cur->next;
            dim--;
            delete cur;
        }
		void remove_player(List& l, double key){

			if(isEmpty())
			{
				cerr << "\nVoid list, impossible find element with key " << key << " !" << endl;
				return;
			}

			Node* cur = head;
			bool found = true;

			while(cur->next)
			{
				if(cur->val.get_punteggio() == key)
					remove(cur->val);

				cur = cur->next;
			}

			if(cur->val.get_punteggio() != key) 
				cerr << "\nElement with key " << key << " not found!" << endl;

			return;	
		}        
        friend ostream& operator<<(ostream& os, List& l){
            if(l.isEmpty()) os << "Lista vuota" << endl;
            os << "dim =" << l.dim << endl;
            Node* ptr=l.head;
            while(ptr->get_next()){
                cout << *ptr << endl;
                ptr=ptr->get_next();
            }
            return os;
        }
};

#endif