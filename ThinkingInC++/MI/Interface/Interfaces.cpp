#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Printable {
public:
	virtual ~Printable() {}
	virtual void print(ostream&) const = 0;
};

class Intable {
public:
	virtual ~Intable() {}
	virtual int toInt() const = 0;
};

class Stringable {
public:
	virtual ~Stringable() {}
	virtual string toString() const = 0;
};

class Able : public Printable, public Intable, public Stringable {
	int myData;
public:
	Able(int x) : myData(x) {}
	void print(ostream& os) const { os << myData; }
	int toInt() const { return myData; }
	string toString() const {
		ostringstream os;
		os << myData;
		return os.str();
	}
};

void testPrintable(const Printable& p) {
	p.print(cout);
	cout << endl;
}

void testIntable(const Intable& n) {
	cout << n.toInt() + 1 << endl;
}

void testStringable(const Stringable& s) {
	cout << s.toString() + "th" << endl;
}

//int main() {
//	Able a(7);
//	testPrintable(a);
//	testIntable(a);
//	testStringable(a);
//}