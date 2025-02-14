#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	std::vector<std::string> trim_suggestions(const std::string& word) const;
	std::vector<std::string> add_trigram_suggestions(const std::vector<std::string> word);
private:
	std::unordered_set<std::string> dict;	//decprecated since A4
	static constexpr int maxlen{25};	// creates constant maxlen = 25
	std::vector<Word> words[maxlen];	// creates an array of 25 vectors
	std::vector<std::string> split_lines(const std::string& str) const;
};

#endif
