#ifndef WORD_H
#define WORD_H

#include <string>
#include <vector>

using namespace std;

class Word {
public:
	/* Creates a word w with the sorted trigrams t */
	Word(const string& w, const vector<string>& t);
	
	/* Returns the word */
	string get_word() const;
	
	/* Returns how many of the trigrams in t that are present
	 in this word's trigram vector */
	unsigned int get_matches(const vector<string>& t) const;
private:
	string word;
	vector<string> trigrams;
};

#endif
