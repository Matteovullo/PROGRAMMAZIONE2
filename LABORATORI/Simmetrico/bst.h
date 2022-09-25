#ifndef BST_H
#define BST_H

#include "bst_node.h"
#include "dllist.h"
#include "queue.h"
#include <iostream>

template<typename T>
class BST {
	BSTNode<T>* root;
	Queue<T> nodes;
	
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

		/*void cancel_below(BSTNode<T>* ptr, int cilindrata){
	        if(ptr->key->getCilindrata() <= cilindrata)
	            remove(ptr->key);
	    }
		
	    void remove_below(BSTNode<T>* ptr, int cilindrata){
	        if(!ptr)
	            return;

	        remove_below(ptr->right, cilindrata);
	        cancel_below(ptr, cilindrata);
	        remove_below(ptr->left, cilindrata);
	    }

	    void remove_below(int cilindrata){remove_below(root, cilindrata);}

		void insert_invertito(BSTNode<T> *ptr, T key, BST<T>& bst){
				if(bst.ptr->right == nullptr && key <= bst.ptr->key) {
					bst.ptr->right = new BSTNode<T>(key);
					bst.ptr->right->setParent(ptr);
					return;
				}
				if(bst.ptr->left == nullptr && key > bst.ptr->key) {
					bst.ptr->left = new BSTNode<T>(key);
					bst.ptr->left->parent = ptr;
				return;
				}
				else if(key <= bst.ptr->key)
					insert(bst.ptr->right, key);
				else
					insert(bst.ptr->left, key);				
		}

		void change(BSTNode<T>* ptr, BST<T>& bst) {
			if(ptr){
				bst.insert_invertito(ptr, ptr->getKey(), bst);
			}
		}
		
		void change_ptr(BSTNode<T>* ptr, BST<T>& bst){
			if(ptr == nullptr)
				return;
			
			change_ptr(ptr->left, bst);
			change(ptr, bst);
			change_ptr(ptr->right, bst);
		}
		
		void change_root(BST<T>& bst) {
			change_ptr(root, bst);
		}

		BST<T> simmetrico(BST<T>& bst){
			if(isEmpty()) return bst;
			change_root(bst);
			return bst;
		}*/
		/*
		void setRight(BSTNode<T>* ptr){
			ptr->setRight(ptr);
		}
		void setLeft(BSTNode<T>* ptr){
			ptr->setLeft(ptr);
		}
		void setParent(BSTNode<T>* ptr){
			ptr->setParent(ptr);
		}
		BSTNode<T>* getRight(BSTNode<T>* ptr){
			return ptr->getRight();
		}
		BSTNode<T>* getLeft(BSTNode<T>* ptr){
			return ptr->getLeft();
		}
		void insert_change(BSTNode<T>* ptr, BSTNode<T>* p, BST<T>& bst){
			if(!ptr) return;
				if(p->right == nullptr && ptr->getKey() <= p->getKey()) {
					bst.setRight(ptr);
					bst.setParent(ptr);
					return;
				}
				if(p->left == nullptr && ptr->getKey() > p->getKey()) {
					bst.setLeft(ptr);
					bst.setParent(ptr);
					return;
				}
				else if(ptr->getKey() <= p->getKey())
					insert_change(bst.getRight(ptr), p, bst);
				else
					insert_change(bst.getLeft(ptr), p,  bst);		
		}
		
		void change(BSTNode<T>* ptr, BSTNode<T>* p, BST<T>& bst){
			if(ptr == nullptr)
				return;
			
			bst.root=getRoot();
			p=ptr;
			if(ptr != root){
				insert_change(ptr, p, bst);
			}
			change(ptr->left, p->left, bst);
			change(ptr->right, p->right, bst);
		}
		
		BST<T> change_bst(BST<T>& bst) {
			change(root, bst.root, bst);
			return bst;
		}*/	

		void insert_symmetric(T key){
			if(isEmpty())
			{
				root = new BSTNode<T>(key);
				return;
			}
			insert_symmetric(root, key);
		}
		void insert_symmetric(BSTNode<T>* ptr, T key){
			if(!ptr->left && key > ptr->key)
			{
				ptr->left = new BSTNode<T>(key);
				ptr->left->setParent(ptr);
				return;
			}
			if(!ptr->right && key <= ptr->key)
			{
				ptr->right = new BSTNode<T>(key);
				ptr->right->setParent(ptr);
				return;
			}
			if(key > ptr->key)
				insert_symmetric(ptr->left, key);
			else if(key <= ptr->key)
				insert_symmetric(ptr->right, key);
		}
		BST<T>* symmetric(){
			BST<T>* toreturn = new BST<T>;
			if(nodes.isEmpty())
				throw out_of_range("..symmetric fail! Empty BST!..");

			DLNode<T>* ptr  = nodes->getHead();
			while(ptr)
			{
				toreturn->insert_symmetric(ptr->getVal());
				ptr = ptr->getNext();
			}

			return toreturn;
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