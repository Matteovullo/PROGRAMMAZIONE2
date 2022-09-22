#ifndef RECUPERO_INFORMAZIONI
#define RECUEPERO_INFORMAZIONI

#include "List.h"
#include "Giocatori.h"

void r(Giocatore* array, List& l, int n){
    for(int i=0; i<n; i++){
        l.insertTail(array[i]);
    }
}

void ordinamento(List& l, char c){
    if(c=='c') l.crescente();
    if(c=='d') l.decrescente();
    return;
}

void informazioni(List& l, string s){
    l.get_info(l, s);
}

void rimozione(List& l, double d){
    l.remove_player(l, d);
}

#endif