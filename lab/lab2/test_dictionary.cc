# include "dictionary.h"
# include <iostream>
# include "word.h"

int main() {
	Dictionary dict;
	std::string str = "dwadawd";
	std::cout << dict.contains(str) << "\n";
	dict.add_trigram_suggestions("test");
	return 0;
}
