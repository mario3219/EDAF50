#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <vector>

using u

class Text {
public:
	void addLine(const std::string& line) { lines.push_back(line); }

	std::iostream begin() {
		return lines.begin();
	}

	std::iostream end() {
		return lines.end();
	}

private:
	std::vector<std::string> lines;
};

#endif
