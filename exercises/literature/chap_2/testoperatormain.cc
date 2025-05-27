#include <iostream>
#include "testoperator.h"

using std::cout;
using std::endl;

int main() {
	auto i = count();
	cout << i() << endl;
	cout << i() << endl;
	return 0;
}
