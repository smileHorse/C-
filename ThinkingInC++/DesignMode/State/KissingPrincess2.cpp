#include <iostream>
#include <string>
using namespace std;

class Creature {
	class State {
	public: 
		virtual string response() = 0;
	};
	class Frog : public State {
	public:
		string response() { return "Ribbet!"; }
	};
	class Prince : public State {
	public:
		string response() { return "Darling!"; }
	};
	State* state;
public:
	Creature() : state(new Frog()) {}
	void greet() {
		cout << state->response() << endl;
	}
	void kiss() {
		delete state;
		state = new Prince();
	}
};

int main() {
	Creature creature;
	creature.greet();
	creature.kiss();
	creature.greet();
}