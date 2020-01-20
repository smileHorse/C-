#include <iostream>
using namespace std;

class Creature {
	bool isFrog;
public:
	Creature() : isFrog(true) {}
	void greet() {
		if (isFrog) {
			cout << "Ribbet!" << endl;
		} else {
			cout << "Darling!" << endl;
		}
	}
	void kiss() { isFrog = false; }
};

//int main() {
//	Creature creature;
//	creature.greet();
//	creature.kiss();
//	creature.greet();
//}