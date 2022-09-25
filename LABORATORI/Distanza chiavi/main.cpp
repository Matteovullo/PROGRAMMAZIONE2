#include<iostream>
#include<fstream>
using namespace std;

//Includo l'header
#include "bst.h"

int main(){
	cout << endl;

    ifstream is("Imput.txt");

    //int 10 ins:80 ins:172 ins:13 ins:138 ins:223 ins:245 ins:144 ins:152 ins:151 ins:270 151 138
 
    for(int i=0; i<6; i++)  //creazione di 6 oggetti di tipo BST
    {
		string type; //tipo del template generico "H"
		is >> type;
		int N; //numero di elementi da inserire nel BST
		is >> N;

		if(type == "int") //se il tipo è int istanzio un BST<int>
		{
			BST<int> b; 
			for(int i=0; i<N; i++) //eseguo N operazioni di inserimento
			{
			    string toinsert; //elemento da inserire
			    is >> toinsert;
			    //toinsert = toinsert.substr(toinsert.find(":")+1, toinsert.length());
			    toinsert = toinsert.erase(0, 4); //elimino "ins:"
			    b.insert(atoi(toinsert.c_str()));
			}

			cout << b << endl;

			//Chiavi k e h delle quali devo controllare la distanza
			string k;
			string h;
			is >> k;
			is >> h;

			cout<<"\n\nDistanza fra " << k << " e " << h << " = " << b.distanzaChiavi(atoi(k.c_str()), atoi(h.c_str())) << endl;
      	}
	    else //se il tipo è char istanzio un BST<char>
		{
	        BST<char> b;
	        for(int i=0; i<N; i++)
	        {
	            string toinsert;
	            is >> toinsert;
			    toinsert = toinsert.erase(0, 4); //elimino "ins:"
	            b.insert(toinsert[0]); //inserisco il primo carattere (l'unico) della stringa
	        }

	        b.inorder();

	        char k = 0;
	        char h =0;
	        is >> k;
	        is >> h;

	        cout<<"\n\nDistanza fra " << k << " e " << h << " = " << b.distanzaChiavi(k,h) << endl;
	    }

	    cout << "\n-------------------------------------------------------------\n";
	}

    cout << endl;
}