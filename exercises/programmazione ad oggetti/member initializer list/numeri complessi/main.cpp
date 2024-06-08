#include <iostream>

using namespace std;

class Complex {
private:
	double Re;
	double Im;
public:
	/* costruttore di default con lista di inizializzazione dei membri che verranno inizializzati a 0
	se viene utilizzato questo costruttore */
	Complex() : Re(0), Im(0) {}
	// costruttore con parametri che inizializza i membri ai valori double passati dal chiamante
	Complex(double a, double b) : Re(a), Im(b) {}
	// costruttore di copia a cui passo i valori dell'oggetto(z) con cui si chiama il costruttore di copia
	Complex(Complex &z) : Re(z.Re), Im(z.Im) {}
	// metodi "get" per prendere i valori dei singoli membri
	double getReal() {
		return this->Re;
	}
	double getImag() {
		return this->Im;
	}
};


int main() {
	Complex Z1; // utilizzo il costruttore di default che inizializza a 0 i campi dell'oggetto
	cout << "Z1 = " << Z1.getReal() << " + " << Z1.getImag() << "i" << endl;

	// utilizzo il costruttore con parametri che inizializza al valore passato i campi dell'oggetto
	Complex Z2(1.5,2.37);
	cout << "Z2 = " << Z2.getReal() << " + " << Z2.getImag() << "i" << endl;

	// utilizzo il costruttore di copia che prende in input un altro oggetto della stessa classe e ne copia i valori
	Complex Z3(Z2);
	cout << "Z3 = " << Z3.getReal() << " + " << Z3.getImag() << "i" << endl;

	return 0;
}