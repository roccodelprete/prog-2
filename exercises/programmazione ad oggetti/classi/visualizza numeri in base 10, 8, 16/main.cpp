#include "lib.hpp"

int main() {
	// dichiaro oggetti di classi derivate e un puntatore di classe base p
	number *p; hextype h; dectype d; octtype o;

	// utilizzo un puntatore alla classe base per puntare ad oggetti delle classi derivate
	p = &d;
	p->setval(15);
	p->show();

	p = &h;
	p->setval(15);
	p->show();

	p = &o;
	p->setval(15);
	p->show();

	return 0;
}
