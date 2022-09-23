#include <iostream>
#include <fstream>
using namespace std;

class Utente{
    private:
        int numero;
        string nome, cognome;
        double popolarita;

    public:
        Utente(){}
        bool operator<(Utente u){
            return popolarita < u.popolarita;
        }
        friend istream& operator>>(istream& imput, Utente& u){
            string nu, n, m, p;
            getline(imput, nu, ';');
            getline(imput, n, ';');
            getline(imput, m, ';');
            getline(imput, p, '\n');
            u.numero=atoi(nu.c_str());
            u.nome=n;
            u.cognome=m;
            u.popolarita=atof(p.c_str());
            return imput;
        }
        friend ostream& operator<<(ostream& os, Utente& u){
            os << u.numero << ";" << u.nome << ";" << u.cognome << ";" << u.popolarita << endl;
            return os;
        }
};

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(Utente array[], int n) {
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

void insertionSort(Utente array[], int n) {
	Utente temp; 
    int j;
	
	for(int i=1; i < n; i++) {
		temp = array[i];
		for(j=i; j > 0; j--) {
			if(temp < array[j-1])
				array[j] = array[j-1];
			else 
				break;
		}
		array[j] = temp;
	}
}

void printArray(Utente array[], int n) {
	
	for(int i=0; i < n; i++) {
		std::cout << array[i] << "\t";
	}
	std::cout << std::endl;
}

int main(){
    Utente array[2000];
    ifstream file("Utenti.txt");
    for(int i=0; i<2000; i++){
        file >> array[i];
        //cout << array[i] << endl;
    }

    insertionSort(array, 2000);
    //selectionSort(array, 2000);
    printArray(array, 2000);
}