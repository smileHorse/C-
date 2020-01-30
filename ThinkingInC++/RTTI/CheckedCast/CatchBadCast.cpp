#include <typeinfo>
#include "Security.h"
using namespace std;

int main() {
	Metal m;
	Security& s = m;
	try {
		Investment& c = dynamic_cast<Investment&>(s);
		cout << "It's an Investment" << endl;
	} catch(bad_cast&) {
		cout << "s is not an Investment type" << endl;
	}
	try {
		Bond& b = dynamic_cast<Bond&>(s);
		cout << "It's an Bond" << endl;
	} catch(bad_cast&) {
		cout << "It's not a Bond type" << endl;
	}
}