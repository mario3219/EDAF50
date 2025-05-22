#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <vector>

class Text {
public:
	void addLine(const std::string& line) { lines.push_back(line); }
	// added
	using iterator = std::vector<std::string>::iterator;

	iterator begin() {return lines.begin(); }
	iterator end() {return lines.end(); }

private:
	std::vector<std::string> lines;
};

#endif
