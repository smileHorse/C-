#include "Bicycle.h"
#include <cassert>
#include <cstddef>

string BicyclePart::names[] = {
	"Frame", "Wheel", "Seat", "Derailleur",
	"Handlebar", "Sprocket", "Rack", "Shock"
};

void MountainBikeBuilder::buildFrame() {
	product->addPart(new BicyclePart(BicyclePart::FRAME));
}

void MountainBikeBuilder::buildWheel() {
	product->addPart(new BicyclePart(BicyclePart::WHEEL));
}

void MountainBikeBuilder::buildSeat() {
	product->addPart(new BicyclePart(BicyclePart::SEAT));
}

void MountainBikeBuilder::buildDerailleur() {
	product->addPart(new BicyclePart(BicyclePart::DERAILLEUR));
}

void MountainBikeBuilder::buildHandlebar() {
	product->addPart(new BicyclePart(BicyclePart::HANDLEBAR));
}

void MountainBikeBuilder::buildSprocket() {
	product->addPart(new BicyclePart(BicyclePart::SPROCKET));
}

void MountainBikeBuilder::buildRack() {}

void MountainBikeBuilder::buildShock() {
	product->addPart(new BicyclePart(BicyclePart::SHOCK));
}

void TouringBikeBuilder::buildFrame() {
	product->addPart(new BicyclePart(BicyclePart::FRAME));
}

void TouringBikeBuilder::buildWheel() {
	product->addPart(new BicyclePart(BicyclePart::WHEEL));
}

void TouringBikeBuilder::buildSeat() {
	product->addPart(new BicyclePart(BicyclePart::SEAT));
}

void TouringBikeBuilder::buildDerailleur() {
	product->addPart(new BicyclePart(BicyclePart::DERAILLEUR));
}

void TouringBikeBuilder::buildHandlebar() {
	product->addPart(new BicyclePart(BicyclePart::HANDLEBAR));
}

void TouringBikeBuilder::buildSprocket() {
	product->addPart(new BicyclePart(BicyclePart::SPROCKET));
}

void TouringBikeBuilder::buildRack() {
	product->addPart(new BicyclePart(BicyclePart::RACK));
}

void TouringBikeBuilder::buildShock() {}

void RacingBikeBuilder::buildFrame() {
	product->addPart(new BicyclePart(BicyclePart::FRAME));
}

void RacingBikeBuilder::buildWheel() {
	product->addPart(new BicyclePart(BicyclePart::WHEEL));
}

void RacingBikeBuilder::buildSeat() {
	product->addPart(new BicyclePart(BicyclePart::SEAT));
}

void RacingBikeBuilder::buildDerailleur() {}

void RacingBikeBuilder::buildHandlebar() {
	product->addPart(new BicyclePart(BicyclePart::HANDLEBAR));
}

void RacingBikeBuilder::buildSprocket() {
	product->addPart(new BicyclePart(BicyclePart::SPROCKET));
}

void RacingBikeBuilder::buildRack() {}

void RacingBikeBuilder::buildShock() {}

void BicycleTechnician::construct() {
	assert(builder);
	builder->createProduct();
	builder->buildFrame();
	builder->buildWheel();
	builder->buildSeat();
	builder->buildDerailleur();
	builder->buildHandlebar();
	builder->buildSprocket();
	builder->buildRack();
	builder->buildShock();
}
