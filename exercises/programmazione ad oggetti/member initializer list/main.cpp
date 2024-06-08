#include <iostream>
using namespace std;

/* Inizializzazione dati membro costanti non statici */
/*class Test {
	const int i;
public:
	Test(int t) : i(t) {}
	int get_i() {
        return i;
	}
};

int main() {
	Test i1(10);
	cout << "i1 = " << i1.get_i() << endl;
	return 0;
}*/
/* ------------------------------------------------- */

/* Inizializzazione dati membro classe base */
/*class A {
	int i;
public:
	A(int arg) {
		this->i = arg;
		cout << "Costruttore con parametro di A -> i = " << this->i << endl;
	}
};

// classe B derivata da A
class B : public A {
public:
	B(int x) : A(x) {
		cout << "Costruttore con parametro di B..." << endl;
	}
};

int main() {
	B obj(6);

	return 0;
}*/
/* ---------------------------------------- */

/* Inizializzazione dati membro reference */
/*class Test {
	int &i;
public:
	Test(int &t) : i(t) {}
	int get_i() {
		return i;
	}
};

int main() {
	int x;
	cout << "Inserire un valore intero: ";
	cin >> x;

	Test i1(x);
	cout << "i1 = " << i1.get_i() << endl;

	x = 20;
	cout << "i1 = " << i1.get_i() << endl;
	return 0;
}*/
/* -------------------------------------- */

/* Inizializzazione oggetti membro che non hanno costruttore di default */
/*class A {
	int i;
public:
	A(int arg) {
		this->i = arg;
		cout << "Costruttore con parametro di A -> i = " << this->i << endl;
	}
};

class B {
	A a;
public:
	B(int x) : a(x) {
		cout << "Costruttore con parametro di B..." << endl;
	}
};

int main() {
	B obj(10);
	return 0;
}*/
/* -------------------------------------------------------------------- */

/* Inizializzazione quando il nome del parametro del costruttore è lo stesso del dato membro */
/*class A {
	int i;
public:
	A(int i) : i(i) { }
	int get_i() {
		return i;
	}
};

int main() {
	A a(15);
	cout << "a = " << a.get_i() << endl;
	return 0;
}*/
/* ----------------------------------------------------------------------------------------- */