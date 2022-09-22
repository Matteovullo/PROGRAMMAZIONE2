#ifndef BST_H
#define BST_H

#include <iostream>
#include "bst_node.h"

template<typename T>
class BST {
	BSTNode<T>* root;
	
	public:
	
	BST() {
		root = nullptr;
	}
	
	bool isEmpty() {
		return root == nullptr;
	}
	
	BSTNode<T>* getRoot() {
		return this->root;
	}
	
	void insert(T key) {
		if(this->isEmpty()) {
			root = new BSTNode<T>(key);
			return;
		}
		insert(root, key);
	}
	
	//la mia procedura ricorsiva deve avere due parametri:
	//il valore da inserire e la radice del sottoalbero 
	
	void insert(BSTNode<T>* ptr, T key) {
		if(ptr->left == nullptr && key <= ptr->key) {
			ptr->left = new BSTNode<T>(key);
			ptr->left->setParent(ptr);
			return;
		}
		if(ptr->right == nullptr && key > ptr->key) {
			ptr->right = new BSTNode<T>(key);
			ptr->right->parent = ptr;
			return;
		}
		else if(key <= ptr->key)
			insert(ptr->left, key);
		else
			insert(ptr->right, key);
	}
	
	void visit(BSTNode<T>* node) {
		std::cout << *node << std::endl;
	}
	
	void inorder(BSTNode<T>* ptr) {
		if(ptr == nullptr)
			return;
		
		inorder(ptr->left);
		visit(ptr);
		inorder(ptr->right);
	}
	
	void inorder() {
		inorder(root);
	}
	
	//IMPLEMENTARE PREORDER E POSTORDER
	
	BSTNode<T>* min() {
		return min(root);
	}
	
	BSTNode<T>* min(BSTNode<T>* from) {
		if(isEmpty()) {
			return NULL;
		}
		
		BSTNode<T>* ptr = from;
		while(ptr->left) {
			ptr = ptr->left;
		}
		
		return ptr;
	}
	
	BSTNode<T>* max() {
		return max(root);
	}
	
	BSTNode<T>* max(BSTNode<T>* from) {
		if(isEmpty()) {
			throw "Empty BST!";
		}
		
		BSTNode<T>* ptr = from;
		while(ptr->right) {
			ptr = ptr->right;
		}
		
		return ptr;
	}
	
	BSTNode<T>* successor(BSTNode<T>* x) {
		if(this->isEmpty()) {
			return nullptr;
		}
		
		// 1. x ha un sottoalbero destro
		
		if(x->right) 
			return this->min(x->right);
		
		// 2. x non ha un sottoalbero destro
		// il successore di x è l'antenato più prossimo di x
		// il cui figlio sinistro è anche un antenato di x
		
		BSTNode<T>* y = x->parent;
		
		while(x != nullptr && x == y->right) {
			x = y;
			y = y->parent;
		}
		
		return y;
		
	}
	
	BSTNode<T>* search(T key) {
		return search(root, key);
	}
	
	BSTNode<T>* search(BSTNode<T>* ptr, T key) {
		if(ptr == nullptr) 
			return nullptr;
		if(ptr->key == key)
			return ptr;
		
		if(key <= ptr->key)
			return search(ptr->left, key);
		else
			return search(ptr->right, key);
		
		return nullptr;
	}
	
	BSTNode<T>* remove(BSTNode<T>* node) {
		//CASO 1
		//il nodo è una foglia
		if(node->left == nullptr && node->right == nullptr) {
			if(node == node->parent->left)
				node->parent->left = nullptr;
			else if (node == node->parent->right)
				node->parent->right = nullptr;
			
			return node;
		}
		
		//CASO 2
		//il nodo da eliminare ha solo un figlio destro
		if(node->left == nullptr && node->right != nullptr) {
			node->right->parent = node->parent;
			
			//il nodo da eliminare è figlio sx
			if(node == node->parent->left) {
				node->parent->left = node->right;
			}
			//il nodo da eliminare è figlio dx
			else if(node == node->parent->right) {
				node->parent->right = node->right;
			}
			return node;
		}
		
		//il nodo da eliminare ha solo un figlio sinistro
		if(node->left != nullptr && node->right == nullptr) {
			node->left->parent = node->parent;
			
			//il nodo da eliminare è figlio sx
			if(node == node->parent->left) {
				node->parent->left = node->left;
			}
			//il nodo da eliminare è figlio dx
			else if(node == node->parent->right) {
				node->parent->right = node->left;
			}
			return node;
		}
		
		return nullptr;
	}
	
	BSTNode<T>* remove(T key) {
		if(this->isEmpty()) {
			return nullptr;
		}
		
		BSTNode<T>* node = this->search(key);
		if(node == nullptr)
			return nullptr;
		
		BSTNode<T>* toDelete = this->remove(node);
		
		if(toDelete != nullptr)
			return toDelete;
		
		//CASO 3
		//il nodo da eliminare ha due figli
		//sostituiamo la chiave nel nodo da eliminare con la chiave del suo successore
		BSTNode<T>* next = this->successor(node);
		//sostituzione della chiave
		T swap = node->key;
		node->key = next ->key;
		next->key = swap;
		
		//richiamo la procedura di cancellazione (casi 1 e 2) sul successore
		toDelete = this->remove(next);
		
		return toDelete;
	}

		void cancel_below(BSTNode<T>* ptr, int eta){
	        if(ptr->key < eta)
	            remove(ptr->key);
	    }
		
	    void remove_below(BSTNode<T>* ptr, int eta){
	        if(!ptr)
	            return;

	        remove_below(ptr->right, eta);
	        cancel_below(ptr, eta);
	        remove_below(ptr->left, eta);
	    }

	    void remove_below(int cilindrata){remove_below(root, cilindrata);}

		void calcolo_media_studenti(BSTNode<T>* ptr, int& media, int& c){
			if(ptr->getKey() >= 5 && ptr->getKey() <= 30){
				media+=ptr->getKey();
				c++;
			}
		}

		void valore_medio_studenti(BSTNode<T>* ptr, int& media, int& c){
			if(!ptr) return;

			valore_medio_studenti(ptr->left, media, c);
			calcolo_media_studenti(ptr, media, c);
			valore_medio_studenti(ptr->right, media, c);
		}

		double getMediaStudenti(){
			int m=0;
			int count=0;
			valore_medio_studenti(root, m, count);
			return m/(double)count;
		}

		void calcolo_media_lavoratori(BSTNode<T>* ptr, int& media, int& c){
			if(ptr->getKey() >= 20 && ptr->getKey() <= 70){
				media+=ptr->getKey();
				c++;
			}
		}

		void valore_medio_lavoratori(BSTNode<T>* ptr, int& media, int& c){
			if(!ptr) return;

			valore_medio_lavoratori(ptr->left, media, c);
			calcolo_media_lavoratori(ptr, media, c);
			valore_medio_lavoratori(ptr->right, media, c);
		}

		double getMediaLavoratori(){
			int m=0;
			int count=0;
			valore_medio_lavoratori(root, m, count);
			return m/(double)count;
		}

		void calcolo_media_pensionati(BSTNode<T>* ptr, int& media, int& c){
			if(ptr->getKey() >= 65 && ptr->getKey() <= 95){
				media+=ptr->getKey();
				c++;
			}
		}

		void valore_medio_pensionati(BSTNode<T>* ptr, int& media, int& c){
			if(!ptr) return;

			valore_medio_pensionati(ptr->left, media, c);
			calcolo_media_pensionati(ptr, media, c);
			valore_medio_pensionati(ptr->right, media, c);
		}

		double getMediaPensionati(){
			int m=0;
			int count=0;
			valore_medio_pensionati(root, m, count);
			return m/(double)count;
		}		

		friend ostream& operator<< (ostream& os, BST<T>& bst){

			if(bst.isEmpty())
				return os << "\nEmpty BST!" << endl;

			os << "\nBST: " << endl;
			bst.inorder();
			return os;
		}
	
};
#endif