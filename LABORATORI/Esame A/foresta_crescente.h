#ifndef FORESTA_CRESCENTE
#define FORESTA_CRESCENTE

#include "List.h"
#include "bst.h"

template<typename H>
class IF{
    int grado;
    LList<BST<H>> forest;
    LList<int> altezze;

    public:
        IF(int grado) : grado(grado){}
        void insBST(BST<H> p){
            if(p->altezza() <= grado){
                forest.ins(p);
                altezza.ins(p->altezza());
            }else{
                return;
            }
        }
        void ins(H key){
            if(forest.head->getNext)
        }

};

#endif