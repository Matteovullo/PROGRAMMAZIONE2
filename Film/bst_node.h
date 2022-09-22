#ifndef BST_NODE
#define BST_NODE

#include <iostream>
using namespace std;

template<typename T>
class BSTNode{
    private:
        T key;
        BSTNode<T>* left;
        BSTNode<T>* right;
        BSTNode<T>* parent;

    template<typename U>
    friend class Bst;

    public:
        BSTNode(T key) : left(nullptr), right(nullptr), parent(nullptr), key(key){}
        friend ostream& operator<<(ostream& os, BSTNode<T>& n){
            os << "Key = " << n.key << ", figlio destro=" << n.right << ", figlio sinistro = " << n.left << ", genitore = " << n.parent << endl;
            return os;
        }
};

#endif