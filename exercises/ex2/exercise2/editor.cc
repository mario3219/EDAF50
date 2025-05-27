#include "editor.h"
#include <algorithm>
#include <string>

using std::string;

string::size_type Editor::find_left_par(string::size_type pos) const {
	auto start = text.begin()+pos;
	auto stop = text.end();
	auto idx = std::find(start,stop,"(");
	return 0;
}
