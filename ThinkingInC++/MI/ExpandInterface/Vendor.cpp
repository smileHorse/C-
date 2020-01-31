#include "Vendor.h"
#include <iostream>
using namespace std;

void Vendor::v() const { cout << "Vendor::v()" << endl; }
void Vendor::f() const { cout << "Vendor::f()" << endl; }
Vendor::~Vendor() { cout << "~Vendor()" << endl; }

void Vendor1::v() const { cout << "Vendor1::v()" << endl; }
void Vendor1::f() const { cout << "Vendor1::f()" << endl; }
Vendor1::~Vendor1() { cout << "~Vendor1()" << endl; }

void A(const Vendor& v) {
	// ...
	v.v();
	v.f();
	// ...
}

void B(const Vendor& v) {
	// ...
	v.v();
	v.f();
	// ...
}
