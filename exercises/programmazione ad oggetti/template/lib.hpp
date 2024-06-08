#include <iostream>
using namespace std;

template <typename type> void swap_var(type &a, type &b){
	cout << "Prima -> var_1 = " << a << " | var_2 =  " << b << '\n';
	type temp = a;
	a = b;
	b = temp;
	cout << "Dopo -> var_1 = " << a << " | var_1 =  " << b << '\n';
}

template <class type> type max_element(type &a, type &b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

template <typename x, typename y> void show(x &a, y &b) {
	cout << "\nPrima variabile = " << a << " | Seconda variabile = " << b <<'\n';
}

template <typename type> class calcola {
public:
	type add(type x, type y) {
		return x + y;
	}
	type mul(type x, type y) {
		return x * y;
	}
};
