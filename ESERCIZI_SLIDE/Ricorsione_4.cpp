/*4. Calcolare il MCD tra due interi dati in input*/

#include <iostream>

using namespace std;

/*int MCD(int m, int n){
    if(n <= m && n%m==0){
        return n;
    }else if(m < n){
        return MCD(n, m);
    }else{
        return MCD(n, m%n);
    }
}*/

int mcd(int a, int b){
   return b==0 ? a : mcd(b,a%b);
}

int main(){
    cout << mcd(10, 10) << endl;
    cout << mcd(2, 10) << endl;
}