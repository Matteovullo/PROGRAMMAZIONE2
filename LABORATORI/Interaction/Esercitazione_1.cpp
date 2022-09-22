/*Si supponga di avere un array interaction I e un array timestamp T, contenenti rispettivamente le 
interazioni ottenute postando un determinato contenuto su un social (+1 per ogni interazione positiva, -
1 per ogni interazione negativa) ed un intero che rappresenta il tempo (in minuti) di pubblicazione dell’iesimo post pubblicato. La popolarità di un utente è determinata da una combinazione lineare della 
frequenza F e di uno score derivato dalle interazioni S, secondo la seguente formula:
𝑃 = 𝛼 ∗ 𝑆 + (1 − 𝛼) ∗ 𝐹
con 𝛼 = 0.66, e S ed F sono calcolati come segue:
𝑆𝑡 =
1
4
∗ 𝐼𝑡−3 +
1
3
∗ 𝐼𝑡−2 +
1
2
∗ 𝐼𝑡−1 + 𝐼𝑡
𝐹𝑡 =
1
𝑛
∑(𝑇𝑡 − 𝑇𝑡−1
)
𝑛
𝑡=1
Scrivere un programma che, dati gli array I e T in input, calcoli la popolarità dell’utente ad ogni istante t, 
e ne individui il periodo di massima popolarità*/

#include <iostream>

using namespace std;
#define n 100
const double alpha=0.66;

double S(double interaction[]){
    int s=0;
    for(int i=n; i>=0; i--){
        if(interaction[i]!=0){
            s+=(1/(double)i)*interaction[i];
        }
    }
    return s;
}

double F(double timestamp[]){
    int c=0;
    double sommatoria=0;
    for(int i=1; i<n; i++){
        if(timestamp[i] != 0){
            c++;
            sommatoria+=timestamp[i]-timestamp[i-1];
        }
    }
    return 1/(double)c*(sommatoria);
}

double popolarita(double s[], double t[]){
    return (alpha*S(s))+((1-alpha)*F(t));
}

int main(){
    double a[n]{1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1};
    double b[n]{10, 20, 30, 50, 10, 5, 2, 6, 10};
    cout << popolarita(a, b) << endl;
}