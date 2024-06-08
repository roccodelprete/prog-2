#include "lib.hpp"

int main() {
	vettore2D U,V,W;

	U.set_component(2.5f,0.5f); // setto i valori delle componenti del vettore U tramite il metodo set_component
	// e poi le stampo tramite il metodo get_component
	cout << "Ascissa vettore U = " << U.get_component()[0] << endl;
	cout << "Ordinata vettore U = " << U.get_component()[1] << endl << endl;

	V.set_component(1.0f,0.5f);
	cout << "Ascissa vettore V = " << V.get_component()[0] << endl;
	cout << "Ordinata vettore V = " << V.get_component()[1] << endl << endl;

	W = U + V; // effettuo la somma vettoriale tramite l'operatore "+" precedentemente ridefinito
	cout << "Vettore ottenuto tramite somma vettoriale tra i vettori U e V" << endl;
	cout << "\tAscissa vettore W = " << W.get_component()[0] << endl;
	cout << "\tOrdinata vettore W = " << W.get_component()[1] << endl << endl;

	float UV = U * V; // effettuo il prodotto scalare tramite l'operatore "*" precedentemente ridefinito
	cout << "Prodotto vettoriale -> U * V = " << UV << endl;

	return 0;
}