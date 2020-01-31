#ifndef COUNTABLE_H
#define COUNTABLE_H

#include <cassert>

class Countable {
	long count;
protected:
	Countable() { count = 0; }
	virtual ~Countable() { assert(count == 0); }
public:
	long attach() { return ++count; }
	long detach() {
		return (--count > 0) ? count : (delete this, 0);
	}
	long refCount() const { return count; }
};
#endif