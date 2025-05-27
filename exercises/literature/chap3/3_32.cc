#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<int> copyV(const int a[],int sz) {
	vector<int> v;
	for (size_t i = 0; i != sz; i++) {
		v.push_back(a[i]);
	} return v;
}

int main() {
	int sz = 10;
	int a[sz] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v = copyV(a,sz);
	for (int a : v) {
		cout << a << endl;
	}
	return 0;
}
