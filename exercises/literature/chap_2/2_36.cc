#include <iostream>

using std::cout;
using std::endl;

int main() {
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype((b)) d = a;
	++c;
	++d;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
}
