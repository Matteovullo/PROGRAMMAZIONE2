/*Definire una classe Punto2D e utilizzarla per definire una classe Rettangolo
simile a quella precedente. In particolare la nuova classe Rettangolo dovrà:
• avere due attributi top_left e bottom_right di tipo Punto2D
• prevedere i seguenti metodi:
• contiene(Punto2D p) restituisce vero se p si trova dentro l'area del
rettangolo chiamante
• contiene(Rettangolo r) restituisce vero se r è contenuto nel
rettangolo chiamante
Inoltre, definire le classi Punto2D e Rettangolo in modo tale che sia possibile
istanziare due oggetti, uno di tipo Punto2D e l’altro di tipo rettangolo nel
seguente modo:
Punto2D p = {10,20}
Rettangolo B({10,20},{50,10});
dove:
• {10,20} rappresenta un oggetto Punto2D di coordinate x=10 y=20
• {50,10} rappresenta un oggetto Punto2D di coordinate x=50 y=10*/

#include <iostream>
#include <cmath>

using namespace std;

class Punto2D{
    private:
        double x, y;

    public:
        Punto2D(){
            x=0;
            y=0;
        }
        Punto2D(int x, int y){
            this->x=x;
            this->y=y;
        }
        double getX(){
            return x;
        }
        double getY(){
            return y;
        }
};

class Rettangolo{
    private:
        Punto2D top_left, botton_right;
        double base, altezza;

    public:
        Rettangolo(){
            base=0;
            altezza=0;
        }
        Rettangolo(double base, double altezza, double x, double y, double x1, double y1) : top_left(x, y), botton_right(x1, y1){
            this->base=base;
            this->altezza=altezza;
        }
        Rettangolo(Punto2D p1, Punto2D p2) : top_left(p1), botton_right(p2){}
        double perimetro(){
            return (base+altezza)*2;
        }
        double area(){
            return base*altezza;
        }
        double diagonale(){
            return sqrt((altezza*altezza)+(base*base));
        }
        bool verifica_quadrato(){
            if(altezza == base){
                return true;
            }else{
                return false;
            }
        }
        void setter(double altezza, double base){
            this->base=base;
            this->altezza=altezza;
        }
        double getX_l(){
            return top_left.getX();
        }
        double getY_l(){
            return top_left.getY();
        }
        double getX_r(){
            return botton_right.getX();
        }
        double getY_r(){
            return botton_right.getY();
        }
        double get_Base(){
            return base;
        }
        double get_Altezza(){
            return altezza;
        }
        bool contiene_p(Punto2D p){
            if(p.getX() < top_left.getX() && p.getX() > top_left.getY() && p.getY() > botton_right.getX() && p.getY() < botton_right.getY()){
                return true;
            }
        }
        bool contiene_r(Rettangolo r){
            if(r.getX_l() < top_left.getX() && r.getY_l() > top_left.getY() && r.getX_r() > botton_right.getX() && r.getY_r() < botton_right.getY()){
                return true;
            }
        }
};

int main(){
    Punto2D p={10, 20};
    Rettangolo B{{10, 20}, {50, 10}};
}