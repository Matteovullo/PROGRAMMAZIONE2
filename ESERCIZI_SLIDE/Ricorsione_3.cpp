/*3. Generare il n-esimo numero della serie di Fibonacci 
e stampare la sequenza fino ad n*/

#include <iostream>

using namespace std;

int stampaFibonacci(int n){
    int primo=0, secondo=1, temp;
    if(n<=1) cout << n << endl;
    cout << primo << endl;
    cout << secondo << endl;
    for(int i=2; i<=n; i++){
        temp=primo;
        primo=secondo;
        secondo=primo+temp;
        cout << secondo << endl;
    }
    cout << "Numero " << n << " della serie di fibonacci è: " << secondo << endl;
    return secondo;
}

int main(){
    stampaFibonacci(6);
}