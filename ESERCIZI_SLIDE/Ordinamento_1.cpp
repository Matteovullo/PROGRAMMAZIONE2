/*implementa l'algoritmo di insertion sort*/

#include <iostream>
using namespace std;

void insertion_sort(int v[], int dim){
    for(int i=0; i<dim; i++){
        int appoggio = v[i];
        int j;
        for(j=i; j>0; j--){
            if(appoggio < v[j-1]){
                v[j] = v[j-1];
            }else{
                break;
            }
        }
        v[j] = appoggio;
    }
}

void printArray(int array[], int n) {
	
	for(int i=0; i < n; i++) {
		std::cout << array[i] << "\t";
	}
	std::cout << std::endl;
}

int main(){
    int array[5]={15, 17, 20, 5, 1};
    insertion_sort(array, 5);
    printArray(array, 5);
}