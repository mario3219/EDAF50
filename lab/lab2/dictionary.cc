#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>

using namespace std;

Dictionary::Dictionary() {
	unordered_set<string> dict;
	ifstream file("words.txt");
	string str;
	while (getline(file, str)) {
		dict.insert(str);		
	}
}

bool Dictionary::contains(const string& word) const {
	return true;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
