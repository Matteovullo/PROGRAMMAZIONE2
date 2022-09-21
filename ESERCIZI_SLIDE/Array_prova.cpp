#include <iostream>

using namespace std;

int main(){
    int numeri[100]={};

    for(int i=0; i<100; i++){
        cout << numeri[i] << endl;
    }

    char str[]="Helloworld";
    str[5]='\0';
    cout << str << endl;
    cout << str[9] << endl;


    cout << numeri[130] << endl;
}