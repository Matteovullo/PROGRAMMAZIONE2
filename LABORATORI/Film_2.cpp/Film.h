#ifndef FILM
#define FILM

#include<iostream>
using namespace std;

class Film{
    string nome;
    string tipo;
    string data;
    int giorno, mese, anno;

    public:
        Film(){}
        string getTipo(){return tipo;}
        int getAnno(){return anno;}
        bool operator==(Film f){
            return tipo==f.tipo;
        }
        bool operator<=(Film f){
            return anno<=f.anno;
        }
        bool operator>=(Film f){
            return anno>=f.anno;
        }
        friend istream& operator>>(istream& imput, Film& f){
            string n, t, d;
            getline(imput, t, ';');
            getline(imput, n, ';');
            getline(imput, d, '\n');
            f.nome=t;
            f.tipo=n;
            f.data=d;
            string a, m, g;
            for(int i=0; i<9; i++){
                if(i>=0 && i<=3){
                    a+=f.data[i];
                }
                if(i>=5 && i<=6){
                    m+=f.data[i];
                }
                if(i==8 || i==9){
                    g+=f.data[i];
                }
            }
            f.anno=atoi(a.c_str());
            f.mese=atoi(m.c_str());
            f.giorno=atoi(m.c_str());
            return imput;
        }
        friend ostream& operator<<(ostream& os, Film& f){
            os << f.nome << ";" << f.tipo << ";" << f.data << endl;
            os << f.anno << "-" << f.mese << "-" << f.giorno << endl;
            return os;
        }
};

#endif