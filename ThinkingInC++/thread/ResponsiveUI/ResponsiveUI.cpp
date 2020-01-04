#include <iostream>
#include <fstream>
#include <string>
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

class DisplayTask : public Runnable {
	ifstream in;
	string line;
	bool quitFlag;

public:
	DisplayTask(const string& file)
		: quitFlag(false) {
			in.open(file.c_str());
	}

	~DisplayTask() {
		in.close();
	}

	void run() {
		while (getline(in, line) && !quitFlag) {
			cout << line << endl;
			Thread::sleep(1000);
		}
	}

	void quit() {
		quitFlag = true;
	}
};

int main() {
	try {
		cout << "Press <Enter> to quit:" << endl;
		DisplayTask* dt = new DisplayTask("ResponsiveUI.cpp");
		Thread t(dt);
		cin.get();
		dt->quit();
	} catch(Synchronization_Exception& e) {
		cerr << e.what() << endl;
	}

	cout << "Shutting down..." << endl;
	return 0;
}