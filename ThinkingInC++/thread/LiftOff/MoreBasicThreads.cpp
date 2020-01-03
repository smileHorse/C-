
#include <iostream>
#include "LiftOff.h"
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

int main() 
{
	const int SZ = 5;
	try {
		for (int i = 0; i < SZ; ++i)
		{
			Thread t(new LiftOff(10, i));
		}
		cout << "Waiting for LiftOff" << endl;
	}
	catch(Synchronization_Exception& e) {
		cerr << e.what() << endl;
	}
	return 0;
}