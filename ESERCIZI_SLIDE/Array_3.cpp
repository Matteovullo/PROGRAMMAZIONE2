/*Scrivere un programma che legga una frase, sostituisca tutte le sequenze di uno o due
spazi con uno spazio singolo e visualizzi la frase risultante.*/

#include <iostream>

using namespace std;

void leggiFrase(string s){
    int c=0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            c++;
        }else{
            c=0;
        }
        if(c==2){
            s.erase(i-1, 1);
        }
    }
    cout << s << endl;
}

int main(){
    cout << sizeof("ciao come stai") << endl;
    cout << sizeof("ciao come  stai") << endl;
    cout << "ciao come  stai" << endl;
    leggiFrase("ciao come  stai");
}