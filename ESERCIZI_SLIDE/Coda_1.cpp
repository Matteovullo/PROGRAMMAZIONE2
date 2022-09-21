/*• una classe coda usando un array*/

#include <iostream>
using namespace std;

/*template<typename T>
class Coda{
    private:
        T **coda;
        int dim;
        int dim_attuale=0;
        T *testa;
        T *fine;

    public:
        Coda(int dim) : dim(dim){
            testa=nullptr;
            fine=nullptr;
            coda=new T*[dim];
            for(int i=0; i<dim; i++){
                coda[i]=nullptr;
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
        void inserire(int val){
            for(int i=0; i<dim; i++){
                if(coda[i] == nullptr){
                    coda[i]=new int(val);
                    dim_attuale++;
                    if(i==0)
                        testa=coda[i];
                    else
                        fine=coda[i];
                    return;
                }
            }
        }
        void rimuovere(){
            if(vuoto()) return;
            int index=0;
            for(int i=0; i<dim; i++){
                if(coda[i] != nullptr){
                    coda[i]=nullptr;
                    dim_attuale--;
                    testa=coda[i+1];
                    break;
                }
            }
            T *sup[dim];
            for(int i=0; i<dim; i++){
                if(coda[i]){
                    sup[i-1]=coda[i];
                }
            }
            for(int i=0; i<dim; i++){
                if(sup[i])
                    coda[i]=sup[i];
            }
        }
        int* ultimo(){
            if(vuoto()){
                return nullptr;
            }else{
                return fine;
            }
        }
        int* inizio(){
            if(vuoto()){
                return nullptr;
            }else{
                return testa;
            }
        }
        friend ostream& operator<<(ostream& os, Coda<T> p){
        os << "Dimensione massima: " << p.dim << ", dimensione attuale: " << p.dim_attuale << endl;
        for(int i=0; i<p.dim; i++){
            if(p.coda[i]){
            cout << *(p.coda[i]) << " ";
            }
        }
        cout << endl;
        return os;
        }
};
*/

template<class T>
class Coda{
    private:
        int dim=0;
        int max_size;
        int testa=0;
        int coda=-1;
        T *array;

    public:
        Coda(int max_size) : max_size(max_size){
            array=new T[max_size];
        }
        bool vuota(){
            return dim==0;
        }
        bool piena(){
            return dim==max_size;
        }
        void enqueue(T val){
            if(piena()) return;

            if(testa==-1){
                testa=0;
            }

            dim++;
            coda++;
            array[coda]=val;
        }
        void dequeue(){
            if(vuota()) return;

            dim--;
            testa++;
        }
        friend ostream& operator<<(ostream& os, Coda<T> c){
            if(c.vuota()) os << "Coda vuota" << endl;

            os << "Dimensione: " << c.dim << endl;
            int count;
            for(int i=c.testa,count =0;count<c.dim; count++){
                os<<c.array[i]<<endl;
                i = (i+1) % c.max_size;
            }
            return os;       
        }
};

int main(){
    Coda<int> c(10);
    c.enqueue(1);
    c.enqueue(5);
    c.enqueue(15);
    cout << c << endl;
    c.dequeue();
    cout << c << endl;
}