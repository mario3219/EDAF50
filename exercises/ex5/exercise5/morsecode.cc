#include "morsecode.h"

#include <fstream>
#include <sstream>
#include <map>
#include <iostream>
#include <vector>
#include <string>

using std::string;

MorseCode::MorseCode() {
	mp["a"]=".-";
	mp["b"]="-...";
	mp["c"]="-.-.";
	mp["d"]="-..";
	mp["e"]=".";
	mp["f"]="..-.";
	mp["g"]="--.";
	mp["h"]="....";
	mp["i"]="..";
	mp["j"]=".---";
	mp["k"]="-.-";
	mp["l"]=".-..";
	mp["m"]="--";
	mp["n"]="-.";
	mp["o"]="---";
	mp["p"]=".--.";
	mp["q"]="--.-";
	mp["r"]=".-.";
	mp["s"]="...";
	mp["t"]="-";
	mp["u"]="..-";
	mp["v"]="...-";
	mp["w"]=".--";
	mp["x"]="-..-";
	mp["y"]="-.--";
	mp["x"]="--..";
}

string MorseCode::encode(const std::string& text) const {
	string temp;
	for (char c : text) {
		string s(1,c);
		for (auto x = mp.begin(); x != mp.end(); ++x) {
			if (x->first == s) {
				temp += x->second;
			}
		}
	} return temp;
}

string MorseCode::decode(const std::string& codes) const {
	string temp;
	std::stringstream test(codes);
	string segment;
	std::vector<string> seglist;
	while (std::getline(test,segment,' ')) {
		seglist.push_back(segment);
	}
	for (string code : seglist) {
		for (auto x = mp.begin(); x != mp.end(); ++x) {
			if (x->second == code) {
				temp += x->first;
			}
		}
	}
	return temp;
}
