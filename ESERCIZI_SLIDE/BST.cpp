/*implemnta un bst*/

#include <iostream>

using namespace std;

template<typename T>
class BSTNodo{
    BSTNodo<T>* sinistro;
    BSTNodo<T>* destro;
    BSTNodo<T>* genitore;

    T chiave;

    template<typename T>
    friend class BST;

    public:
        BSTNodo(T chiave) : chiave(chiave){
            sinistro=nullptr;
            destro=nullptr;
            genitore=nullptr;
        }
        void setSinistro(BSTNodo<T>* sinistro){
            this->sinistro=sinistro;
        }
        void setDestro(BSTNodo<T>* destro){
            this->destro=destro;
        }
        void setGenitore(BSTNodo<T>* genitore){
            this->genitore=genitore;
        }
        void setChiave(T chiave){
            this->chiave=chiave;
        }
        BSTNodo<T>* getSinistro(){
            return sinistro;
        }
        BSTNodo<T>* getDestro(){
            return destro;
        }
        BSTNodo<T>* getGenitore(){
            return genitore;
        }
        T getChiave(){
            return chiave;
        }
        friend ostream& operato<<(ostream& os, BSTNodo<T>& nodo){
            os << << "BSTNode@" << &nodo << " key=" << nodo.chiave << " - left=" << nodo.sinistro << " right=" << nodo.destro << " parent=" << nodo.genitore;
            return os;
        }
};

template<typename T>
class BST{
    private:
        BSTNodo<T>* radice;

    public:
        BST(){
            radice = nullptr;
        }
        bool vuoto(){
            if(radice == nullptr) return true;
            else return false;
        }
        BSTNodo<T>* getRadice(){
            return radice;
        }
        void inserimento(T chiave){
            if(vuoto()){
                radice = new BSTNodo<T>(chiave);
                return
            }
            inseriemento(radice, chiave);
        }
        void inserimento(BSTNodo<T>* ptr, T c){
            if(ptr->getSinistro()==nullptr && c <= ptr->chiave){
                ptr->sinistro=new BSTNodo<T>(c);
                ptr->sinistro->setGenitore(ptr);
                return
            }
            if(ptr->getDestro()==nullptr && c > ptr->chiave){
                ptr->destro=new BSTNodo<T>(c);
                ptr->destro->setGenitore(ptr);
                return
            }else if(c <= ptr->chiave){
                inserimento(ptr->sinistro, c);
            }else{
                inserimento(ptr->destro, c);
            }
        }
        void visita(BSTNodo<T>* nodo){
            cout << *nodo << endl;
        }
        void preOrder(BSTNodo<T>* ptr){
            if(p){
                cout << ptr->chiave << " ";
                preOrder(ptr->sinistro);
                preOrder(ptr->destro);
            }
        }
        void inOrder(BSTNodo* ptr){
            if(ptr){
                inOrder(ptr->sinistro);
                cout << ptr->chiave << " ";
                inOrder(ptr->destro);
             }
        }
        void postOrder(BSTNodo<T>* ptr){
            if(ptr){
                postOrder(ptr->sinistro);
                postOrder(ptr->destro);
                cout << ptr->chiave << " ";
            }
        }
        BSTNodo<T>* min(){
            return min(radice);
        }
        BSTNodo<T>* min(BSTNodo<T>* p){
            if(vuoto()) return nullptr;
            BSTNodo<T>* ptr=p;
            while(ptr->sinistro){
                ptr=ptr->sinistro;
            }
            return ptr;
        }
        BSTNodo<T>* mas(){
            return mas(radice);
        }
        BSTNodo<T>* mas(BSTNodo<T>* p){
            if(vuoto()) retunr nullptr;
            BSTNodo<T>* ptr=p;
            while(ptr->destro){
                ptr=ptr->destro;
            }
            return ptr;
        }
        BSTNodo<T>* successore(BSTNodo<T>* x){
            if(vuoto()) retunr nullptr;
            if(x->destro){
                return min(x);
            }
            BSTNodo<T>* y=x->genitore;
            while(x != nullptr && x==y->destro){
                x=y;
                y=y->genitore;
            }
            return y;
        }
        BSTNodo<T>* ricerca(T chiave){
            return ricarca(radice, chiave);
        }
        BSTNodo<T>* ricerca(BSTNodo<T>* ptr, T chiave){
            if(ptr==nullptr) return nullptr;
            if(ptr->chiave=chiave) return ptr;
            if(chiave <= ptr->chiave){
                return ricerca(ptr->sinistro, chiave);
            }else{
                return ricerca(ptr->destro, chiave);
            }
            return nullptr;
        }
        BSTNodo<T>* rimozione(BSTNodo<T>* nodo){
            if(nodo->sinistro == nullptr && nodo->destro == nullptr){
                if(nodo == nodo->genitore->sinistro){
                    nodo->genitore->sinistro=nullptr;
                }else if(nodo == nodo->genitore->destro){
                    nodo->genitore->destro=nullptr;
                }
                return nodo;
            }
            if(nodo->sinistro == nullptr && nodo->destro != nullptr){
                nodo->sinistro->genitore=nodo->genitore;
                if(nodo == nodo->genitore->sinistro){
                    nodo->genitore->sinistro=nodo->sinistro;
                }else if(nodo==nodo->genitore->destro){
                    nodo->genitore->sinistro=nodo->sinistro;
                }
                return nodo;
            }
            if(nodo->sinistro != nullptr && nodo->destro == nullptr){
                nodo->sinistro->genitore=nodo->genitore;
                if(nodo == nodo->genitore->sinistro){
                    nodo->genitore->sinistro=nodo->sinistro;
                }else if(nodo == nodo->genitore->destro){
                    nodo->genitore->destro=nodo->destro;
                }
                return nodo;
            }
            return nullptr;
        }
        BSTNodo<T>* rimozione(T chiave){
            if(vuoto()) return nullptr;
            BSTNodo<T>* nodo=ricerca(chiave);
            if(nodo==nullptr){
                return nullptr;
            }
            BSTNodo<T>* eliminare=rimozione(nodo);
            if(eliminare != nullptr){
                return eliminare;
            }
            BSTNodo<T>* successivo=successivo(nodo);
            T swao=nodo->chiave;
            nodo->chiave=successivo->chiave;
            successivo->chiave=swap;
            eliminare=rimozione(successivo);
            return eliminare;
        }
};