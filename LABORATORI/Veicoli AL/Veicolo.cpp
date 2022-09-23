#include <iostream>
#include <fstream>
using namespace std;

#include "Static_stack.h"
#include "BST.h"

class Veicolo{
	protected:
		int cavalli;
		
	public:
		Veicolo(double cavalli) : cavalli(cavalli){}
		virtual int getCilindrata()=0;
		virtual ostream& put(ostream& os){
			os << "Class=" << typeid(*this).name() << ", cilindrata = " << cavalli << endl;
			return os;
		}
};

ostream& operator<<(ostream& os, Veicolo& obj){
	return obj.put(os);
}

class Auto : public Veicolo{
	public:
		Auto(double cilindrata) : Veicolo(cilindrata){}
		int getCilindrata(){return cavalli;}
		ostream& put(ostream& os){
			Veicolo::put(os);
			return os;
		}
};

class Moto : public Veicolo{
	public:
		Moto(double cilindrata) : Veicolo(cilindrata){}
		int getCilindrata(){return cavalli;}
		ostream& put(ostream& os){
			Veicolo::put(os);
			return os;
		}
};

class Barca : public Veicolo{
	public:
		Barca(double cilindrata) : Veicolo(cilindrata){}	
		int getCilindrata(){return cavalli;}
		ostream& put(ostream& os){
			Veicolo::put(os);
			return os;
		}
};

int main(){
	//punto 1
	int n=100;
	Veicolo** array=new Veicolo*[n];
	for(int i=0; i<n; i++){
        int r=rand()%(3)+1;
		if(r == 1){
			array[i]=new Auto(rand()%(45-9+1)+9);
		}
		if(r == 2){
			array[i]=new Moto(rand()%(55-20+1)+20);
		}
		if(r == 1){
			array[i]=new Barca(rand()%(50-1+1)+1);
		}
	}

	for(int i=0; i<n; i++){
		cout << array[i] << endl;
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
	int c=2000;
	//cout << "Inserire una cilindrata: " << endl;
	//bst_a.remove_below(c);
	//bst_m.remove_below(c);
	//bst_b.remove_below(c);
}