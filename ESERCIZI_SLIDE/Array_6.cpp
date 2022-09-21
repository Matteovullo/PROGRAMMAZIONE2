/*Definire un programma che visualizzi il triangolo di Pascal*/

#include <stdio.h>

#define N 10

int main()
{
  /* dichiarazione delle variabili */
  int r, c, TT[N][N];
  
  /* inizializzo la prima riga */
  TT[0][0] = 1;
  for ( c=1 ; c<N ; c++ )
    TT[0][c] = 0;

  /* calcolo le righe successive */
  for ( r=1 ; r<N ; r++ )
  {
    TT[r][0] = 1;
    for ( c=1 ; c<N ; c++ )
      TT[r][c] = TT[r-1][c-1] + TT[r-1][c];
  }

  /* stampa */
  for ( r=0 ; r<N ; r++ )
  {
    /* scrivo i numeri della riga r-ma */
    for ( c=0 ; c<=r ; c++ )
      printf("%6d", TT[r][c]); /* "%6d" occupa 6 spazi */
    /* fine della riga r-ma */
    printf("\n");
  }

  return 0;
}