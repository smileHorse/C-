#include <iostream>
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

const double pi = 3.14159265358979323846;
const double e = 2.7182818284590452354;

class SimplePriorities : public Runnable {
	int countDown;
	volatile double d;
	int id;
public:
	SimplePriorities(int ident = 0) : countDown(5), id(ident) {}
	~SimplePriorities() { cout << id << " completed" << endl; }

	friend ostream& operator<<(ostream& os, const SimplePriorities& sp) {
		return os << "#" << sp.id << " priority: " << Thread().getPriority()
			<< " count: " << sp.countDown;
	}

	void run() {
		while (true) {
			for (int i = 1; i < 100000; ++i)
			{
				d = d + (pi + e) / double(i);
			}
			cout << *this << endl;
			if (--countDown) {
				return;
			}
		}
	}
};

int main() {
	try {
		Thread high(new SimplePriorities);
		high.setPriority(High);
		for (int i = 0; i < 5; ++i) {
			Thread low(new SimplePriorities(i));
			low.setPriority(Low);
		}
	} catch(Synchronization_Exception& e) {
		cerr << e.what() << endl;
	}
}