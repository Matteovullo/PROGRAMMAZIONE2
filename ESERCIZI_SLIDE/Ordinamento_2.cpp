/*migliora l'algoritmo precedente sfurttando la ricerca binaria*/

#include <iostream>

using namespace std;

#include <iostream>

//binarySearch
//supponiamo che l'array sia già ordinato
bool ricercaBinaria(int array[], int n, int key) {
	bool found = false;
	
	//n/2 = (n-0)/2
	//int midpoint = n/2; //floor(n/2)
	int start = 0;
	int end = n;
	
	while(!found && (start != end)) {
			
		int midpoint = start + ((end-start)/2); // (start+end)/2
		
		std::cout << "start = " << start << ", end = " << end << ", midpoint = " << midpoint << std::endl;
		if(array[midpoint] == key) 
			found = true;
		else if(key < array[midpoint]) {
			//considerare la metà inferiore
			//aggiornare end e midpoint
			end = midpoint;
			//midpoint = (end-start)/2;
		}
		else {
			//considerare la metà superiore
			//aggiornare start e midpoint
			start=midpoint+1;
			//midpoint = (end-start)/2;
		}
		
		
	}
	//verificare ad ogni iterazione se key >= array[n/2]
	
	return found;
}

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