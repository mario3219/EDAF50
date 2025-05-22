#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename T>
class SequenceGenerator {
	public:
		SequenceGenerator(T istart, T istep) : start(istart), step(istep) {}
		SequenceGenerator(T istart) : start(istart), step(1) {}
		SequenceGenerator() : start(0), step(1) {}
		T operator()() {
			T temp = start;
			start += step;
			return temp;
		}
	private:
		T start;
		T step;
};

using namespace std;

int main() {
	vector<int> v(10); // allocate 10 elements
	
	/*
	 * Output: 10 15 20 25 30 35 40 45 50 55
	 */
	generate(v.begin(), v.end(), SequenceGenerator<int>(10, 5));
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	/*
	 * Output: 5 6 7 8 9 10 11 12 13 14
	 */
	generate(v.begin(), v.end(), SequenceGenerator<int>(5));
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	/*
	 * Output: 0 1 2 3 4 5 6 7 8 9
	 */
	generate(v.begin(), v.end(), SequenceGenerator<int>());
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	/*
	 * Output: abcd...xyz
	 */
	vector<char> chars('z' - 'a' + 1);
	generate(chars.begin(), chars.end(), SequenceGenerator<char>('a'));
	copy(chars.begin(), chars.end(), ostream_iterator<char>(cout));
	cout << endl;
}
