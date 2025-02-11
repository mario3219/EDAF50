# include "dictionary.h"
# include <iostream>
# include "word.h"

int main() {
	Dictionary dict;
	std::string str = "ama";
	std::cout << dict.contains(str) << "\n";
	return 0;
}
