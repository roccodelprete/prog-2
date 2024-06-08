#include <iostream>
#include <bitset>
using namespace std;

int main(){
	/* test di set() e flip() */
	/*
	bitset <8> bits;    //viene definito un array di 8 bit (0..7)
	bits.set(0);    //setta il primo bit a 1
	bits.flip(7);   //esegue la complementazione del bit n°7
	cout<<"bits="<<bits;
	*/
	/*------------------------*/

	/* invertire l'ordine di una stringa di bit */
	bitset <8> binary_number;
	bitset <8> binary_number_inverted;
	int n=8;
	binary_number[1]=1;
	cout<<"binary number: "<<binary_number<<endl;
	for(int i=0; i<n-1; i++)
		binary_number_inverted[n-1-i]=binary_number[i];
	cout<<"binary number inverted: "<<binary_number_inverted<<endl;
	/*------------------------------------------*/
	return 0;
}