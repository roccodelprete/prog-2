#include <iostream>
#include "lib.hpp"

using namespace std;

int main() {
    int a = 10, b = 20;
	double c = 15.242, d = 89.654;
	char e = 'd', f = 'e';
	swap_var<int>(a, b);
	cout << endl;
    swap_var<double>(c, d);
	cout << endl;
	swap_var<char>(e, f);

	cout << "\nElemento massimo -> " << max_element(c, d) << '\n';
    cout << "\nElemento massimo -> " << max_element(e, f) << '\n';

    show<int, double>(a, c);

	int number_1, number_2;
	calcola<int> *p = new calcola<int>;
	cout << "\nInserisci il primo valore -> ";
	cin >> number_1;
	cout << "Inserisci il secondo valore -> ";
	cin >> number_2;

	cout << number_1 << " + " << number_2 << " = " << p->add(number_1, number_2) << " | " << number_1 << " * " << number_2 << " = " << p->mul(number_1, number_2) << endl;

	delete p;

    return 0;
}