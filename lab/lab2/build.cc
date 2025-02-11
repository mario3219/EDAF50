# include <iostream>
# include <algorithm>
# include <vector>
# include "trigrams.h"

int main() {
    std::string s;
    while (std::cin >> s) {
        transform(s.begin(), s.end(), s.begin(),[](unsigned char c) { return std::tolower(c); });
        std::vector<std::string> trigrams = find_trigrams(s);
        std::cout << s << " " << trigrams.size() << " ";
        for (std::string tri : trigrams) {
            std::cout << tri << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
