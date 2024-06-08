#include "lib.h"

void veicolo::show() {
	cout << "Veicolo(classe base)" << endl;
	cout << "\tRuote: " << get_ruote() << endl;
	cout << "\tPasseggeri: " << get_pass() << endl;
}

void camion::show() {
	cout << "Camion" << endl;
	cout << "\tRuote: " << get_ruote() << endl;
	cout << "\tPeso: " << get_peso() << endl;
	cout << "\tPasseggeri: " << get_pass() << endl;
}

void automobile::show() {
	vector<string> t;

	t.push_back("utilitaria");
	t.push_back("berlina");
	t.push_back("suv");

	cout << "Automobile(classe base)" << endl;
	cout << "\tTipo: " << t.at(get_tipo()) << endl;
	cout << "\tRuote: " << get_ruote() << endl;
	cout << "\tPasseggeri: " << get_pass() << endl;
}