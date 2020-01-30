#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>
#include <vector>
#include "Trash.h"
using namespace std;

// Sums up the value of the Trash in a bin:
template<class Container>
void sumValue(Container& bin, ostream& os) {
	typename Container::iterator tally = bin.begin();
	float val = 0;
	while(tally != bin.end()) {
		val += (*tally)->weight() * (*tally)->value();
		os << "weight of " << typeid(**tally).name() << " = " << (*tally)->weight() << endl;
		++tally;
	}
	os << "Total value = " << val << endl;
}

//int main() {
//	srand(time(0));
//	vector<Trash*> bin;
//	// Fill up the Trash bin
//	for (int i = 0; i < 30; ++i) {
//		switch(rand() % 3) {
//		case 0:
//			bin.push_back(new Aluminum((rand() % 1000) / 10.0));
//			break;
//		case 1:
//			bin.push_back(new Paper((rand() % 1000) / 10.0));
//			break;
//		case 2:
//			bin.push_back(new Glass((rand() % 1000) / 10.0));
//			break;
//		}
//	}
//	vector<Glass*> glassBin;
//	vector<Paper*> paperBin;
//	vector<Aluminum*> aluminumBin;
//	vector<Trash*>::iterator sorter = bin.begin();
//	// Sort the Trash
//	while(sorter != bin.end()) {
//		Aluminum* ap = dynamic_cast<Aluminum*>(*sorter);
//		Paper* pp = dynamic_cast<Paper*>(*sorter);
//		Glass* gp = dynamic_cast<Glass*>(*sorter);
//		if (ap)	{
//			aluminumBin.push_back(ap);
//		} else if(pp) {
//			paperBin.push_back(pp);
//		} else if (gp) {
//			glassBin.push_back(gp);
//		}
//		++sorter;
//	}
//	sumValue(aluminumBin, cout);
//	sumValue(paperBin, cout);
//	sumValue(glassBin, cout);
//	sumValue(bin, cout);
//}