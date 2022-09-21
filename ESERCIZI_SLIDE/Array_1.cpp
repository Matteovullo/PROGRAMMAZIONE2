/*Scrivere un programma che sfrutta un metodo ‘leggiElementi()’ per inizializzare un array
di double di dimensione non nota, chiedendo all’utente di inserire un valore per volta
fino a quando non viene inserito il valore zero. Successivamente, stampare gli elementi
mediante un altro metodo ‘stampaElementi()’*/

#include <iostream>
using namespace std;

#define n 100

void leggiElementi(double* vet, int& c){
	
	//cout<<"Indirizzo c in leggiElementi: "<<&c<<endl;
	c=0;
	double temp;
	for(int i=0; i<n; i++)
	{
		cout<<"Inserisci un elemento (0 per terminare l'inserimento): "<<endl;
		cin>>temp;
		if(temp == 0)
			break;
		else
			vet[i] = temp;
			c++;
	}
}

void stampaElementi(double* v, int c){
	for(int i=0; i<c; i++)
		cout<<"Elemento n"<<i<<" :"<<v[i]<<endl;
	
	cout<<endl;
}

int main(){
	double vet[n];
	int c;
	//cout<<"Indirizzo c nel main: "<<&c<<endl;
	leggiElementi(vet, c);
	stampaElementi(vet, c);
}