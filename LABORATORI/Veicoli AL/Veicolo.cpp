#include <iostream>
#include <fstream>
using namespace std;

#include "Static_stack.h"
#include "bst.h"
#include "Veicolo.h"



int main(){

	int N = 500;
	StaticStack<Veicolo*> s_auto(N);
	StaticStack<Veicolo*> s_moto(N);
	StaticStack<Veicolo*> s_barca(N);

	ifstream is("Veicoli.txt");
	string type = "";
	string cilindrata = "";
	Veicolo* v;
	for(int i=0; i<N; i++){
		int r=rand()%(3-1+1)+1;
		if(r==1){
			v = new Auto(rand()%(45-9+1)+1);
			s_auto.push(v);
		}if(r==2){
			v = new Moto(rand()%(55-20+1)+1);
			s_moto.push(v);
		}if(r==3){
			v = new Barca(rand()%(50-1+1)+1);
			s_barca.push(v);
		}
	}

	cout << "Stack di oggetti di tipo Auto" << s_auto << endl;
	cout << "Stack di oggetti di tipo Moto" << s_moto << endl;
	cout << "Stack di oggetti di tipo Barca" << s_barca << endl;

	BST<Veicolo*> b_auto;
	BST<Veicolo*> b_moto;
	BST<Veicolo*> b_barca;

	while(s_auto.getTop())
		b_auto.insert(s_auto.pop());

	while(s_moto.getTop())
		b_moto.insert(s_moto.pop());

	while(s_barca.getTop())
		b_barca.insert(s_barca.pop());
	
	cout << "\nBst di oggetti di tipo Auto" << endl;
	b_auto.inOrder();
	cout << "------------------------------------------------------" << endl;
	cout << "\nBst di oggetti di tipo Moto" << endl;
	b_moto.inOrder();
	cout << "------------------------------------------------------" << endl;
	cout << "\nBst di oggetti di tipo Barca" << endl;
	b_barca.inOrder();
	cout << "------------------------------------------------------" << endl;

	/*int val;
	bool okay = false;
	do{
		cout << "\nInserisci un valore di cilindrata: " << endl;
		cin >> val;

		if(cin.fail()){
			cerr << "Errore nell'inserimento di val!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	
		}else
			okay = true;
	}while(!okay);*/
	int val = 30;
	b_auto.remove_below(val);
	b_moto.remove_below(val);
	b_barca.remove_below(val);

	cout << "\nBst di oggetti di tipo Auto" << endl;
	b_auto.inOrder();
	cout << "------------------------------------------------------" << endl;
	cout << "\nBst di oggetti di tipo Moto" << endl;
	b_moto.inOrder();
	cout << "------------------------------------------------------" << endl;
	cout << "\nBst di oggetti di tipo Barca" << endl;
	b_barca.inOrder();
	cout << "------------------------------------------------------" << endl;

}