#include <iostream>
#include "static_stack.h"
#include "static_queue.h"
using namespace std;

class OperazioneAritmetica{
    protected:
        double opSinistro;
        double opDestro;

    public:
        OperazioneAritmetica(double opSistro, double opDestro) : opSinistro(opSinistro), opDestro(opDestro){}
        OperazioneAritmetica() : opSinistro(0), opDestro(0){}
        void setOpSinistro(double a){opSinistro=a;}
        void setOpDestro(double b){opDestro=b;}
        virtual double eseguiCalcolo()=0;
};

class Addizione : public OperazioneAritmetica{
    public:
        Addizione(double a, double b) : OperazioneAritmetica(a, b){}
        Addizione() : OperazioneAritmetica(){}
        double eseguiCalcolo(){
            return opSinistro+opDestro;
        }
};

class Sottrazione : public OperazioneAritmetica{
    public:
        Sottrazione(double a, double b) : OperazioneAritmetica(a, b){}
        Sottrazione() : OperazioneAritmetica(){}
        double eseguiCalcolo(){
            return opSinistro-opDestro;
        }
};

class Moltiplicazione : public OperazioneAritmetica{
    public:
        Moltiplicazione(double a, double b) : OperazioneAritmetica(a, b){}
        Moltiplicazione() : OperazioneAritmetica(){}
        double eseguiCalcolo(){
            return opSinistro*opDestro;
        }
};

class Divisione : public OperazioneAritmetica{
    public:
        Divisione(double a, double b) : OperazioneAritmetica(a, b){}
        Divisione() : OperazioneAritmetica(){}
        double eseguiCalcolo(){
            return opSinistro/opDestro;
        }
};

int main(){
    //punto 1
    int n;
    cout << "Inserire un valore intero: " << endl;
    cin >> n;

    //punto 2
    StaticStack<OperazioneAritmetica*> pila(n);
    for(int i=0; i<n; i++){
        int r=rand()%(4-1+1)+1;
        if(r==1){
            OperazioneAritmetica* ptr=new Addizione;
            pila.push(ptr);
        }
        if(r==2){
            OperazioneAritmetica* ptr=new Sottrazione;
            pila.push(ptr);
        }
        if(r==3){
            OperazioneAritmetica* ptr=new Moltiplicazione;
            pila.push(ptr);
        }
        if(r==4){
            OperazioneAritmetica* ptr=new Divisione;
            pila.push(ptr);
        }
    }

    //punto 3
    StaticQueue<double> coda(2*n);
    for(int i=0; i<2*n; i++){
        double r=((double)rand()/RAND_MAX)*1000;
        coda.enqueue(r);
    }

    //punto 4
    cout << pila << endl;
    cout << coda << endl;

    //punto 5
    for(int i=0; i<n; i++){
        double a=coda.dequeue();
        double b=coda.dequeue();
        OperazioneAritmetica* ptr=pila.pop();
        ptr->setOpSinistro(a);
    	ptr->setOpDestro(b);
    	cout << ptr->eseguiCalcolo() << endl;
         /*if(typeid(ptr)==typeid(Addizione)){
            cout << dynamic_cast<Addizione*>(ptr)->eseguiCalcolo() << endl;
        }
        if(typeid(ptr)==typeid(Sottrazione)){
            cout << dynamic_cast<Sottrazione*>(ptr)->eseguiCalcolo() << endl;
        }
        if(typeid(ptr)==typeid(Moltiplicazione)){
            cout << dynamic_cast<Moltiplicazione*>(ptr)->eseguiCalcolo() << endl;
        }
        if(typeid(ptr)==typeid(Divisione)){
            cout << dynamic_cast<Divisione*>(ptr)->eseguiCalcolo() << endl;
        }*/
    }
}
