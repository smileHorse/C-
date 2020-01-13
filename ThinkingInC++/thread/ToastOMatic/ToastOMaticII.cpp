#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include "zthread/Condition.h"
#include "zthread/ThreadedExecutor.h"
#include "TQueue.h"
using namespace ZThread;
using namespace std;

class Toast {
	enum Status { DRY, BUTTERED, JAMMED };
	Status status;
	int id;
public:
	Toast(int idn) : status(DRY), id(idn) {}
	void butter() { status = BUTTERED; }
	void jam() { status = JAMMED; }
	string getStatus() const {
		switch(status) {
		case DRY: return "dry";
		case BUTTERED: return "buttered";
		case JAMMED: return "jammed";
		default: return "error";
		}
	}
	int getId() { return id; }
	friend ostream& operator<<(ostream& os, const Toast& t) {
		return os << "Toast " << t.id << ": " << t.getStatus();
	}
};

typedef CountedPtr< TQueue<Toast> > ToastQueue;

class Toaster : public Runnable {
	ToastQueue toastQueue;
	int count;
public:
	Toaster(ToastQueue& tq) : toastQueue(tq), count(0) {}
	void run() {
		try {
			while (!Thread::interrupted()) {
				int delay = rand() / (RAND_MAX / 5) * 100;
				Thread::sleep(delay);
				// Make toast
				Toast t(count++);
				cout << t << endl;
				toastQueue->put(t);
			}
		} catch (Interrupted_Exception& ) {
			cout << "Toaster off" << endl;
		}
	}
};

// Apply butter to toast
class Butterer : public Runnable {
	ToastQueue dryQueue, butteredQueue;
public:
	Butterer(ToastQueue& dry, ToastQueue& buttered) : dryQueue(dry), butteredQueue(buttered) {}
	void run() {
		try {
			while (!Thread::interrupted()) {
				// Blocks until next piece of toast is available
				Toast t = dryQueue->get();
				t.butter();
				cout << t << endl;
				butteredQueue->put(t);
			}
		} catch (Interrupted_Exception& ) {
			cout << "Butterer off" << endl;
		}
	}
};

// Apply jam to buttered toast
class Jammer : public Runnable {
	ToastQueue butteredQueue, finishedQueue;
public:
	Jammer(ToastQueue& buttered, ToastQueue& finished) : butteredQueue(buttered), 
		finishedQueue(finished) {}
	void run() {
		try {
			while (!Thread::interrupted()) {
				// Blocks until next piece of toast is available
				Toast t = butteredQueue->get();
				t.jam(); 
				cout << t << endl;
				finishedQueue->put(t);
			}
		} catch (Interrupted_Exception& ) {
			cout << "Jammer off" << endl;
		}
	}
};

// Consume the toast
class Eater : public Runnable {
	ToastQueue finishedQueue;
	int counter;
public:
	Eater(ToastQueue& finished) : finishedQueue(finished), counter(0) {}
	void run() {
		try {
			while (!Thread::interrupted()) {
				// Blocks until next piece of toast is available
				Toast t = finishedQueue->get();
				// Verify that the toast is coming in order,
				// and that all pieces are jammed
				if (t.getId() != counter++ || t.getStatus() != "jammed") {
					cout << ">>>> Error: " << t << endl;
					exit(1);
				} else {
					cout << "Chomp! " << t << endl;
				}
			}
		} catch (Interrupted_Exception& ) {
			cout << "Eater off" << endl;
		}
	}
};

//int main() {
//	srand(time(0));
//	try {
//		ToastQueue dryQueue(new TQueue<Toast>),
//			butteredQueue(new TQueue<Toast>),
//			finishedQueue(new TQueue<Toast>);
//		cout << "Press <Enter> to quit" << endl;
//		ThreadedExecutor executor;
//		executor.execute(new Toaster(dryQueue));
//		executor.execute(new Butterer(dryQueue, butteredQueue));
//		executor.execute(new Jammer(butteredQueue, finishedQueue));
//		executor.execute(new Eater(finishedQueue));
//		cin.get();
//		executor.interrupt();
//	} catch (Synchronization_Exception& e) {
//		cerr << e.what() << endl;
//	}
//}