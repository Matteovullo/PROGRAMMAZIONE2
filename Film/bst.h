#ifndef BST
#define BST

#include "bst_node.h"

template<typename T>
class Bst{
    private:
        BSTNode<T>* root;

    public:
        Bst() : root(nullptr){}
        bool isEmpty(){
            return root==nullptr;
        }
        void insert(T val){
            if(isEmpty()){
                root=new BSTNode<T>(val);
                return;
            }
            insert(root, val);
        }
        void insert(BSTNode<T>* ptr, T val){
            if(ptr->left==nullptr && val < ptr->key){
                ptr->left=new BSTNode<T>(val);
                ptr->left->parent=ptr;
                return;
            }
            if(ptr->right==nullptr && val >= ptr->key){
                ptr->right=new BSTNode<T>(val);
                ptr->right->parent=ptr;
                return;
            }else if(val < ptr->val){
                insert(ptr->left, val);
            }else{
                insert(ptr->right, val);
            }
        }
        void visit(BSTNode<T>* ptr){
            cout << *ptr << endl;
        }
        void inorder(BSTNode<T>* ptr){
            if(!ptr) return;

            inorder(ptr->left);
            visit(ptr);
            inorder(ptr->right);
        }
        void inorder(){
            inorder(root);
        }
    friend ostream& operator<<(ostream& os, Bst<T>& bst){
        bst.inorder();
        return os;
    }
};

#endif