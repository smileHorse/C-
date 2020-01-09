#include <iostream>
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
using namespace ZThread;
using namespace std;

class BlockedMutex {
	Mutex lock;
public:
	BlockedMutex() { lock.acquire(); }
	void f() {
		Guard<Mutex> g(lock);
		// This will never be available
	}
};

class Blocked2 : public Runnable {
	BlockedMutex blocked;
public:
	void run() {
		try {
			cout << "Waiting for f() in BlockedMutex" << endl;
			blocked.f();
		} catch(Interrupted_Exception& e) {
			cerr << e.what() << endl;
		}
	}
};

//int main() {
//	try {
//		Thread t(new Blocked2);
//		t.interrupt();
//	} catch(Synchronization_Exception& e) {
//		cerr << e.what() << endl;
//	}
//}