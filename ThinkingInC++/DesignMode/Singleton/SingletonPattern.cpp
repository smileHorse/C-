
#include <iostream>
using namespace std;

class Singleton {
	static Singleton s;
	int i;
	Singleton(int x) : i(x) {}
	Singleton& operator=(const Singleton&);
	Singleton(const Singleton&);
public:
	static Singleton& instance() { return s; }
	int getValue() { return i; }
	void setValue(int x) { i = x; }
};

Singleton Singleton::s(47);

int main() {
	Singleton& s = Singleton::instance();
	cout << s.getValue() << endl;
	Singleton& s2 = Singleton::instance();
	s2.setValue(9);
	cout << s.getValue() << endl;
}