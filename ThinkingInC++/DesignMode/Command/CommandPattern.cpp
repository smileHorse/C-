#include <iostream>
#include <vector>
using namespace std;

class Command {
public:
	virtual void execute() = 0;
};

class Hello : public Command {
public:
	void execute() { cout << "Hello " << endl; }
};

class World : public Command {
public:
	void execute() { cout << "World! " << endl; }
};

class IAm : public Command {
public:
	void execute() { cout << "I'm the command pattern" << endl; }
};

// An object that holds commands
class Macro {
	vector<Command*> commands;
public:
	void add(Command* c) { commands.push_back(c); }
	void run() {
		vector<Command*>::iterator it = commands.begin();
		while(it != commands.end()) {
			(*it++)->execute();
		}
	}
};

int main() {
	Macro macro;
	macro.add(new Hello);
	macro.add(new World);
	macro.add(new IAm);
	macro.run();
}