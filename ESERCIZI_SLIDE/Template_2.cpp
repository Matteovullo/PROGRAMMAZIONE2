/*Implementare un metodo
int ricerca(T dato, T v[], int dim)
che prende in input un oggetto di tipo T, un array di elementi tipo T di lunghezza dim e
cerca il primo elemento all’interno dell’array, restituendo l’indice se presente. Se
l’elemento non è presente il metodo restituisce il valore -1. Definire inoltre una
semplice classe Punto.
Nel corpo del metodo main() istanziare:
- un array di interi
- un array di char
- un array di Punto
Permettere all’utente di inserire dei valori per ciascuno dei tre tipi elencati sopra ed
applicare l’algoritmo di ricerca degli elementi inseriti dall’utente.
Per verificare il funzionamento del codice, stampare il contenuto degli array*/

#include <iostream>

using namespace std;

template <typename T>
int ricerca(T dato, T v[], int dim){
    for(int i=0; i<dim; i++){
        if(v[i] == dato){
            return i;
        }
    }
    return -1;
}

class Punto{
    int x;

    public:
        Punto(int x){
            this->x=x;
        }
        int getX(){
            return x;
        }
};

template <>
int ricerca<Punto>(Punto p, Punto array[], int dim){
    for(int i=0; i<dim; i++){
        if(array[i].getX() == p.getX()){
            return i;
        }
    }
    return -1;
}

int main(){
    int array1[5]={1, 2, 3, 4, 5};
    char array2[3]={'A', 'E', 'I'};
    Punto array3[5]={1, 2, 3, 4, 5};
    cout << ricerca<int>(1, array1, 5) << endl;
    cout << ricerca<char>('A', array2, 3) << endl;
    cout << ricerca<Punto>(array3[0], array3, 10) << endl;
}