#ifndef DLLIST
#define DLLIST

#include "dlnode.h"

template<typename T>
class DLList {
	
	protected:
	
	DLNode<T> *head;
	DLNode<T> *tail;
	
	public:
	
	DLList() {
		head = nullptr;
		tail = nullptr;
	}

	DLNode<T>*getHead(){
		if(isEmpty()) return nullptr;

		return head;
	}
	
	bool isEmpty() {
		return (head == nullptr) && (tail == nullptr);
	}
	
	void insertHead(T val) {
		if(this->isEmpty()) {
			head = new DLNode<T>(val);
			tail = head;
			return;
		}
		
		DLNode<T> *toInsert = new DLNode<T>(val);
		toInsert->next = head;
		head->prev = toInsert;
		head = toInsert;
	}
	
	void insertTail(T val) {
		if(this->isEmpty()) {
			this->insertHead(val);
			return;
		}
		
		DLNode<T> *toInsert = new DLNode<T>(val);
		toInsert->prev = tail;
		tail->next = toInsert;
		tail = toInsert;
	}
	
	void removeHead() {
		if(this->isEmpty()) {
			std::cout << "Empty list" << std::endl;
			return;
		}
		
		if(head == tail) {
			DLNode<T> *ptr = head;
			head = nullptr;
			tail = nullptr;
			delete ptr;	
			return;
		}
		
		DLNode<T> *ptr = head;
		ptr->next->prev = nullptr;
		head = ptr->next; //head->next
		
		delete ptr;
	}
	
	void removeTail() {
		if(this->isEmpty()) {
			std::cout << "Empty list" << std::endl;
			return;
		}
		
		if(head == tail) {
			DLNode<T> *ptr = head;
			head = nullptr;
			tail = nullptr;
			delete ptr;			
		}
		
		DLNode<T> *ptr = tail;
		ptr->prev->next = nullptr;
		tail = ptr->prev; //tail->prev
		
		delete ptr;
	}
	
	void remove(T val){
		if(this->isEmpty()) {
			std::cout << "Empty list" << std::endl;
			return;
		}

		DLNode<T>* ptr=head;
		while(ptr){
			if(ptr->getVal() == val) break;
			ptr=ptr->getNext();
		}

		if(!ptr) return;

		if(ptr == head){
			removeHead();
			return;
		}
		if(ptr == tail){
			removeTail();
			return;
		}

		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
	}

	friend ostream& operator<<(ostream& os, DLList<T>& dl){
		if(dl.isEmpty()) os << "Empty double linked list!" << endl;
		DLNode<T>* ptr=dl.head;
		while(ptr){
			os << *ptr << endl;
			ptr=ptr->getNext();
		}
		return os;
	}
};

#endif