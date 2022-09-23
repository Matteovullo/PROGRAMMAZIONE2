#ifndef BST_H
#define BST_H

#include "bst_node.h"
#include <iostream>

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

		void insert_change(BSTNode<T>* ptr, BST<T>& bst){
			T key=ptr->getKey();
				if(ptr->right == nullptr && key <= ptr->key) {
					bst.ptr->right = ptr;
					bst.ptr->right->setParent(ptr);
					return;
				}
				if(ptr->left == nullptr && key > bst.ptr->key) {
					bst.ptr->left = ptr;
					bst.ptr->left->parent = ptr;
				return;
				}
				else if(key <= bst.ptr->key)
					insert(bst.right, key);
				else
					insert(bst.left, key);		
		}
		
		void change(BSTNode<T>* ptr, BST<T>& bst){
			if(ptr == nullptr)
				return;
			
			bst.root=getRoot();
			if(ptr != root){
				insert_change(ptr, bst);
			}
			change(ptr->left, bst);
			change(ptr->right, bst);
		}
		
		BST<T> change_bst(BST<T>& bst) {
			change(root);
			return bst;
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