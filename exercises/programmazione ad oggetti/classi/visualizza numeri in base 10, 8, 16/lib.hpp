#include <iostream>
using namespace std;

// dichiaro e implemento una classe astratta; non si possono istanziare oggetti di classe astratta
class number {
protected: // attributo protected
	int val;

public: // metodi pubblici
	void setval(int i) { val = i; }
	virtual void show() = 0; // funzione virtuale pura
};

// definisco e implemento una classe derivata per stampare un numero in esadecimale
class hextype : public number {

public:
	void show() { // overriding del metodo show della classe base
		cout << "hex = " << hex << val << endl;
	}
};

// definisco e implemento una classe derivata per stampare un numero in decimale
class dectype : public number {

public:
	void show() { // overriding del metodo show della classe base
		cout << "dec = " << val << endl;
	}
};

// definisco e implemento una classe derivata per stampare un numero in ottale
class octtype : public number {

public:
	void show() { // overriding del metodo show della classe base
		cout << "oct = " << oct << val << endl;
	}
};