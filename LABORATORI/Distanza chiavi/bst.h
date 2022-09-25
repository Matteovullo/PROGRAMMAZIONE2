#ifndef bst
#define bst

#include <iostream>
using namespace std;

template<typename H>
class BSTNode{
    private:
        H key;
        BSTNode<H>* left;
        BSTNode<H>* right;
        BSTNode<H>* parent;

    public:
        BSTNode(H key) : key(key), left(nullptr), right(nullptr), parent(nullptr){}
    	friend ostream& operator<<(ostream& out, BSTNode<H>& node) {
			out << "BSTNode@" << &node << " key=" << node.key << " - left=" << node.left << " right=" << node.right << " parent=" << node.parent;
		return out;
	}  

    template<typename U>
    friend class BST;            
};

template<typename H>
class BST{
    private:
        BSTNode<H>* root;

    public:
        BST() : root(nullptr){}
        bool isEmpty(){return root==nullptr;}
        void insert(H key) {
            if(this->isEmpty()) {
                root = new BSTNode<H>(key);
                return;
            }
            insert(root, key);
        }
     
        void insert(BSTNode<H>* ptr, H key) {
            if(ptr->left == nullptr && key <= ptr->key) {
                ptr->left = new BSTNode<H>(key);
                ptr->left->parent=ptr;
                return;
            }
            if(ptr->right == nullptr && key > ptr->key) {
                ptr->right = new BSTNode<H>(key);
                ptr->right->parent = ptr;
                return;
            }
            else if(key <= ptr->key)
                insert(ptr->left, key);
            else
                insert(ptr->right, key);
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
        /*
        BSTNode<H>* distanza(BSTNode<H>* ptr, H key, int& i){
            if(ptr == nullptr) 
                return nullptr;
            if(ptr->key == key){
                return ptr;
            }
            
            if(ptr->left == nullptr && ptr->right == nullptr){
                i++;
                BSTNode<H>* p=ptr->parent;
                distanza(p, key, i);
            }else if(key < ptr->key && key > root->key && ptr->left->key > ptr->parent->key){
                i++;
                BSTNode<H>* p=ptr->parent;
                distanza(p, key, i);               
            }else if(key <= ptr->key){
                i++;
                distanza(ptr->left, key, i);
            }else{
                i++;
                distanza(ptr->right, key, i);
            }
            return nullptr;
        }

        int distanzaChiavi(H k, H h){
            if((isEmpty())) return -1;

            BSTNode<H>* chiave1=search(k);
            BSTNode<H>* chiave2=search(h);
            if(chiave1->key == chiave2->key){
                return 0;
            }

            int i=0;
            distanza(chiave1, h, i);
            return i;
        }*/

		int from_root(BSTNode<H>* nodo_h, BSTNode<H>* partenza){

			//partenza = radice del sottoalbero ottenuto mettendo nodo_k come radice

			if(partenza->key == nodo_h->key) //distanza tra un nodo e se stesso
				return 0;

			BSTNode<H>* tmp = partenza;
			int counter = 0;  //distanza tra padre e figlio

			while(tmp && tmp->key != nodo_h->key) //esco quando arrivo ad una foglia 
												//oppure quando trovo il nodo
			{
				if(nodo_h->key > tmp->key) 
					tmp = tmp->right;
				else 
					tmp=tmp->left;

				counter++;
			}
			
			if(!tmp) 
				return -1;
			else 
				return counter;  
			
		}

		int distanzaChiavi(H k, H h) {

			BSTNode<H>* nodo_k = search(k);
			BSTNode<H>* nodo_h = search(h);

			int counter=0;

			if(!nodo_k || !nodo_h)
				throw ("Chiavi errate!");		//Sollevo un eccezzione
					
			if(k <= h)
			{
				BSTNode<H>* tmp = nodo_k;
				bool flag = true;

				while(tmp && flag) 
				{
					int distance = from_root(nodo_h, tmp); 

					if(distance == 0) //k e h coincidono
						flag = false;
					
					else if(distance == -1)
					{
						tmp = tmp->parent;  //salgo 
						counter++; 
					}
					else 
					{
						counter += distance;
						flag = false;
					}
				}

				return counter;
			}
			else
				return distanzaChiavi(h, k); //inverto per ottenere k <= h
		}

 		friend ostream& operator<< (ostream& os, BST<H>& b){

			if(b.isEmpty())
				return os << "\nEmpty BST!" << endl;

			os << "\nBST: " << endl;
			b.inorder();
			return os;
		}       
};

#endif