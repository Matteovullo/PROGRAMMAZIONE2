#ifndef QUEUE_H
#define QUEUE_H

#include "dllist.h"
#include <iostream>
using namespace std;

template<typename T>
class Queue : protected DLList<T> {
	protected:
	int size = 0;
	
	public:
	
	Queue() : DLList<T>() {}

	DLNode<T>* getHead(){
		if(isEmpty()) return nullptr;
		return DLList<T>::getHead();
	}

	int getSize(){return size;}

	void printHead(){
		if(getHead()) cout << *getHead() << endl;
	}
	
	void rimozione(string s){
		if(isEmpty()) return;

		DLNode<T>* ptr=DLList<T>::getHead();
		while(ptr){
			if(ptr->getVal().getCodiceFiscale() == s){
				size--;
				DLList<T>::remove(ptr->getVal());
				return;
			}
			ptr=ptr->getNext();
		}
	}

	void enqueue(T val) {
		DLList<T>::insertTail(val);
		size++;
	}
	
	DLNode<T>* dequeue() {
		
		if(isEmpty())
			return 0;
		
		DLNode<T>* ptr = DLList<T>::getHead();
		DLList<T>::removeHead();
		size--;
		return ptr;
	}
	
	bool isEmpty() {
		return size == 0;
	}
	
	friend std::ostream& operator<<(std::ostream& out, Queue<T>& queue) {
		out << "Queue starting at " << &(queue.head);
		DLNode<T> *ptr = queue.head;
		while(ptr) {
			out << *ptr << std::endl;
			ptr = ptr->getNext();
		}
		return out;
	}
};

#endif