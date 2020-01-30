#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <typeinfo>
#include <utility>
#include <vector>
#include "Trash.h"
using namespace std;

// Comparator for type_info pointers
struct TInfoLess {
	bool operator()(const type_info* t1, const type_info* t2) const {
		return t1->before(*t2);
	}
};

typedef map<const type_info*, vector<Trash*>, TInfoLess> TrashMap;

// Sums up the value of the Trash in a bin:
void sumValue(const TrashMap::value_type& p, ostream& os) {
	vector<Trash*>::const_iterator tally = p.second.begin();
	float val = 0;
	while(tally != p.second.end()) {
		val += (*tally)->weight() * (*tally)->value();
		os << "weight of " << p.first->name() << " = " << (*tally)->weight() << endl;
		++tally;
	}
	os << "Total value = " << val << endl;
}

int main() {
	srand(time(0));
	TrashMap bin;
	// Fill up the Trash bin
	for (int i = 0; i < 30; ++i) {
		Trash* tp;
		switch(rand() % 3) {
		case 0:
			tp = new Aluminum((rand() % 1000) / 10.0);
			break;
		case 1:
			tp = new Paper((rand() % 1000) / 10.0);
			break;
		case 2:
			tp = new Glass((rand() % 1000) / 10.0);
			break;
		}
		bin[&typeid(*tp)].push_back(tp);
	}
	// print sorted results
	for (TrashMap::iterator p = bin.begin(); p != bin.end(); ++p) {
		sumValue(*p, cout);
	}
}