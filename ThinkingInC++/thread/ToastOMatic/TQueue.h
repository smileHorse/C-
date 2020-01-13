#ifndef TQUEUE_H
#define TQUEUE_H

#include <deque>
#include "zthread/Thread.h"
#include "zthread/Condition.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
using namespace ZThread;
using namespace std;

template<class T> class TQueue {
	Mutex lock;
	Condition cond;
	deque<T> data;
public:
	TQueue() : cond(lock) {}
	void put(T item) {
		Guard<Mutex> g(lock);
		data.push_back(item);
		cond.signal();
	}
	T get() {
		Guard<Mutex> g(lock);
		while (data.empty()) {
			cond.wait();
		}
		T returnVal = data.front();
		data.pop_front();
		return returnVal;
	}
};

#endif