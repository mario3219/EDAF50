#include <iostream>
#include "compare.h"
#include <vector>

using std::cout;
using std::endl;

template<typename T1, typename T2>
size_t find() {
}

int main() {
	compare<int,int> c;
	cout << c.cmpr(5,2) << endl;
	cout << c.cmpr(2,5) << endl;
	return 0;
}
