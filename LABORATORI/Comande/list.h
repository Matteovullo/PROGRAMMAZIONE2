#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"

using namespace std;

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

	void raggruppa(string cognome){
		if(isEmpty()) return;

		Node<T>* ptr=head;
		while(ptr){
			if(ptr->getVal().getCognome() == cognome){
				cout << ptr->getVal();
			}
			ptr=ptr->getNext();
		}
	}

	double cerca(string cognome){
		if(isEmpty()) return -1;
		double totale=0;
		Node<T>* ptr=head;
		while(ptr){
			if(ptr->getVal().getCognome() == cognome){
				cout << ptr->getVal().getPizza() << endl;
				totale+=ptr->getVal().getPrezzo();
			}
			ptr=ptr->getNext();
		}
		return totale;
	}

	/*double media_cliente(string cognome){
		if(isEmpty()) return -1;
		double media=0;
		int c=0;
		Node<T>* ptr=head;
		while(ptr){
			if(ptr->getVal().getCognome() == cognome){
				media+=ptr->getVal().getPrezzo();
				c++;
			}
			ptr=ptr->getNext();
		}
		return media/c;
	}

	void elimina(){
		if(isEmpty()) return;
		double media=0;
		int c=0;
		double a[59];
		Node<T>* ptr=head;
		int i=0;
		while(ptr){
			string s=ptr->getVal().getCognome();
			double d=media_cliente(s);
			a[i]=d;
			i++;
			ptr=ptr->getNext();
		}
		for(int i=0; i<59; i++){
			media+=a[i];
			c++;
		}
		while(ptr){
			if(media_cliente(ptr->getVal().getCognome()) < media/c){
				remove(ptr->getVal());
			}
			ptr=ptr->getNext();
		}		
	}*/

	double media(){
		if(isEmpty()) return -1;

		double media=0;
		int c=0;
		Node<T>* ptr=head;
		while(ptr){
			media+=ptr->getVal().getPrezzo();
			c++;
			ptr=ptr->getNext();
		}
		return media/c;

	}

	void elimina(){
		if(isEmpty()) return;
		Node<T>* ptr=head;
		while(ptr){
			if(ptr->getVal().getPrezzo() < media()){
				remove(ptr->getVal());
			}
			ptr=ptr->getNext();
		}		
	}

	void classifica(){
		if(isEmpty()) return;
		Node<T>* ptr=head;
		int i=0;
		string pizza=ptr->getVal().getPizza();
		string array[size];
		while(ptr){
			array[i]=ptr->getVal().getPizza();
			i++;
			ptr=ptr->getNext();
		}
		int pizze_max=0;
		string pizza_max="";
		for(int i=0; i<size; i++){
			string pizza=array[i];
			int pizze_attuali=0;
			for(int j=i; j<size; j++){
				if(pizza == array[j]){
					pizze_attuali++;
				}
			}
			if(pizze_attuali > pizze_max){
				pizze_max=pizze_attuali;
				pizza_max=pizza;
			}
		}
		cout << "Pizza piu richiesta è : " << pizza_max;
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
};

#endif