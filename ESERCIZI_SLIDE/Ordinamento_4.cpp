/*Applicare la ricerca sequenziale per contare il numero di volte che un elemento
compare in un array*/

#include <iostream>
using namespace std;

template<typename T>
int conta_elementi(T array[], int dim, T chiave){
    int count=0;
    for(int i=0; i<dim; i++){
        if(chiave == array[i]) count++;
    }
    return count;
}

int main(){
    int array[10]={1, 1, 1, 5, 2, 5, 5, 4};
    cout << conta_elementi<int>(array, 10, 0) << endl;
}