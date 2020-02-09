#include <iostream>
using namespace std;

class NameStrategy {
public:
	virtual void greet() = 0;
};

class SayHi : public NameStrategy {
public:
	void greet() {
		cout << "Hi!How's it going?" << endl;
	}
};

class Ignore : public NameStrategy {
public:
	void greet() {
		cout << "Pretend I don't see you" << endl;
	}
};

class Admission : public NameStrategy {
public:
	void greet() {
		cout << "I'm sorry, I forgot your name" << endl;
	}
};

class Context {
	NameStrategy& strategy;
public:
	Context(NameStrategy& strat) : strategy(strat) {}
	void greet() { strategy.greet(); }
};

int main() {
	SayHi sayHi;
	Ignore ignore;
	Admission admission;
	Context c1(sayHi), c2(ignore), c3(admission);
	c1.greet();
	c2.greet();
	c3.greet();
}