#include <iostream>
#include "zthread/ConcurrentExecutor.h"
#include "LiftOff.h"
using namespace ZThread;
using namespace std;

int main() {
	try {
		ConcurrentExecutor executor;
		for (int i = 0; i < 5; ++i)
		{
			executor.execute(new LiftOff(10, i));
		}

		cout << "main..." << endl;
	} catch(Synchronization_Exception& e) {
		cerr << e.what() << endl;
	}
}