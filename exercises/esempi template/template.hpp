#include <iostream>
using namespace std;

template <typename type> void swap_var(type &a, type &b){
    type temp = a;
    a = b;
    b = temp;
}

template <class x> x max_element(x &a, x &b) {
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
	type add(type x, type y);
	type mul(type x, type y);
};

template <typename type>
type calcola<type>::add(type x, type y) {
	return x + y;
}
template <typename type>
type calcola<type>::mul(type x, type y) {
	return x * y;
}
