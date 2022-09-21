/*lista circolare*/

#include <iostream>
using namespace std;

template<typename T>
class Nodo{
    private:
        T val;
        Nodo<T>* successivo;

    template<typename U>
    friend class Lista;

    public:
        Nodo(T val){ 
            successivo=nullptr;
            this->val=val;
        }
        T getVal() const {
            return val;
        }
        Nodo<T>* getSuccessivo() const {
            return successivo;
        }
};

template<typename T>
class Lista{
    private:
        Nodo<T>* testa;
        Nodo<T>* circolare;
        int size=0;

    public:
        Lista(){
            testa=nullptr;
            circolare=nullptr;
        }
        bool vuota()const{
            return (testa==nullptr && circolare==nullptr);
        }
        void inserimentoTesta(T val){
            if(vuota()){
                testa = new Nodo<T>(val);
                circolare = testa;
                return;
            }

            Nodo<T>* ptr=new Nodo<T>(val);
            ptr->successivo=testa->successivo;
            testa = ptr;
            circolare = testa;
            size++;
        }
        void inserimentoCoda(T val){
            if(vuota()){
                inserimentoTesta(val);
                return;
            }

            Nodo<T>* ptr=testa;
            while(ptr->getSuccessivo()){
                ptr=ptr->getSuccessivo();
            }
            Nodo<T>* nuovo=new Nodo<T>(val);
            ptr->successivo=nuovo;
            size++;
        }
        void inserimentoOrdine(T val){
            if(vuota()){
                inserimentoTesta(val);
                return;
            }
            Nodo<T>* corrente=testa;
            Nodo<T>* precente=nullptr;
            while(corrente!=nullptr && corrente->getVal() <= val){
                precente = corrente;
                corrente = corrente->getSuccessivo();
            }

            Nodo<T>* nuovo=new Nodo<T>(val);
            nuovo->successivo=corrente;
            precente->successivo=nuovo;
        }
        void inserimento(T val){
            if(vuota()){
                inserimentoTesta(val);
                return;
            }else{
                inserimentoCoda(val);
            }
        }
        void rimozioneTesta(){
            if(vuota()){
                return;
            }

            testa  = testa->successivo;
            circolare = testa;
            size--;
        }
        void rimozioneCoda(){
            if(vuota()){
                return;
            }
            if(size==1){
                rimozioneTesta();
                return;
            }

            Nodo<T>* corrente=testa;
            Nodo<T>* precente=nullptr;
            while(corrente){
                precente = corrente;
                corrente = corrente->getSuccessivo();
            }

            corrente=nullptr;
            size--;
        }
        int ricerca(T val){
            if(testa->getVal() == val) return 1;
            Nodo<T>* ptr=testa;
            int c=0;
            while(ptr->getSuccessivo()){
                if(ptr->getVal() == val) return c;
                ptr=ptr->getSuccessivo();
                c++;
            }
            return -1;
        }
        friend ostream& operator<<(ostream& os, const Lista<T>& l){
            if(l.vuota()) {os << "Lista vuota;" << endl;}
            else{
                Nodo<T>* ptr=l.testa;
                while(ptr != nullptr){
                    os << "val=" << ptr->getVal() << "->";
                    ptr=ptr->getSuccessivo();
                }
                os << l.circolare->getVal() << endl;
            }
            return os;
        }
};

int main(){
    Lista<int> l;
    l.inserimentoTesta(5);
    l.inserimentoCoda(1);
    l.inserimentoCoda(3);
    cout << l << endl;
    l.rimozioneTesta();
    cout << l << endl;
    l.rimozioneCoda();
    cout << l << endl;
    cout << l.ricerca(3) << endl;
    l.inserimentoCoda(4);
    l.inserimentoOrdine(5);
    cout << l << endl;
}