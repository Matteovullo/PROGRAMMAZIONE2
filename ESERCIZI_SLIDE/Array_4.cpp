/*Scrivere un programma che inizializza solo i primi due elementi di un vettore di 4 e
visualizzi il valore degli elementi non assegnati.*/

#include <iostream>

using namespace std;

int main(){
    string vettore[4]={"ff", "dddf"};
    cout << vettore[2] << ", " << vettore[3] << endl;

    double v[2]={2.5};
    cout << v[1] << endl;
}