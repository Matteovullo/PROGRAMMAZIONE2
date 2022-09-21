/*Implementare l'algoritmo di ordinamento BubbleSort tramite un metodo
void bubbleSort(T a[], int n) 
che prende in input un array di elementi di tipo T di lunghezza n e li ordina.
Definire inoltre una semplice classe Rettangolo.
Nel corpo del metodo main() istanziare:
- un array di interi
- un array di char
- un array di rettangoli
applicare l'algoritmo di ordinamento a tutti e tre gli array facendo in modo che gli
oggetti di tipo Rettangolo vengano confrontati in base al valore della loro area.
Per verificare il funzionamento del codice, stampare il contenuto degli array prima
e dopo l’ordinamento.*/

#include <iostream>
using namespace std;

class Rettangolo{
    private:
        double altezza, base;

    public:
        Rettangolo(double altezza, double base){
            this->altezza=altezza;
            this->base=base;
        }
        Rettangolo(Rettangolo& r){
            this->base=r.base;
            this->altezza=r.altezza;
        }
        double area(){
            return altezza*base;
        }
        friend ostream& operator<<(ostream &os, Rettangolo& r);
};

ostream& operator<<(ostream &os, Rettangolo& r){
    os << "Altezza: " << r.altezza << ", base: " <<r.base << ", area: " << r.area() << endl;
    return os;
}

template<typename T>
void bubbleSort(T *a, int n){
    bool scambio=true;
    for(int i=0; i < n; i++) {
		cout << a[i] << "\t";
	}
    while(scambio){
        scambio = false;
        for(int i=0; i<n-1; i++){
            if(a[i] > a[i+1]){
                swap(a[i], a[i+1]);
                scambio = true;
            }
        }
    }
    cout << endl;
    for(int i=0; i < n; i++) {
		cout << a[i] << "\t";
	}
    cout << endl;
}

void swap_r(Rettangolo& r1, Rettangolo& r2){
    Rettangolo aux=r1;
    r1=r2;
    r2=aux;
}

void bubbleSort_r(Rettangolo *a, int n){
    bool scambio=true;
    for(int i=0; i < n; i++) {
		cout << a[i] << "\t";
	}
    while(scambio){
        scambio = false;
        for(int i=0; i<n-1; i++){
            if(a[i].area() > a[i+1].area()){
                swap_r(a[i], a[i+1]);
            } 
        }
    }
    cout << endl;
    for(int i=0; i < n; i++) {
		cout << a[i] << "\t";
	}
    cout << endl;
}

void swap(Rettangolo& r1, Rettangolo& r2){
    Rettangolo aux=r1;
    r1=r2;
    r2=aux;
}

template<typename T>
void printArray(T *array, int n) {
	for(int i=0; i < n; i++) {
		cout << array[i] << "\t";
	}
	cout << endl;
}

int main(){
    int *a = new int[5]{5, 4, 2, 4, 10};
    char *b = new char[3]{'y', 'u', 'a'};
    Rettangolo array[3]{{1.5, 10.0}, {2.0, 3.5}, {5.1, 1.6}};

    /*printArray(a, 5);
    printArray(b, 5);
    printArray(array, 3);*/

    bubbleSort(a, 5);
    bubbleSort(b, 3);
    bubbleSort_r(array, 3);

    /*printArray(a, 5);
    printArray(b, 5);
    printArray(array, 3);*/
}