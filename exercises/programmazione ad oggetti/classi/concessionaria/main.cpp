#include "lib.h"

int main() {
	veicolo v1;
	camion c1;
	automobile a1;

	veicolo *p1 = &v1;
	p1->set_ruote(2);
	p1->set_pass(2);
	p1->show();
	cout << endl;

	camion *p2 = &c1;
	p2->set_ruote(8);
	p2->set_peso(3000);
	p2->set_pass(2);
	p2->show();
	cout << endl;

	automobile *p3 = &a1;
	p3->set_tipo(utilitaria);
	p3->set_pass(5);
	p3->set_ruote(4);
	p3->show();

	return 0;
}