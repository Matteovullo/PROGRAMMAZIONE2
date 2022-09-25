#ifndef VEICOLO_H
#define VEICOLO_H

#include<typeinfo>
#include<iostream>

class Veicolo{
	protected:
		int cavalli;
		
	public:
		Veicolo(int cavalli):cavalli(cavalli){}
		Veicolo(){}
        friend ostream& operator<<(ostream& os, const Veicolo& obj){
            os << "Tipo:" << typeid(obj).name() << ", cilindrata= " << obj.cavalli << endl;
            return os;
        }
		int getCilindrata(){return this->cavalli;}
};

class Auto : public Veicolo{
	public:
		Auto(int cavalli) : Veicolo(cavalli){}
};

class Moto : public Veicolo{
	public:
		Moto(int cavalli) : Veicolo(cavalli){}
};

class Barca : public Veicolo{
	public:
		Barca(int cavalli) : Veicolo(cavalli){}	
};

#endif