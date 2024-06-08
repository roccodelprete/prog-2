#include "lib.hpp"

int main() {
	Rubrica r;
	short scelta;

	while (scelta != 5)
	{
		cout << "1 - Aggiungi a rubrica" << endl;
		cout << "2 - Rimuovi da rubrica" << endl;
		cout << "3 - Stampa rubrica" << endl;
		cout << "4 - Trova numero" << endl;
		cout << "5 - Exit" << endl << endl;
		cout << "Scelta: ";
		cin >> scelta;
		cout << endl;


		switch (scelta)
		{
			case 1:
				aggiungi_cont(&r);
				break;
			case 2:
				rimuovi_cont(&r);
				break;
			case 3:
				r.print_rubrica();
				break;
			case 4:
				trova_numero_cont(r);
				break;
			case 5:
				break;
			default:
				break;
		}
	}

	return 0;
}