/*Definire una semplice classe Rettangolo.
Successivamente definire:
- Un metodo statico che prende in input una
struttura dati e permette all’utente di inserire un
numero arbitrario di oggetti di tipo rettangolo
- Un metodo statico che prende in input la struttura
definita nel punto precedente e due valori
numerici, ed elimina dalla struttura dati tutti i
rettangoli con area compresa tra i due valori
forniti dall’utent*/

#include <iostream>
using namespace std;

template <typename T>
class Node {
	T val;
	Node<T>* next;
	bool verbose;
	
	template<typename U>
	friend class List;
	
	public:
	
	Node(T val, bool verbose=false) : val(val), verbose(verbose) {
		next = nullptr;
	}
	
	Node<T>* getNext() const { return this->next; }
	
	T& getVal() {return this->val; }
	
	friend ostream& operator<<(ostream& out, const Node<T> &node) {
		if(node.verbose)
			out << "node@" << &node << " val=" << node.val << " - next=" << node.next;
		else
			out << "val=" << node.val;
		return out;
	}
};

template <typename T>
class List {
	protected:
	Node<T>* head;
	int size = 0;
	bool verbose;
	
	public:
	
	List(bool verbose=false) : verbose(verbose) {
		head = nullptr;
	}

    List() : verbose(false) {
		head = nullptr;
	}
	
	bool isEmpty() {
		return head == nullptr;
	}
	
	Node<T> *getHead() const { return head; }
	
	void insert(T val) {
		if(this->isEmpty()) {
			head = new Node<T>(val, verbose);
			size++;
			return;
		}
	}
	
	void insertHead(T val) {	
		Node<T> *temp = new Node<T>(val, verbose);
		temp->next = head;
		this->head = temp;
		size++;
	}
	
	void insertTail(T val) {
		if(this->isEmpty()) {
			this->insertHead(val);
			return;
		}
		
		Node<T> * ptr = head;
		while(ptr->getNext() != nullptr) {
			ptr = ptr->getNext();
		}
		
		Node<T> * temp = new Node<T>(val, verbose);
		ptr->next = temp;
		size++;
	}
	
	void insertInOrder(T val) {
		
		if(this->isEmpty()) {
			this->insertHead(val);
			return;
		}
		if(val <= head->val) {
			this->insertHead(val);
			return;
		}
		
		Node<T> *ptr = head;
		while(ptr->getNext() && (val >= ptr->val)) {
			
			if(val <= ptr->next->val)
				break;
			
			ptr = ptr->getNext();
		}
		
		if(!(ptr->next)) {
			this->insertTail(val);
			return;
		}
		
		Node<T> *toInsert = new Node<T>(val, verbose);
		toInsert->next = ptr->next;
		ptr->next = toInsert;
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
		
		if(head->val == val) {
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
	
	friend ostream& operator<<(ostream& out, const List<T> &list) {
		if(list.verbose) {
			out << "List head=" << list.head << endl;
			Node<T> *ptr = list.head;
			while(ptr != nullptr) {
				out << "\t" << *ptr << endl;
				ptr = ptr->getNext();
			}
		}
		else {
			Node<T> *ptr = list.head;
			while(ptr->getNext() != nullptr) {
				out << *ptr << " -> ";
				ptr = ptr->getNext();
			}
			
			out << *ptr;
		}
		
		return out;
		
	}

	template<class U>
    friend void rimozione_punti(List<T> l);
};

class Rettangolo{
    private:
        double altezza, base;

    public:
        Rettangolo(double altezza, double base) : altezza(altezza), base(base){}
        double getArea(){
        	return altezza*base;
		}
};

void inserimento_rettangolo(List<Rettangolo>& l){
    int n=0;
    cout << "Numero di oggetti?" << endl;
    cin >> n;
    bool finito=false;
    do{
        int c=0;
        for(int i=0; i<n; i++){
            int altezza, base;
            cout << "Inseire altezza: " << endl;
            cin >> altezza;
            cout << "Inserire base: " << endl;
            cin >> base;
            Rettangolo r(altezza, base);
            l.insertTail(r);
            c++;
            if(c==n) finito=true;
        }
    }while(!finito);
}

template<class T>
void rimozione_punti(List<Rettangolo>& l, double a, double b){
    	Node<Rettangolo> * ptr = l.head;
		while(ptr){
			if(ptr->Rettangolo::getArea() >= a && ptr->Rettangolo::getArea() <= b){
				l.remove(ptr->Rettangolo::getArea());
			}
			ptr = ptr->getNext();
		}
}

int main(){
    List<Rettangolo> l;
    inserimento_rettangolo(l);
    //cout << l << endl;
    rimozione_punti(l, 10, 20);
}