#include <iostream>
using namespace std;

namespace space1 {
	void func() {
		cout << "in space1" << '\n';
	}
}

namespace space2 {
	void func() {
		cout << "in space2" << '\n';
	}
}

using namespace space2;

int main() {
	space1::func();
	func();

	return 0;
}
