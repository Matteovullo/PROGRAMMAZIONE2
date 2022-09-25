#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>
#include "list.h"

template<typename H>
class BSTNode {
	protected:
	
	H key;
	BSTNode<H>* left;
	BSTNode<H>* right;
	BSTNode<H>* parent;
	bool verbose = false;
	
	template<typename U>
	friend class BST;
	
	public: 
	
	BSTNode(H key, bool verbose=true) : key(key), verbose(verbose) {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	
	void setLeft(BSTNode<H>* left) {
		this->left = left;
	}
	
	void setRight(BSTNode<H>* right) {
		this->right = right;
	}
	
	void setParent(BSTNode<H>* parent) {
		this->parent = parent;
	}
	
	BSTNode<H>* getLeft() {
		return this->left;
	}
	
	BSTNode<H>* getRight() {
		return this->right;
	}
	
	BSTNode<H>* getParent() {
		return this->parent;
	}
	
	void setKey(H key) {
		this->key = key;
	}
	
	H getKey() {
		return this->key;
	}

    H* getPtr(){
        H* ptr;
        ptr=&key;
        return ptr;
    }
	
	friend std::ostream& operator<<(std::ostream& out, BSTNode<H>& node) {
		if(node.verbose)
			out << "BSTNode@" << &node << " key=" << node.key << " - left=" << node.left << " right=" << node.right << " parent=" << node.parent;
		else
			out << "BSTNode key=" << node.key;
		return out;
	}
};

template<typename H>
class BST{
    private:
        BSTNode<H>* root;
        LList<H> l;
        LList<int> ll;
	
	public:
        BST() {
            root = nullptr;
        }
        
        bool isEmpty() {
            return root == nullptr;
        }
        
        BSTNode<H>* getRoot() {
            return this->root;
        }

    public:
        BST<H>* ins(H key) {
            if(this->isEmpty()) {
                root = new BSTNode<H>(key);
                l.ins(key);
                return this;
            }
            insert(root, key);
            return this;
        }
        
        //la mia procedura ricorsiva deve avere due parametri:
        //il valore da inserire e la radice del sottoalbero 
        
        void insert(BSTNode<H>* ptr, H key) {
            if(ptr->left == nullptr && key <= ptr->key) {
                ptr->left = new BSTNode<H>(key);
                ptr->left->setParent(ptr);
                l.ins(key);
                return;
            }
            if(ptr->right == nullptr && key > ptr->key) {
                ptr->right = new BSTNode<H>(key);
                ptr->right->parent = ptr;
                l.ins(key);
                return;
            }
            else if(key <= ptr->key)
                insert(ptr->left, key);
            else
                insert(ptr->right, key);
        }   

        BSTNode<H>* search(H key) {
            return search(root, key);
        }
        
        BSTNode<H>* search(BSTNode<H>* ptr, H key) {
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

		BSTNode<H>* remove(BSTNode<H>* node) {
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
            l.canc(node->getKey());
			
			return nullptr;
		}
		
		BST<H>* canc(H key) {
			if(this->isEmpty()) {
				return this;
			}
			
			BSTNode<H>* node = this->search(key);
			if(node == nullptr)
				return this;
			
			BSTNode<H>* toDelete = this->remove(node);
			
			if(toDelete != nullptr)
				return this;
			
			//CASO 3
			//il nodo da eliminare ha due figli
			//sostituiamo la chiave nel nodo da eliminare con la chiave del suo successore
			BSTNode<H>* next = this->successor_R(node);
			//sostituzione della chiave
			H swap = node->key;
			node->key = next ->key;
			next->key = swap;
			
			//richiamo la procedura di cancellazione (casi 1 e 2) sul successore
			toDelete = this->remove(next);
			
			return this;
		}     

        H* minimum() {
            return minimum(root);
        }
        
        H* minimum(BSTNode<H>* from) {
            if(isEmpty()) {
                return NULL;
            }
            
            BSTNode<H>* ptr = from;
            while(ptr->left) {
                ptr = ptr->left;
            }
            
            return ptr->getPtr();
        }

        BSTNode<H>* successor_R(BSTNode<H>* x) {
            if(this->isEmpty()) {
                return nullptr;
            }
            
            // 1. x ha un sottoalbero destro
            
            if(x->right) 
                return this->min(x->right);
            
            // 2. x non ha un sottoalbero destro
            // il successore di x è l'antenato più prossimo di x
            // il cui figlio sinistro è anche un antenato di x
            
            BSTNode<H>* y = x->parent;
            
            while(x != nullptr && x == y->right) {
                x = y;
                y = y->parent;
            }
            
            return y;
            
        }
    
        BSTNode<H>* min() {
            return min(root);
        }
        
        BSTNode<H>* min(BSTNode<H>* from) {
            if(isEmpty()) {
                return NULL;
            }
            
            BSTNode<H>* ptr = from;
            while(ptr->left) {
                ptr = ptr->left;
            }
            
            return ptr;
        }
        
        H* successor(H val) {
            if(this->isEmpty()) {
                return nullptr;
            }

            BSTNode<H>* x=search(val);
            
            // 1. x ha un sottoalbero destro
            
            if(x->right) 
                return this->minimum(x->right);
            
            // 2. x non ha un sottoalbero destro
            // il successore di x è l'antenato più prossimo di x
            // il cui figlio sinistro è anche un antenato di x
            
            BSTNode<H>* y = x->parent;
            
            while(x != nullptr && x == y->right) {
                x = y;
                y = y->parent;
            }
            
            return y->getPtr();
            
        }
        void print(){
            l.print();
        }
        int profondita(BSTNode<H>* u){
            int p=0;
            BSTNode<H>* ptr=u;
            while(ptr->parent != nullptr) {
                p++;
                ptr=ptr->parent;
            }
            return p;
        }
        int altezza(BSTNode<H>* ptr){
            if(ptr == nullptr){
                if(ll.getTail())  return ll.getTail()->getVal();
                else return 0;
            }
            altezza(ptr->left);
            ll.ins(profondita(ptr));
            altezza(ptr->right);
            if (ll.getTail()) return ll.getTail()->getVal();
            else return 0;
        }
        int altezza(){
            return altezza(root);
        }
        void printll(){
            ll.print();
        }
        void visit(BSTNode<H>* node) {
            std::cout << *node << std::endl;
        }
        
        void inorder(BSTNode<H>* ptr) {
            if(ptr == nullptr)
                return;
            
            inorder(ptr->left);
            visit(ptr);
            inorder(ptr->right);
        }
        
        void inorder() {
            inorder(root);
        }
};

#endif