#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
class SequenceGenerator {
	public:
		SequenceGenerator<T>() : start(0), incr(1), step(0) {};
		SequenceGenerator<T>(T start) : start(start), incr(1), step(0) {};
		SequenceGenerator<T>(T start, T incr) : start(start), incr(incr), step(0) {};
		T operator()() {
			T temp = start+incr*step;
			step++;
			return temp;
		}
	private:
		T start;
		T incr;
		T step;
};

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
