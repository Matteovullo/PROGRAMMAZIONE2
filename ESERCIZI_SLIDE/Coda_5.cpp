/*coda dinamica con lista*/

#include <iostream>
using namespace std;

#include "List.h"

template<typename T>
class Coda : protected List<T>{
    private:
        int dim=0;

    public:
        Coda() : List<T>(){}
        bool vuoto(){
            if(dim==0) return true;
            else return false;
        }
        void enqueue(T val){
            List<T>::insertTail(val);
            dim++;
        }
        void dequeue(){
            if(vuoto()) return;
            List<T>::removeHead();
            dim--;
        }
        friend ostream& operator<<(ostream& out, Coda<T>& queue) {
		out << "Queue starting at " << &(queue.head) << endl;
		Node<T> *ptr = queue.head;
		while(ptr) {
			out << *ptr << std::endl;
			ptr = ptr->getNext();
		}
		return out;
	    }
};

int main(){
    Coda<int> c;
    c.enqueue(1);
    c.enqueue(2);
    cout << c << endl;
    c.dequeue();
    cout << c << endl;
}