/*Scrivere una funzione di conversione che riceva come parametro una stringa
rappresentante una data in formato gg/mm/aa e la restituisca nel formato testuale, es:
17/11/91 --> 17 novembre 1991*/

#include <iostream>

using namespace std;

void conversione(string s){
    for(int i=0; i<s.length(); i++){
        if(s[i] == '/' && i==2){
            for(int j=0; j<i; j++){
                cout << s[j];
            }
        }
        if(s[i] == '/' && i==5){
            string aux="";
            for(int j=3; j<i; j++){
                aux+= s[j];
            }
            if(aux == "01"){
                cout << "gennaio";
            }
            if(aux == "02"){
                cout << "febbraio";
            }
            if(aux == "03"){
                cout << "marzo";
            }
            if(aux == "04"){
                cout << "aprile";
            }
            if(aux == "05"){
                cout << "maggio";
            }
            if(aux == "06"){
                cout << "giugno";
            }
            if(aux == "07"){
                cout << "luglio";
            }
            if(aux == "08"){
                cout << "agosto";
            }
            if(aux == "09"){
                cout << "settembre";
            }
            if(aux == "10"){
                cout << "ottobre";
            }
            if(aux == "11"){
                cout << "novembre";
            }
            if(aux == "12"){
                cout << "dicembre";
            }
        }
        cout << " ";
        if(i==6){
            string aux="";
            aux+=s[6];
            aux+=s[7];
            if(aux[0] == '9'){
                cout << "19" << aux << endl;
            }else if(aux[0] == '0'){
                cout << "20" << aux << endl;
            }
        }
    }
}

int main(){
    string data="20/11/00";
    conversione(data);
}