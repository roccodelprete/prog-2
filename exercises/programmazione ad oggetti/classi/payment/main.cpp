#include "payment_method.cpp"
#include "paypal.cpp"
#include "credit_card.cpp"
#include "bitcoin.cpp"

using namespace std;

void execute_payment(float total, payment_method *pm) {
	pm->pay(total);
}

int main() {
	float total = 1983.89f;
	int payment_method = 0;
	paypal ppl;
	credit_card cc;
	bitcoin btc;

	execute_payment(total, &ppl);
	execute_payment(total, &cc);
	execute_payment(total, &btc);

	return 0;
}
