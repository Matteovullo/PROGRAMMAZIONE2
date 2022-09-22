#ifndef FILM
#define FILM

#include<iostream>
using namespace std;

class Film{
    private:
        string titolo;
        int anno;
        double valutazione;

    public:
        Film(){}
        friend istream& operator>>(istream& imput, Film& f){
            string t;
            string a;
            string v;
            getline(imput, t, ';');
            getline(imput, a, ';');
            getline(imput, v, '\n');
            f.titolo=t;
            f.anno=atoi(a.c_str());
            f.valutazione=atof(v.c_str());
            return imput;
        }
        friend ostream& operator<<(ostream& os, Film& f){
            os << f.titolo << ";" << f.anno << ";" << f.valutazione << endl;
            return os;
        }
};

#endif