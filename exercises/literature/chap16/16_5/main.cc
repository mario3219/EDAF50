#include <iostream>

using std::cout;
using std::endl;

template<typename T, std::size_t N>
void print(const T (&arr)[N]) {
	for (std::size_t i = 0; i < N; i++) {
		cout << arr[i] << " ";
	} cout << endl;
}

int main() {
	int a[] = {1,2,3,4,5};
	print(a);
	return 0;
}
