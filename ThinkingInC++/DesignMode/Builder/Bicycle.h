#ifndef BICYCLE_H
#define BICYCLE_H

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
using namespace std;

class BicyclePart {
public:
	enum BPart { FRAME, WHEEL, SEAT, DERAILLEUR, HANDLEBAR, SPROCKET, RACK, SHOCK, NPARTS };
private:
	BPart id;
	static string names[NPARTS];
public:
	BicyclePart(BPart bp) { id = bp; }
	friend ostream& operator<<(ostream& os, const BicyclePart& bp) {
		return os << bp.names[bp.id];
	}
};

class Bicycle {
	vector<BicyclePart*> parts;
public:
	~Bicycle() {}
	void addPart(BicyclePart* bp) { parts.push_back(bp); }
	friend ostream& operator<<(ostream& os, const Bicycle& b) {
		os << "{ ";
		for (size_t i = 0; i < b.parts.size(); ++i) {
			os << *b.parts[i] << " ";
		}
		return os << "}";
	}
};

class BicycleBuilder {
protected:
	Bicycle* product;
public:
	BicycleBuilder() { product = 0; }
	void createProduct() { product = new Bicycle; }
	virtual void buildFrame() = 0;
	virtual void buildWheel() = 0;
	virtual void buildSeat() = 0;
	virtual void buildDerailleur() = 0;
	virtual void buildHandlebar() = 0;
	virtual void buildSprocket() = 0;
	virtual void buildRack() = 0;
	virtual void buildShock() = 0;
	virtual string getBikeName() const = 0;
	Bicycle* getProduct() {
		Bicycle* temp = product;
		product = 0;	// Relinquish product
		return temp;
	}
};

class MountainBikeBuilder : public BicycleBuilder {
public:
	void buildFrame();
	void buildWheel();
	void buildSeat();
	void buildDerailleur();
	void buildHandlebar();
	void buildSprocket();
	void buildRack();
	void buildShock();
	string getBikeName() const { return "MountainBike"; }
};

class TouringBikeBuilder : public BicycleBuilder {
public:
	void buildFrame();
	void buildWheel();
	void buildSeat();
	void buildDerailleur();
	void buildHandlebar();
	void buildSprocket();
	void buildRack();
	void buildShock();
	string getBikeName() const { return "TouringBike"; }
};

class RacingBikeBuilder : public BicycleBuilder {
public:
	void buildFrame();
	void buildWheel();
	void buildSeat();
	void buildDerailleur();
	void buildHandlebar();
	void buildSprocket();
	void buildRack();
	void buildShock();
	string getBikeName() const { return "RacingBike"; }
};

class BicycleTechnician {
	BicycleBuilder* builder;
public:
	BicycleTechnician() { builder = 0; }
	void setBuilder(BicycleBuilder* b) { builder = b; }
	void construct();
};

#endif