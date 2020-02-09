#include <cstddef>
#include <iostream>
#include <map>
#include <vector>
#include "Bicycle.h"
using namespace std;

// Constructs a bike via a concreate builder
Bicycle* buildMeABike(BicycleTechnician& t, BicycleBuilder* builder) {
	t.setBuilder(builder);
	t.construct();
	Bicycle* b = builder->getProduct();
	cout << "Built a " << builder->getBikeName() << endl;
	return b;
}

int main() {
	map<string, size_t> order;
	order["mountain"] = 2;
	order["touring"] = 1;
	order["racing"] = 3;

	vector<Bicycle*> bikes;
	BicycleBuilder* m = new MountainBikeBuilder;
	BicycleBuilder* t = new TouringBikeBuilder;
	BicycleBuilder* r = new RacingBikeBuilder;
	BicycleTechnician tech;
	map<string, size_t>::iterator it = order.begin();
	while(it != order.end()) {
		BicycleBuilder* builder;
		if (it->first == "mountain") {
			builder = m;
		} else if (it->first == "touring") {
			builder = t;
		} else if (it->first == "racing") {
			builder = r;
		}
		for (size_t i = 0; i < it->second; ++i)	{
			bikes.push_back(buildMeABike(tech, builder));
		}
		++it;
	}
	delete m;
	delete t;
	delete r;

	for (size_t i = 0; i < bikes.size(); ++i) {
		cout << "Bicycle: " << *bikes[i] << endl;
	}
}