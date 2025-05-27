#include "testoperator.h"

count::count() : cnt(0) {}
int count::operator()() {
	cnt++;
	return cnt;
}
