#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int* zero(int *a, int *b) {
	int *temp = a;
	while (a != b) {
		*a = 0;
		a++;
	} return temp;
}

void print(int *a, int *b) {
	while (a != b) {
		cout << *a << endl;
		a++;
	}
}

int main() {
	int a[] = {1,2,3,4,5};
	int *beg = begin(a);
	int *last = end(a);
	print(beg,last);
	int *b = zero(beg,last);
	print(beg,last);
	return 0;
}
