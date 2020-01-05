#include <iostream>
#include "zthread/Thread.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

class SleepingTask : public Runnable {
	int countDown;
	int id;

public:
	SleepingTask(int ident = 0) : countDown(5), id(ident) {}
	~SleepingTask() { cout << id << " completed" << endl; }

	friend ostream& operator<<(ostream& os, const SleepingTask& yt) {
		return os << "#" << yt.id << ": " << yt.countDown;
	}

	void run() {
		while(true) {
			try {
				cout << *this << endl;
				if (--countDown == 0) {
					return;
				}
				Thread::sleep(100);
			} catch (Interrupted_Exception& e) {
				cerr << e.what() << endl;
			}
		}
	}
};

int main() {
	try {
		ThreadedExecutor executor;
		for (int i = 0; i < 5; ++i){
			executor.execute(new SleepingTask(i));
		}
	} catch(Synchronization_Exception& e) {
		cerr << e.what() << endl;
	}
}