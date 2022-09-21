#include <iostream>
#include <climits>
#include "BSTshape.h"
#include "static_queue.h"
using namespace std;

class Shape{
    public:
        virtual double getArea()=0;
};

class Rectangle : public Shape{
    private:
        double altezza, base, area;

    public:
        Rectangle(double altezza, double base) : Shape(){
            this->altezza=altezza;
            this->base=base;
        }
        Rectangle(double area) : area(area){}
        double getArea(){
            return altezza*base;
        }

};

class Circle : public Shape{
    private:
        double raggio, area;

    public:
        Circle(double raggio) : Shape() {
            this->raggio=raggio;
        }
        Circle(int area) : area(area){}
        double getArea(){
            return raggio*raggio*3.14;
        }
};

class Triangle : public Shape{
    private:
        double altezza, base, area;

    public:
        Triangle(double base, double altezza) : Shape(){
            this->altezza=altezza;
            this->base=base;
        }
        Triangle(double area) : area(area){}
        double getArea(){
            return (altezza*base)/2;
        }
};

int main(){
	int N;
	cout << "\nInserisci N: " << endl;
	cin >> N;

	StaticQueue<Shape*> Rectangle_queue(N);
	StaticQueue<Shape*> Circle_queue(N);
	StaticQueue<Shape*> Triangle_queue(N);
		
	Shape* ptr;
	for(int i=0; i<N; i++){

		switch(rand()%3){

			case(0):	
				ptr = new Rectangle(1.5+rand()%6, 2.2+rand()%3);
				Rectangle_queue.enqueue(ptr);
				break;		

			case(1):	
				ptr = new Circle(1.8+rand()%4);
				Circle_queue.enqueue(ptr);
				break;	

			case(2):	
				ptr = new Triangle(2.5+rand()%3, 1.3+rand()%7);
				Triangle_queue.enqueue(ptr);
				break;
		}
	}

	//Mando in output le tre code
	cout << "\nCoda di rettangoli: \n" << Rectangle_queue << endl;
	cout << "\nCoda di circonferenze: \n" << Circle_queue << endl;
	cout << "\nCoda di triangoli: \n" << Triangle_queue << endl;

	BST<Shape*> bst_unico;

	while(Rectangle_queue.getFirst())
		bst_unico.insert(Rectangle_queue.dequeue());		

	while(Circle_queue.getFirst())
		bst_unico.insert(Circle_queue.dequeue());		

	while(Triangle_queue.getFirst())
		bst_unico.insert(Triangle_queue.dequeue());
		
	//Mando in output il bst
	cout << bst_unico << endl;	

	double val;
	cout << "\nInserire un valore di area: " << endl;
	cin >> val;

	bst_unico.remove_below(val);

	//Confermo l'avvenuta eliminazione dei nodi
	cout << bst_unico << endl;	

}