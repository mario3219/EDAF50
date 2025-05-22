#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cctype>

using namespace std;

bool myfunction1(string str1, string str2) {
	char c1 = tolower(str1[0]);
	char c2 = tolower(str2[0]);
	return c1 > c2;
}

bool myfunction2(string str1, string str2) {
	char c1 = tolower(str1[0]);
	char c2 = tolower(str2[0]);
	return c1 < c2;
}

int main() {
	vector<string> v = {"Mary", "had", "a", "little", "lamb", "and", "some",
		"olives", "on", "the", "side"};
	
	// print the words: Mary had a little lamb and some olives on the side
	std::copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
	cout <<endl;
	
	cout << "------" << endl;
	// sort in alphabetical order: Mary a and had lamb little olives on side some the
	sort(v.begin(),v.end(),myfunction1);
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	
	cout << "------" << endl;
	// in reverse order: the some side on olives little lamb had and a Mary
	sort(v.begin(),v.end(),myfunction2);
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	
	// by ascending length: a on the and had Mary lamb side some olives little

	//cout << v << endl;
	
	cout << "------" << endl;
	// sort in alphabetical order again, print three-letter words: and had the
	sort(v.begin(),v.end(),myfunction1);
	/*for (auto it = v.begin(); it != v.end(); it+3) {
		cout << *it << *(it+1) << *(it+2) << endl;
	}*/
	// remove words with <= three letters: Mary lamb little olives side some

	//cout << v << endl;
}
