/*• una classe pila usando un array*/

#include <iostream>
using namespace std;

/*class Pila{
    private:
        int dim;
        int **pila;
        int *indice;
        int dim_attuale=0;

    public:
        Pila(int dim) : dim(dim){
            pila=new int*[dim];
            for(int i=0; i<dim; i++){
                pila[i]=nullptr;
            }
            indice=nullptr;
        }
        void inserire(int val){
            for(int i=0; i<dim; i++){
                if(pila[i] == nullptr){
                    pila[i]=new int(val);
                    dim_attuale++;
                    indice=pila[i];
                    return;
                }
            }
        }
        void rimuovere(){
            if(vuoto()) return;
            for(int i=dim-1; i>=0; i--){
                if(pila[i] != nullptr){
                    pila[i]=nullptr;
                    dim_attuale--;
                    if(i>0)
                        indice=pila[i-1];
                    else
                        indice=pila[0];
                    return;
                }
            }
        }
        bool pieno(){
            if(dim_attuale == dim) return true;
            else return false;
        }
        bool vuoto(){
            if(dim_attuale ==  0) return true;
            else return false;
        }
        int* superficie(){
            if(vuoto()){
                return nullptr;
            }else{
                for(int i=dim-1; i>=0; i--){
                    if(pila[i] != nullptr){
                        return pila[i];
                    }
                }
            }
        }
        friend ostream& operator<<(ostream& os, Pila p);
};

ostream& operator<<(ostream& os, Pila p){
    os << "Dimensione massima: " << p.dim << ", dimensione attuale: " << p.dim_attuale << endl;
    for(int i=p.dim-1; i>=0; i--){
        if(p.pila[i]){
            cout << *(p.pila[i]) << endl;
        }
    }
    return os;
}*/

template<typename T>
class Pila{
    private:
        int dim=0;
        int cima=-1;
        int max_size;
        T *array;

    public:
        Pila(int max_size) : max_size(max_size){
            array = new T[max_size];
        }
        bool vuota(){
            return dim==0;
        }
        bool piena(){
            return dim==max_size;
        }
        T getCima(){
            if(vuota()) return -1;
            return array[cima];
        }
        void push(T val){
            if(piena()) return;

            dim++;
            array[++cima]=val;
        }
        void pop(){
            if(vuota()) return;

            dim--;
            cima--;
        }
        friend ostream& operator<<(ostream& os, Pila<T> p){
            os << "Max_size: " << p.max_size << endl;
            if(p.vuota()) os << "Pila vuota" << endl;
            for(int i=0; i<p.dim; i++){
                os << p.array[i] << endl;
            }
            return os;
        }
};

int main(){
    Pila<int> p(10);
    p.push(5);
    p.push(15);
    p.push(1);
    cout << p << endl;
    p.pop();
    cout << p << endl;
    cout << p.getCima() << endl;
}