#include "People.h" //Referencia al header donde se declaran los métodos

People::People() {
	x = ofRandom(500, 1200);
	y = ofRandom(-1, -20);
	speed = ofRandom(2, 10);
	peopleMax = 6;
}

void People::setup() { //Cargamos las imagenes en un for.
	for (int i = 1; i < 6; i++) {
		string filename = "img/human" + ofToString(i) + ".png";
		people[i].load(filename);
	}

	//ver unlocated texture warning
}

void People::update() {
	y += speed;

	if (y > height) {
		x = ofRandom(500, 1200);
		y = ofRandom(-1, -20);
		speed = ofRandom(2, 10);
	}
}

void People::draw() { //dibujamos las imagenes
	for (int i = 0; i < peopleMax; i++) {
		people[i].setAnchorPercent(0.5, 0.5);
		people[i].draw(x, y);
	}

	//falta testear porque se dibujan solo los circulos rojos, si es que se pisan o que pasa.
}