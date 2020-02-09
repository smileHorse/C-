#include <iostream>
#include <vector>
using namespace std;

enum Answer { NO, YES };

class GimmeStrategy {
public:
	virtual Answer canIHave() = 0;
	virtual ~GimmeStrategy() {}
};

class AskMom : public GimmeStrategy {
public:
	Answer canIHave() {
		cout << "Mooom? Can I have this?" << endl;
		return NO;
	}
};

class AskDad : public GimmeStrategy {
public:
	Answer canIHave() {
		cout << "Dad, I really need this!" << endl;
		return NO;
	}
};

class AskGrandpa : public GimmeStrategy {
public:
	Answer canIHave() {
		cout << "Grandpa, is it my birthday yet?" << endl;
		return NO;
	}
};

class AskGrandma : public GimmeStrategy {
public:
	Answer canIHave() {
		cout << "Grandma, I really love you!" << endl;
		return YES;
	}
};

class Gimme : public GimmeStrategy {
	vector<GimmeStrategy*> chain;
public:
	Gimme() {
		chain.push_back(new AskMom());
		chain.push_back(new AskDad());
		chain.push_back(new AskGrandpa());
		chain.push_back(new AskGrandma());
	}
	Answer canIHave() {
		vector<GimmeStrategy*>::iterator it = chain.begin();
		while(it != chain.end()) {
			if ((*it++)->canIHave() == YES) {
				return YES;
			}
		}
		cout << "Whiiiiiinne!" << endl;
		return NO;
	}
	~Gimme() {}
};

int main() {
	Gimme chain;
	chain.canIHave();
}