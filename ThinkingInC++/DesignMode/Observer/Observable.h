#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <set>
#include "Observer.h"
using namespace std;

class Observable {
	bool changed;
	set<Observer*> observers;
protected:
	virtual void setChanged() { changed = true; }
	virtual void clearChanged() { changed = false; }
public:
	virtual void addObserver(Observer& o) {
		observers.insert(&o);
	}
	virtual void deleteObserver(Observer& o) {
		observers.erase(&o);
	}
	virtual void deleteObservers() {
		observers.clear();
	}
	virtual int countObservers() {
		return observers.size();
	}
	virtual bool hasChanged() { return changed; }
	// If this object has changed, notify all of its observers
	virtual void notifyObservers(Argument* arg = 0) {
		if (!hasChanged())	{ return; }
		clearChanged();
		set<Observer*>::iterator it;
		for(it = observers.begin(); it != observers.end(); ++it) {
			(*it)->update(this, arg);
		}
	}
	virtual ~Observable() {}
};

#endif