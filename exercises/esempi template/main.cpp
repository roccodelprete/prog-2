#include <iostream>
#include "template.hpp"

using namespace std;

int main() {
    int a = 10, b= 20;
    cout << "Prima\n\ta = " << a << ", b =  " << b << '\n';
    swap_var<int>(a, b);
    cout << "Dopo\n\ta = " << a << ", b =  " << b << '\n';

    double c = 15.242, d = 89.654;
    cout << "\nPrima\n\tc = " << c << ", d =  " << d << '\n';
    swap_var<double>(c, d);
    cout << "Dopo\n\tc = " << c << ", d =  " << d << '\n';
    cout << "\nElemento massimo -> " << max_element(c, d) << '\n';

    char e = 'd', f = 'e';
    cout << "\nPrima\n\te = " << e << ", f =  " << f << '\n';
    swap_var<char>(e, f);
    cout << "Dopo\n\te = " << e << ", f =  " << f << '\n';
    cout << "\nElemento massimo -> " << max_element(e, f) << '\n';

    show<int, double>(a, c);

	int number_1, number_2;
	calcola<int> *p = new calcola<int>;
	cout << "\nInserisci il primo valore -> ";
	cin >> number_1;
	cout << "Inserisci il secondo valore -> ";
	cin >> number_2;

	cout << "Risultato addizione -> " << p->add(number_1, number_2) << " | Risultato moltiplicazione -> " << p->mul(number_1, number_2) << '\n';

	delete p;

    return 0;
}
