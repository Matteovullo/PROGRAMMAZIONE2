/*5. calcolare il numero di occorrenze di un carattere c in 
una stringa s*/

#include <iostream>

using namespace std;

int occorrenze(string s, char c){
    if(s.length() == 1 && s[0] == c){
        return 1;
    }else{
        int l=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]==c){
                l++;
            }
        }
        if(l==0){
            return -1;
        }else{
            return l;
        }
    }
}

int main(){
    cout << occorrenze("c", 'c') << endl;
    cout << occorrenze("c", 'l') << endl;
    cout << occorrenze("cdfvvvf", 'l') << endl;
    cout << occorrenze("cccddddd", 'c') << endl;
}