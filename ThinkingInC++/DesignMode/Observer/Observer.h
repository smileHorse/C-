#ifndef OBSERVER_H
#define OBSERVER_H

class Observable;
class Argument {};

class Observer {
public:
	// Called by the observed object, whenever the observerd object is changed
	virtual void update(Observable* o, Argument* arg) = 0;
	virtual ~Observer() {}
};
#endif