#pragma once
#include "paymentMethod.cpp"
#include <iostream>
using namespace std;

class creditCard: public paymentMethod {
    public:
        void pay(float total) {
            cout << "Pagamento di " << total << " euro con carta di credito.\n";
        }
};
