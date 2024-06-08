#pragma once
#include "payment_method.cpp"
#include <iostream>
using namespace std;

class paypal : public payment_method {
public:
	void pay(float total) {
		cout << "Pagamento di " << total << " euro con PayPal.\n";
	}
};
