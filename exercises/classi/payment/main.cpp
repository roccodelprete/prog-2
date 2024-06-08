#include "paymentMethod.cpp"
#include "paypal.cpp"
#include "creditCard.cpp"
#include "bitcoin.cpp"

using namespace std;

void execute_payment(float total, paymentMethod *pm) {
    pm->pay(total);
}

int main() {
    float total = 1983.89f;
    int payment_method = 0;
    paypal ppl;
    creditCard cc;
    bitcoin btc;

    execute_payment(total, &ppl);
    execute_payment(total, &cc);
    execute_payment(total, &btc);

    return 0;
}
