/*
 * countobj.cc: count creation and destruction of objects. One class and
 * several functions, all in this file.
 */

#include <iostream>
#include <string>

class Counted {
public:
	Counted();
	Counted(const Counted&);
	~Counted();
	static int getNbrObj();
	Counted &operator=(Counted);
private:
	static int nbrObj;
};

Counted::Counted(const Counted& cp) {
	nbrObj++;
}

int Counted::nbrObj = 0;

Counted::Counted() {
	nbrObj++;
}

Counted::~Counted() {
	nbrObj--;
}

int Counted::getNbrObj() {
	return nbrObj;
}

Counted& Counted::operator=(Counted c) {
	return *this;
}

void f() {
	Counted c;
	Counted* pc = new Counted;
	delete pc;
}

void g() {
	Counted c1;
	Counted c2 = c1;
}

void h() {
	Counted c1;
	Counted c2;
	c2 = c1;
}

using std::cout;
using std::endl;
using std::string;

void print_nbr_objects(const string& msg) {
	cout << msg << " -- number of objects: "
	     << Counted::getNbrObj() << endl;
}

int main() {
	print_nbr_objects("Program start, before f()");
	f();
	
	print_nbr_objects("After f(), before g()    ");
	g();
	
	print_nbr_objects("After g(), before h()    ");
	h();
	
	print_nbr_objects("After h(), program end   ");
}

