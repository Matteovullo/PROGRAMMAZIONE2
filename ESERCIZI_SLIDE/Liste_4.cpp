/*Una lista doppia*/

#include<iostream>
using namespace std;

template<typename T>
class DoppioNodo{
    private:
        T val;
        DoppioNodo<T>* succ;
        DoppioNodo<T>* pre;

        template<typename U>
        friend class DoppiaLista;

    public:
        DoppioNodo(int val) : val(val), succ(nullptr), pre(nullptr){}
        T getValore(){
            return val;
        }
        DoppioNodo* getSucc(){
            return succ;
        }
        DoppioNodo* getPre(){
            return pre;
        }
};

template<typename T>
class DoppiaLista{
    protected:
        int dim=0;
        DoppioNodo<T>* testa;
        DoppioNodo<T>* coda;

    public:
        DoppiaLista() : testa(nullptr), coda(nullptr){}
        bool vuota()const{
            if(testa==nullptr && testa==nullptr){
                return true;
            }else{
                return false;
            }
        }
        void inserimento_in_testa(int val){
            if(vuota()){
                DoppioNodo<T>* ptr=new DoppioNodo<T>(val);
                testa=ptr;
                coda=ptr;
                dim++;
                return;
            }

            DoppioNodo<T>* ptr=new DoppioNodo<T>(val);
            testa->pre = ptr;
            ptr->succ = testa;
            testa = ptr;
            dim++;
        }
        void inserimento_in_coda(int val){
            if(vuota()){
                inserimento_in_testa(val);
                dim++;
                return;
            }
            DoppioNodo<T>*ptr=new DoppioNodo<T>(val);
            ptr->pre=coda;
            coda->succ=ptr;
            coda=ptr;
            dim++;
        }
        void rimozione_in_testa(){
            if(vuota()){
                return;
            }else if(testa==coda){
                testa=nullptr;
                coda=nullptr;
                dim--;
                return;
            }else{
                DoppioNodo<T>* ptr=testa;
                ptr->succ->pre=nullptr;
                testa=ptr->succ;
                delete ptr;
                dim--;
            }
        }
        void rimozione_in_coda(){
            if(vuota()){
                return;
            }else if(testa==coda){
                testa=nullptr;
                coda=nullptr;
                dim--;
                return;
            }else{
                DoppioNodo<T>* ptr=coda;
                ptr->pre=coda->pre->succ;
                coda=ptr;
                dim--;
            }
        }
        DoppioNodo<T>* ricerca(int val){
            if(vuota){
                return nullptr;
            }else{
                DoppioNodo<T>* ptr=testa;
                while(ptr->getSucc() != nullptr){
                    if(ptr->getValore() == val) return ptr;
                    ptr=ptr->getSucc();
                }
            }
        }
        friend ostream& operator<<(ostream& os, const DoppiaLista<T> &dl){
            if(dl.vuota()){
                os << "Doppialista vuota" << endl;
            }else{
                os << "Dimensione: " << dl.dim << endl;
                DoppioNodo<T>* ptr=dl.testa;
                for(int i=0; i<dl.dim; i++){
                    os << "Valore: " << ptr->getValore() << ", Indirizzo successivo: " << ptr->getSucc() << ", Indirizzo precedente: " << ptr->getPre() << endl;
                    ptr=ptr->getSucc();
                }
            }
            return os;
        }
};

int main(){
    DoppiaLista<int> dl;
    dl.inserimento_in_testa(1);
    dl.inserimento_in_coda(2);
    dl.inserimento_in_coda(3);
    cout << dl << endl;
    dl.rimozione_in_coda();
    dl.rimozione_in_testa();
    cout << dl << endl;
}