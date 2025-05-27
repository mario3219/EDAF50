#include <iostream>

using std::cout;
using std::endl;

int func() {
	static int ctr = 0;
	return ++ctr;
}

int main() {
	for (int i = 0; i != 10; i++) {
		cout << func() << endl;
	}
	return 0;
}
