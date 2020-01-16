#ifndef DININGPHILOSOPHERS_H
#define DININGPHILOSOPHERS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "zthread/Condition.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include "zthread/Thread.h"
#include "Display.h"
using namespace ZThread;
using namespace std;

class Chopstick {
	Mutex lock;
	Condition notToken;
	bool taken;
public:
	Chopstick() : notToken(lock), taken(false) {}
	void take() {
		Guard<Mutex> g(lock);
		while (taken)
		{
			notToken.wait();
		}
		taken = true;
	}
	void drop() {
		Guard<Mutex> g(lock);
		taken = false;
		notToken.signal();
	}
};

class Philosopher : public Runnable {
	Chopstick& left;
	Chopstick& right;
	int id;
	int ponderFactor;
	CountedPtr<Display> display;
	int randSleepTime() {
		if (ponderFactor == 0) {
			return 0;
		}
		return rand() / (RAND_MAX / ponderFactor) * 250;
	}
	void output(string s) {
		ostringstream os;
		os << *this << " " << s << endl;
		display->output(os);
	}
public:
	Philosopher(Chopstick& l, Chopstick& r, CountedPtr<Display>& disp, int ident, int ponder)
		: left(l), right(r), display(disp), id(ident), ponderFactor(ponder) {}
	virtual void run() {
		try {
			while(!Thread::interrupted()) {
				output("thinking...");
				Thread::sleep(randSleepTime());
				// Hungry
				output("grabbing right");
				right.take();
				output("grabbing left");
				left.take();
				output("eating...");
				Thread::sleep(randSleepTime());
				right.drop();
				left.drop();
			}
		} catch(Synchronization_Exception& e) {
			output(e.what());
		}
	}
	friend ostream& operator<<(ostream& os, const Philosopher& p) {
		return os << "Philosopher " << p.id;
	}
};

#endif