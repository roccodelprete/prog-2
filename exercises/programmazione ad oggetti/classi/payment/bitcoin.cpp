#pragma once
#include "payment_method.cpp"
#include <iostream>

using namespace std;

class bitcoin: public payment_method {
public:
	void pay(float total) {
		cout << "Pagamento di " << total << " euro con Bitcoin.\n";
	}
};
