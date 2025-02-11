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
	ifstream file("words.txt");
	string str;
	if (file.is_open()) {
		while (getline(file, str)) {
			dict.insert(str);
		}
	} file.close();
}

bool Dictionary::contains(const string& word) const {
	for (string str : dict) {
		if (str.contains(word)) {
			return true;
		} return false;
	}
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
