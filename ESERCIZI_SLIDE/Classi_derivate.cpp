#include <iostream>

using namespace std;

class Color{
    private:
        string c;

    public:
        Color(string c){
            this->c=c;
        }
        void print(){
            cout << c << endl;
        }
};

class Shape{
    protected:
        Color color;
    
    public:
        Shape() : color("rosso"){}
        Shape(Color c) : color("rosso"){}
        Color getColor(){
            return color;
        }
        void setColor(Color color){
            this->color=color;
        }
        void print(){
            color.print();
        }
        virtual double area()=0;
};

class Rectangle : public Shape{
    private:
        double height=1.0;
        double width=1.0;
    
    public:
        Rectangle(double, double) : Shape(){}
        Rectangle(double, double, Color) : Shape(){}
        double getHeight(){
            return height;
        }
        void setHeight(double h){
            height=h;
        }
        double getWidth(){
            return width;
        }
        void setWidth(double w){
            width=w;
        }
        bool isASquare(){
            if(width==height)
                return true;
            else
                return false;
        }
        double area(){
            return width*height;
        }
};

class Circle : public Shape{
    private:
        double radius=1;
        double xc=0;
        double yc=0;

    public:
        Circle(double, double, double) : Shape(){}
        Circle(double, double, double, double, Color) : Shape(){}
        double getXc(){
            return xc;
        }
        void setXc(double xc){
            this->xc=xc;
        }
        double getYc(){
            return yc;
        }
        void setYc(double yc){
            this->yc=yc;
        }
        double getRadius(){
            return radius;
        }
        void setRadius(double radius){
            this->radius=radius;
        }
        double getCircumreference(){
            return 3.14*2*radius;
        }
        bool isGoniometric(){
            return true;
        }
        double area(){
            return radius*radius*3.14;
        }
};

class Triangle : public Shape{
    private:
        double base=1;
        double height=1;

    public:
        Triangle(double, double) : Shape(){}
        Triangle(double, double, Color) : Shape(){}
        double getHeight(){
            return height;
        }
        void setHeight(double h){
            height=h;
        }
        double getBase(){
            return base;
        }
        void setBase(double b){
            base=b;
        }
        double area(){
            return (base*height)/2;
        }
};

int main(){
    Shape *array[10];
    for(int i=0; i<10; i++){
        array[i]=new Circle(1.0, 0.0, 0.0);
    }
    for(int i=0; i<10; i++){
        array[i]->print();
    }
    double media=0.0;
    for(int i=0; i<10; i++){
        media+=array[i]->area();
    }
    cout << "media aree: " << media/10 << endl; 
}