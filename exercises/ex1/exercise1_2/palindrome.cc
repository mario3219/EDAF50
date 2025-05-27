#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

bool palindrome(const string &str) {
	string temp;
	size_t sz = str.size();
	for (int i = sz-1; i != -1; i--) {
		temp += str[i];
	}
	cout << temp << endl;
	bool result = (temp == str);
	return result;
}

int main() {
	string test1 = "kalle";
	string test2 = "anna";
	cout << palindrome(test1) << endl;
	cout << palindrome(test2) << endl;
	return 0;
}
