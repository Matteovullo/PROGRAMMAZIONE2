#include <iostream>
#include <fstream>
using namespace std;

#include "Static_stack.h"
#include "BST.h"

class Veicolo{
	protected:
		int cilindrata;
		
	public:
		Veicolo(double cilindrata) : cilindrata(cilindrata){}
		virtual int getCilindrata()=0;
		virtual ostream& put(ostream& os){
			os << "Class=" << typeid(*this).name() << ", cilindrata = " << cilindrata << endl;
			return os;
		}
};

ostream& operator<<(ostream& os, Veicolo& obj){
	return obj.put(os);
}

class Auto : public Veicolo{
	public:
		Auto(double cilindrata) : Veicolo(cilindrata){}
		int getCilindrata(){return cilindrata;}
		ostream& put(ostream& os){
			Veicolo::put(os);
			return os;
		}
};

class Moto : public Veicolo{
	public:
		Moto(double cilindrata) : Veicolo(cilindrata){}
		int getCilindrata(){return cilindrata;}
		ostream& put(ostream& os){
			Veicolo::put(os);
			return os;
		}
};

class Barca : public Veicolo{
	public:
		Barca(double cilindrata) : Veicolo(cilindrata){}	
		int getCilindrata(){return cilindrata;}
		ostream& put(ostream& os){
			Veicolo::put(os);
			return os;
		}
};

int main(){
	//punto 1
	ifstream file("veicoli.txt");
	string s;
	int n=500;
	Veicolo* array[n];
	for(int i=0; i<n; i++){
		string s1="";
		string s2="";
		getline(file, s1, ',');
		getline(file, s2, '\n');
		if(s1 == "AUTO"){
			array[i]=new Auto(atoi(s2.c_str()));
		}
		if(s1 == "MOTO"){
			array[i]=new Moto(atoi(s2.c_str()));
		}
		if(s1 == "BARCA"){
			array[i]=new Barca(atoi(s2.c_str()));
		}
	}

	for(int i=0; i<n; i++){
		cout << *array[i] << endl;
	}
	
	//punto 2
	StaticStack<Auto*> a(1000);
	StaticStack<Moto*> m(1000);
	StaticStack<Barca*> b(1000);
	for(int i=0; i<n; i++){
		if(typeid(*array[i])==typeid(Auto)) a.push(dynamic_cast<Auto*>(array[i]));
		if(typeid(*array[i])==typeid(Moto)) m.push(dynamic_cast<Moto*>(array[i]));
		if(typeid(*array[i])==typeid(Barca)) b.push(dynamic_cast<Barca*>(array[i]));
	}
	cout << a << endl;
	cout << m << endl;
	cout << b << endl;

	//punto 3
	BST<Auto*> bst_a;
	BST<Moto*> bst_m;
	BST<Barca*> bst_b;
	for(int i=0; i<n; i++){
		if(typeid(*array[i])==typeid(Auto)) bst_a.insert(dynamic_cast<Auto*>(array[i]));
		if(typeid(*array[i])==typeid(Moto)) bst_m.insert(dynamic_cast<Moto*>(array[i]));
		if(typeid(*array[i])==typeid(Barca)) bst_b.insert(dynamic_cast<Barca*>(array[i]));
	}
	cout << bst_a << endl;
	cout << bst_m << endl;
	cout << bst_b << endl;
	
	//punto 4
	//cout << bst_a << endl;
	//cout << bst_m << endl;
	//cout << bst_b << endl;
	int c=1000;
	//cout << "Inserire una cilindrata: " << endl;
	bst_a.remove_below(c);
	bst_m.remove_below(c);
	bst_b.remove_below(c);
}