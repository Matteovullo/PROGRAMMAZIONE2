/*implementa un grafo con liste*/

#include <iostream>
#include "13_list.h"

template<typename T>
class GrafoVertice : public List<T>{
    protected
        bool verbose;

    public:
        GrafoVertice(T chiave, bool verbose=false) : List<T>(verbose){
            List<T>::insert(chiave);
        }
        friend ostream& operator<<(ostream& out, GrafoVertice<T>& v){
            if(v.verbose) {
			out << "Graph Vertex with key " << v.head->getVal() << ": " << std::endl;
			out << "\tAdjacency List: ";
			Node<T> *ptr = v.getHead();
			while(ptr) {
				out << " -> " << ptr->getVal() ;
				ptr = ptr->getNext();
			}
		}
		else {
			Node<T> *ptr = v.getHead();
			out << ptr->getVal() << ": ";
			if(ptr->getNext()) {
				ptr = ptr->getNext();
				while(ptr->getNext()) {
					out << ptr->getVal() << ", ";
					ptr = ptr->getNext();
				}
				out << ptr->getVal();
			}
			else 
				out << "/";
		}
		
		    return out;
        } 
};

template<typename T>
class GrafoLista{
    List<GrafoVertice<T>> vertici;
    int nVertici=0;
    bool orientato;
    bool verboso;

    public:
        GrafoLista(bool verboso=false; bool orientato=true) : orientato(orientato), verboso(verboso){}
        void aggiungereVertice(T chiave){
            GrafoVertice<T> aggiungere(chiave, verbose)
            vertici.insertTail(aggiungere);
            nVertici++;
        }
        void aggingereArco(T chiave1, T chiave2){
            Node<GrafoVertice<T>> *nodo1=ricerca(chiave1);
            Node<GrafoVertice<T> *nodo2=ricerca(chiave2);
            if(nodo1 && nodo2){
                nodo->getVal().insertTail(chaive2);
                if(!orientato){
                    node2->getVal().insertTail(chiave2);
                }
            }
        }
        Node<GrafoVertice<T>>* ricerca(T chiave){
            if(nVertici==0){
                return nullptr;
            }
            Node<GrafoVertice<T>> *ptr=vertici.getHead();
            while(ptr){
                if(key==ptr->getVal().getHead()->getVal()){
                    return ptr;
                }
                ptr=ptr->getNext();
            }
            return nullptr;
        }
        friend ostream& operator<<(ostream& out, GraphList<T>& g) {
			out << g.vertices;
			return out;
		}
};