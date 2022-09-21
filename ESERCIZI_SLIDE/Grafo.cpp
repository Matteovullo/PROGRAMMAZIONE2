/*implemnta una grafo*/

#include <iostream>
using namespace std;

template<typename T>
class Vartice{
    private:
        T chiave;

    public:
        Vertice(T chiave) : chiave(chiave){}
        Vertice() : Vertice(NULL){}
        T getChiave(){
            return chiave;
        }
        bool operator==(Vertice<T> v){
            if(v.chiave == chiave) return true;
            else return false;
        }
        friend &ostream operator<<(ostream& os, Vertice<T>& v){
            os << v.chiave;
            return os;
        }

        template<typename U>
        friend class Grafo;
};

template<typename T>
class Grafo{
    private:
        Vertice<T>** vertici;
        bool** adiacente;
        int massima_dimensione=0;
        int nVertici=0;

    public:
        Grafo(int massima_dimensione) : massima_dimensione(massima_dimensione){
            vertici = new Vertice<T>*[massima_dimensione];
            adiacente=new bool*[massima_dimensione];
            for(int i=0; i<massima_dimensione; i++){
                adiacente[i]=new bool[massima_dimensione];
                for(int j=0; j<massima_dimensione; j++){
                    adiacente[i][j]=false;
                }
            }
        }
        void aggiungiVertie(T chiave){
            if(massima_dimensione == nVertici){
                return;
            }
            vertici[nVertici++]=new Vertice<T>(chiave);
        }
        void aggiungereCollegamento(T chiave1, T chiave2){
            int i=ricerca(chiave1);
            int j=ricerca(chiave2);
            if(i!=-1 && j!=-1){
                adiacente[i][j]=true;
                adiacente[j][i]=true;
            }else{
                return;
            }
        }
        int ricerca(T chiave){
            if(nVertici=0){
                return -1;
            }
            for(int i=0; i<nVertici; i++){
                if(vertici[i]->chiave == chiave){
                    return i;
                }
            }
            return -1;
        }
        friend ostream& operator<<(ostream& os, Grafo<T>& g){
            for(int i=0; i<g.nVertici; i++){
                out << "v[" << i << "]=" << *g.vertici[i] << "\t";
            }
            os <<endl;
		    for(int i = 0; i < g.nVertici; i++) {
			    for(int j = 0; j < g.nVertici; j++) {
				    if(g.adiacenza[i][j])
					os << "(" << i << ", " << j << ")" << endl;
			    }
		    }
            return os;
        }
};