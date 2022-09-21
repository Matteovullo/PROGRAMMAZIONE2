/*Una lista concatenata di interi*/

#include <iostream>
using namespace std;

class Nodo{
    private:
        int val;
        Nodo* successivo;

    public:
        Nodo(int valore) : val(valore){
            successivo=nullptr;
        }
        int getVal(){
            return val;
        }
        Nodo* getSuccessivo(){
            return successivo;
        }
        friend class Lista;
};

class Lista{
    protected:
        int dim=0;
        Nodo* testa;

    public:
        Lista(){
            testa=nullptr;
        }
        bool vuota(){
            if(testa){
                return false;
            }else{
                return true;
            }
        }
        void inserimento_in_testa(int val){
            Nodo* ptr= new Nodo(val);
            testa=ptr;
            dim++;
        }
        void inserimento_in_coda(int val){
            Nodo* ptr=testa;
            while(ptr->getSuccessivo() != nullptr){
                ptr=ptr->getSuccessivo();
            }
            Nodo* nodo=new Nodo(val);
            ptr->successivo=nodo;
            dim++;
        }
        /*void rimozione_in_testa(){
            if(vuota()){
                return;
            }else{
                
            }
        }*/
        void rimozione_in_coda(){
            if(vuota()){
                return;
            }else{
                Nodo* ptr=testa;
                while(ptr->getSuccessivo() != nullptr){
                    ptr=ptr->getSuccessivo();
                }
                dim--;
                ptr->successivo=nullptr;
                delete ptr;
            }
        }
        Nodo* ricerca(int val){
            if(vuota()){
                return nullptr;
            }else{
                Nodo* ptr=testa;
                while(ptr->getSuccessivo() != nullptr){
                    ptr=ptr->getSuccessivo();
                    if(ptr->getVal() == val){
                        return ptr;
                    }
                }
            }
            return nullptr;
        }
        friend ostream& operator<<(ostream& os, Lista &l);
};

ostream& operator<<(ostream& os, Lista &l){
    os << "Dimensioni: " << l.dim << endl;
        Nodo* ptr=l.testa;
        while(ptr->getSuccessivo() != nullptr){
            ptr=ptr->getSuccessivo();
            os << "Indirizzo: " << ptr->getSuccessivo() << ", valore: " << ptr->getVal() << endl;
        }
        return os;
}

int main(){
    Lista l;
    l.inserimento_in_testa(1);
    l.inserimento_in_coda(2);
    l.inserimento_in_coda(3);
    l.inserimento_in_coda(4);
    cout << l;
    l.rimozione_in_coda();
    cout << l;
}