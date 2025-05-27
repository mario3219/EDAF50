#include <iostream>

using std::cout;
using std::endl;

int main() {
	const unsigned int sz = 10;
	int a[sz];
	for (int i = 0; i != sz; i++) {
		a[i]=i;
	}
	for (int i = 0; i != sz; i++) {
		cout << a[i] << endl;
	}
	return 0;
}
