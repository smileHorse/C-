#include <iostream>
#include "Vendor.h"
using namespace std;

class MyBase {
public:
	virtual void v() const = 0;
	virtual void f() const = 0;
	virtual void g() const = 0;
	virtual ~MyBase() { cout << "~MyBase()" << endl; }
};

class Paste1 : public MyBase, public Vendor1 {
public:
	void v() const {
		cout << "Paste1::v()" << endl;
		Vendor1::v();
	}
	void f() const {
		cout << "Paste1::f()" << endl;
		Vendor1::f();
	}
	void g() const {
		cout << "Paste1::g()" << endl;
	}
	~Paste1() { cout << "~Paste1()" << endl; }
};

int main() {
	Paste1& p1p = *new Paste1;
	MyBase& mp = p1p;
	cout << "calling f()" << endl;
	mp.f();
	cout << "calling g()" << endl;
	mp.g();
	cout << "calling A(p1p)" << endl;
	A(p1p);
	cout << "calling B(p1p)" << endl;
	B(p1p);
	cout << "delete mp" << endl;
	delete &mp;
}