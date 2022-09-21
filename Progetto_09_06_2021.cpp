#include <iostream>
using namespace std;

class Veicolo{
	protected:
		int cilindrata;
		
	public:
		Veicolo(double cilindrata) : cilindrata(cilindrata){}
		friend operator>>(istream& os, Veicolo& v){
			string cilindrata;
			getline(os, v.)
		}
};

class Auto : public Veicolo{
	public:
		Auto(double cilindrata) : Veicolo(cilindrata){}
};

class Moto : public Veicolo{
	public:
		Moto(double cilindrata) : Veicolo(cilindrata){}	
};

class Barca : pubic Veicolo{
	public:
		Barca(double cilindrata) : Veicolo(cilindrata){}	
};

int main(){
	ifstream file("Veicolo.txt");
	string s;
	int n=0;
	while(getline(file, s)){
		i++;
	}
	Veicolo* array[n];
	for(int i=0; i<n; i++){
		string s1="";
		string s2="";
		getline(file, s1, ',');
		getline(file, s2, '\n')
		if(s1 == "AUTO"){
			array[i]=new Auto(atoi(s2));
		}
		if(s1 == "MOTO"){
			array[i]=new Moto(atoi(s2));
		}
		if(s1 == "BARCA"){
			array[i]=new Barca(atoi(s2));
		}
	}
	
}