#include <iostream>
#include <fstream>
using namespace std;

#include "Paziente.h"
#include "Queue.h"

int main(){
    //punto 1
    ifstream file("coda.txt");
    Queue<Paziente> medico1;
    Queue<Paziente> medico2;
    Queue<Paziente> medico3;
    Queue<Paziente> medico4;
    for(int i=0; i<10; i++){
        Paziente p;
        file >> p;
        cout << p << endl;
        if(p.getUrgenza() == 1) medico1.enqueue(p);
        if(p.getUrgenza() == 2) medico2.enqueue(p);
        if(p.getUrgenza() == 3) medico3.enqueue(p);
        if(p.getUrgenza() == 4) medico4.enqueue(p);
    }
    cout << endl;

    //punto 2
    cout << medico1 << endl;
    cout << medico2 << endl;
    cout << medico3 << endl;
    cout << medico4 << endl;

    //punto 3
    medico1.printHead();
    medico2.printHead();
    medico3.printHead();
    medico4.printHead();
    cout << endl;

    //punto 4
    int array[4];
    for(int i=0; i<4; i++){
        if(i == 0) array[i]=medico1.getSize();
        if(i == 1) array[i]=medico2.getSize();
        if(i == 2) array[i]=medico3.getSize();
        if(i == 3) array[i]=medico4.getSize();
        cout << array[i] << endl;
    }

    //punto 5
    DLList<Paziente> dl;
    //dl.insertTail(medico4.dequeue()->getVal());
    //dl.insertTail(medico4.dequeue()->getVal());
    //dl.insertTail(medico4.dequeue()->getVal());
    dl.insertTail(medico4.dequeue()->getVal());
    cout << dl << endl;

    //punto 6
    medico1.rimozione("VLLMTT02T20B429T");
    cout << medico1 << endl;
}