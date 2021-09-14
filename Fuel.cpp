#include "Fuel.h"

Fuel::Fuel() {
	fx = ofRandom(500, 1200);
	fy = ofRandom(100, 950);
	bx = ofRandom(500, 1200);
	by = ofRandom(100, 950);
}

void Fuel::setup() {
	for (int i = 0; i < 2; i++) {
		fuel[i].load("img/fuel.png");
		bioFuel[i].load("img/biofuel.png");
	}
}

void Fuel::draw() {
	for (int i = 0; i < 2; i++) {
		bioFuel[i].setAnchorPercent(0.5, 0.5);
		bioFuel[i].draw(bx, by);
		fuel[i].setAnchorPercent(0.5, 0.5);
		fuel[i].draw(fx, fy);
	}
}