#include <iostream>
using namespace std;

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
	
		void visit(BSTNode<T>* ptr) { cout << "\n" << *ptr << endl; }
 
		void in_order(BSTNode<T>* ptr){

			if(!ptr)
				return;

			in_order(ptr->left);
			visit(ptr);
			in_order(ptr->right);
		}

		void in_order(){in_order(root);}

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
	
	int min_distanza(BSTNode<T>* from) {
		if(isEmpty()) {
			return -1;
		}
		
        int c=1;
		BSTNode<T>* ptr = from;
		while(ptr->left) {
            c++;
			ptr = ptr->left;
		}
		
		return c;
	}

    int distanza_successore(T val){
        if(this->isEmpty()) {
			return -1;
		}
		
		// 1. x ha un sottoalbero destro
		BSTNode<T>* x=search(val);
		if(x->right) 
			return this->min_distanza(x->right);
		
		// 2. x non ha un sottoalbero destro
		// il successore di x è l'antenato più prossimo di x
		// il cui figlio sinistro è anche un antenato di x
		
		BSTNode<T>* y = x->parent;
		int c=1;
		while(x != nullptr && x == y->right) {
            c++;
			x = y;
			y = y->parent;
		}
		
		return c;
    }
};

int main(){
    BST<int> bst;
    bst.insert(5);
    bst.insert(1);
    bst.insert(10);
    bst.insert(20);
    bst.insert(4);

    bst.in_order();

    cout << bst.distanza_successore(4) << endl;

    BST<char> b;
	b.insert('a');
	b.insert('b');
	b.insert('A');

	b.in_order();

	cout << bst.distanza_successore('a') << endl; 
}