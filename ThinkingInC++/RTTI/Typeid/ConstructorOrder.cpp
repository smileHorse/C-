#include <iostream>
#include <typeinfo>
using namespace std;

template<int id> class Announce {
public:
	Announce() {
		cout << typeid(*this).name() << " constructor" << endl;
	}
	~Announce() {
		cout << typeid(*this).name() << " destructor" << endl;
	}
};

class X : public Announce<0> {
	Announce<1> m1;
	Announce<2> m2;
public:
	X() { cout << "X::X()" << endl; }
	~X() { cout << "X::~X()" << endl; }
};

int main() {
	X x;
}