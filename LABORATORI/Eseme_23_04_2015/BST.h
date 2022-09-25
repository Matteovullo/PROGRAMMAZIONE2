#ifndef bst
#define bst

#include<iostream>
using namespace std;

//punto A
template<typename T>
class BSTNode {
	protected:
	
	T key;
	BSTNode<T>* left;
	BSTNode<T>* right;
	BSTNode<T>* parent;
	bool verbose = false;
	
	template<typename U>
	friend class BST;
	
	public: 
	
	BSTNode(T key, bool verbose=true) : key(key), verbose(verbose) {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	
	void setLeft(BSTNode<T>* left) {
		this->left = left;
	}
	
	void setRight(BSTNode<T>* right) {
		this->right = right;
	}
	
	void setParent(BSTNode<T>* parent) {
		this->parent = parent;
	}
	
	BSTNode<T>* getLeft() {
		return this->left;
	}
	
	BSTNode<T>* getRight() {
		return this->right;
	}
	
	BSTNode<T>* getParent() {
		return this->parent;
	}
	
	void setKey(T key) {
		this->key = key;
	}
	
	T getKey() {
		return this->key;
	}
	
	friend std::ostream& operator<<(std::ostream& out, BSTNode<T>& node) {
		if(node.verbose)
			out << "BSTNode@" << &node << " key=" << node.key << " - left=" << node.left << " right=" << node.right << " parent=" << node.parent;
		else
			out << "BSTNode key=" << node.key;
		return out;
	}
};

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

    void visit_minori(BSTNode<T>* node, T k) {
        if(node->key < k)
		    std::cout << *node << std::endl;
	}
    
    //punto 2
    BSTNode<T>* search(T key){
        int i=0;
        return search(root, key, i);
    }

    BSTNode<T>* search(BSTNode<T>* ptr, T key, int& i){
        if(isEmpty()) return nullptr;
        if(ptr==nullptr) return nullptr;
        if(ptr->getKey() == key){
            cout << "Elemento presente!" << endl;
            cout << "Numero di iterazioni : " << i << endl; 
            return ptr;
        }
        if(key <= ptr->key){
            i++;
            return search(ptr->left, key, i);
        }else{
            i++;
            return search(ptr->right, key, i);
        }
        return nullptr;
    }
	 
    //punto 3
	void minori(BSTNode<T>* ptr, T k) {
		if(ptr == nullptr)
			return;
		
		minori(ptr->left, k);
		visit_minori(ptr, k);
		minori(ptr->right, k);
	}
	
	void minori(T k) {
		minori(root, k);
	}

    //punto 4
    BSTNode<T>* min(){
        return min(root);
    }

    BSTNode<T>* min(BSTNode<T>* from){
        if(isEmpty()) return nullptr;

        BSTNode<T>* ptr=from;
        while(ptr->left){
            ptr=ptr->left;
        }
        return ptr;
    }

    BSTNode<T>* max(){
        return max(root);
    }

    BSTNode<T>* max(BSTNode<T>* from){
        if(isEmpty()) return nullptr;

        BSTNode<T>* ptr=from;
        while(ptr->right){
            ptr=ptr->right;
        }
        return ptr;
    }
};

#endif