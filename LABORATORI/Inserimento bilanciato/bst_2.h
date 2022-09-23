#ifndef bst
#define bst

#include<iostream>
using namespace std;

template<typename T>
class BSTNode{
    private:
        T key;
        BSTNode<T>* left;
        BSTNode<T>* right;
        BSTNode<T>* parent;

    public:
        BSTNode(T key) : key(key), left(nullptr), right(nullptr), parent(nullptr){}
        T getKey(){return key;}
        friend ostream& operator<<(ostream& os, BSTNode<T>& n){
            os << "val = " << n.key  << ", left = " << n.left << ", right = " << n.right << ", parent = " << n.parent << endl;
            return os;
        }
        template<typename U>
        friend class BST;
};

template<typename T>
class BST{
    private:
        BSTNode<T>* root;

    public:
        BST() : root(nullptr){}
        bool isEmpty(){return root==nullptr;}
        /*void insert(T key){
            if(isEmpty()){
                root=new BSTNode<T>(key);
                return;
            }else{
                insert(root, key);
            }
        }
        void insert(BSTNode<T>* ptr, T key){
            if(ptr->left==nullptr && key < ptr->getKey()){
                ptr->left = new BSTNode<T>(key);
                ptr->left->parent=ptr;
            }
            if(ptr->rigth==nullptr && key >= ptr->getKey()){
                ptr->rigth = new BSTNode<T>(key);
                ptr->rigth->parent=ptr;
            }
            else if(key < ptr->getKey()){
                insert(ptr->left, key);
            }else{
                insert(ptr->rigth, key);
            }
        }*/
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
                ptr->left->parent=ptr;
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
        void visit(BSTNode<T>* ptr){
            cout << *ptr << endl;
        }
        void inorder(BSTNode<T>* ptr){
            if(!ptr) return;

            inorder(ptr->left);
            visit(ptr);
            inorder(ptr->left);
        }
        void inorder(){
            inorder(root);
        }
        friend ostream& operator<<(ostream& os, BST<T>& b){
            if(b.isEmpty()) os << "BST vuoto" << endl;
            b.inorder();
            return os;
        }
};

#endif