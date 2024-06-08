#pragma once
#include "paymentMethod.cpp"
#include <iostream>
using namespace std;

class paypal: public paymentMethod {
    public:
        void pay(float total) {
            cout << "Pagamento di " << total << " euro con PayPal.\n";
        }
};
