#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>
#include <sstream>
#include "trigrams.h"

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
	if (file.is_open()) {
		while (getline(file, str)) {
			dict.insert(str);

			// using word class
			v = split_lines(str);
			word = v[0];
			v.erase(v.begin(), v.begin() + 2);	// keep only trigrams

			// stores word in the vector at index equal to the size of the word
			words[word.size()].insert(words[word.size()].begin(), Word(word, v));
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

vector<string> Dictionary::trim_suggestions(const vector<string> candidates) const {
	string score[];
	for (string candidate : candidates)
	return suggestions;
}

vector<string> Dictionary::add_trigram_suggestions(const string& word) {
	int sz = word.size();
	vector<Word> can; //candidates

	// add candidates from words list around equal size (+-1)
	for (int inc = -1; inc <= 1; ++inc) {
		can.insert(can.end(), words[sz+inc].begin(), words[sz+inc].end());
	}

	// store candidates with more than half or more matching trigrams
	vector<string> triag = find_trigrams(word);
	vector<string> new_can;
	size_t count = 0;
	for (size_t idx = 0; idx <= can.size(); ++idx) {
		count = can[idx].get_matches(triag);
		if (count >= triag.size()/2) {
			new_can.insert(new_can.begin(), can[idx].get_word());
		}
	}
	return new_can;
}
