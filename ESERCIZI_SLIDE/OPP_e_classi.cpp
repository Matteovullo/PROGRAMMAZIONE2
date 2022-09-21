/*Definire una classe Rettangolo con i seguenti requisiti funzionali:
• Attributi base e altezza privati, ma accessibili tramite getter/setter.
• Il costruttore prende la base e l’altezza come parametri, in alternativa
imposta due valori di default.
• Implementare delle funzioni membro pubbliche per il calcolo di area,
perimetro e diagonale
• Implementare una funzione membro che verifica se si tratta di un quadrato
Definire un metodo main() dove vengono istanziati alcuni oggetti Rettangolo
per testare le funzionalità della classe.
Hint: utilizzare in maniera opportuna i diversi modi per definire un costruttore
ed il qualificatore const.*/

#include <iostream>
#include <cmath>

using namespace std;

class Rettangolo{
    private:
        double base, altezza;

    public:
        Rettangolo(){
            base=0;
            altezza=0;
        }
        Rettangolo(double base, double altezza){
            this->base=base;
            this->altezza=altezza;
        }
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
        double get_Base() const{
            return base;
        }
        double get_Altezza() const{
            return altezza;
        }
};

int main(){
    Rettangolo r1;
    Rettangolo r2(2.0, 3.0);
    cout << r1.get_Altezza() << endl;
    cout << r2.get_Altezza() << endl;
    cout << r1.get_Base() << endl;
    cout << r2.get_Base() << endl;
    cout << r1.area() << endl;
    cout << r2.area() << endl;
    cout << r1.perimetro() << endl;
    cout << r2.perimetro() << endl;
    cout << r1.diagonale() << endl;
    cout << r2.diagonale() << endl;
}