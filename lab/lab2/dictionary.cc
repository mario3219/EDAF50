#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>
#include <sstream>

using namespace std;

vector<string> Dictionary::split_lines(const string& str) const {
	string s;
	stringstream ss(str);
	vector<string> v;
	while (getline(ss, s, ' ')) {
		v.push_back(s);
	} return v;
}

Dictionary::Dictionary() {
	ifstream file("words.txt");
	string str;
	vector<string> v;	// for using word class
	string word;		// ...
	string trigrams;	// ...
	if (file.is_open()) {
		while (getline(file, str)) {
			dict.insert(str);
			
			// using word class instead
			v = split_lines(str);
			word = v[0];
			v.erase(v.begin(), v.begin() + 2);	// keep only trigrams
			words.insert(words.begin(), Word(word, v));
		}
	} file.close();
}

bool Dictionary::contains(const string& word) const {
	for (string str : dict) {
		if (str.contains(word)) {
			return true;
		}
	} return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}

//vector<string> Dictionary::add_trigram_suggestions(const string& trigrams) {
//	return vector<string>;
//}
