/*implementa l'algoritmo di selection sort*/

#include <iostream>
using namespace std;

void selection_sort(int v[], int dim){
    for(int i=0; i<dim; i++){
        int appoggio = v[i];
        int minimo = v[i];
        int index = i;
        for(int j=i; j<dim; j++){
            if(v[j] < appoggio){
                appoggio = v[j];
                index = j;
            }
        }
        v[i] = appoggio;
        v[index] = minimo;
    }
}

void selectionSort(int array[], int n) {
	int indexMin;
	for(int i=0; i < n; i++) {
		indexMin = i;
		for(int j=i+1; j < n; j++) {
			if(array[j] < array[indexMin])
				indexMin = j;
		}
		swap(array[i], array[indexMin]);
	}
}

void printArray(int array[], int n) {
	
	for(int i=0; i < n; i++) {
		std::cout << array[i] << "\t";
	}
	std::cout << std::endl;
}

int main(){
    int array[10]={10, 20, 35, 4, 5, 10, 6, 3, 1};
    selection_sort(array, 10);
    printArray(array, 10);
}