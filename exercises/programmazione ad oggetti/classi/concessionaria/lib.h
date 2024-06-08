#include <iostream>
#include <vector>
#include <string>

using namespace std;

// classe base
class veicolo {
	int numRuote;
	int numPasseggeri;

public:
	void set_ruote(int n) { numRuote = n; }
	int get_ruote() { return numRuote; }
	void set_pass(int n) { numPasseggeri = n; }
	int get_pass() { return numPasseggeri; }
	virtual void show();
};

// classe derivata
class camion : public veicolo {
	int peso_rimorchio; // attributo privato

public:
	void set_peso(int w) { peso_rimorchio = w; }
	int get_peso() { return peso_rimorchio; }
	void show();
};

// definisco un nuovo tipo tramite enum
typedef enum {utilitaria, berlina, suv} tipo;

// classe derivata
class automobile : public veicolo {
	tipo tipo_auto; // attributo privato

public:
	void set_tipo(tipo t) { tipo_auto = t; }
	int get_tipo() { return tipo_auto; }
	void show();
};