#ifndef TRASH_H
#define TRASH_H

#include <iostream>
using namespace std;

class Trash {
	float _weight;
public:
	Trash(float wt) : _weight(wt) {}
	virtual float value() const = 0;
	float weight() const { return _weight; }
	virtual ~Trash() {
		cout << "~Trash()" << endl;
	}
};

class Aluminum : public Trash {
	static float val;
public:
	Aluminum(float wt) : Trash(wt) {}
	float value() const { return val; }
	static void value(float newval) { val = newval; }
};

class Paper : public Trash {
	static float val;
public:
	Paper(float wt) : Trash(wt) {}
	float value() const { return val; }
	static void value(float newval) { val = newval; }
};

class Glass : public Trash {
	static float val;
public:
	Glass(float wt) : Trash(wt) {}
	float value() const { return val; }
	static void value(float newval) { val = newval; }
};

#endif