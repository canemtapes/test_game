#include "People.h" //Referencia al header donde se declaran los métodos

People::People() {
	/*
	for (int i = 1; i < peopleMax; i++) {
		peoplePosX[i] = ofRandom(250 * i, 1200 * i);
		peoplePosY[i] = ofRandom(-100 * i, -200 * i);
	}
	*/

	x = ofRandom(250, 1200);
	y = ofRandom(-100, -200);

	speed = ofRandom(2, 10);
	peopleMax = 3;
}

void People::setup() { //Cargamos las imagenes en un for.
	/*for (int i = 1; i <= peopleMax; i++) {
		string filename = "img/human" + ofToString(i) + ".png";
		people[i].load(filename);
	}*/

	person1.load("img/human1.png");
	person2.load("img/human2.png");
	person3.load("img/human3.png");

	//ver unlocated texture warning
}

void People::update() {
	
		y += speed;

		if (y > height) {
			x = ofRandom(250, 1200);
			y = ofRandom(-100, -200);
			speed = ofRandom(2, 10);
		}

	/*
		for (int i = 0; i < peopleMax; i++) {

			if (peoplePosY[i] > height) {
				peoplePosX[i] = ofRandom(500, 1200);
				peoplePosY[i] = ofRandom(-1, -20);
				speed = ofRandom(2, 10);
			}
		}
	*/
}

void People::draw() { //dibujamos las imagenes
	person1.setAnchorPercent(0.5, 0.5);
	person1.draw(x, y);

	person2.setAnchorPercent(0.5, 0.5);
	person2.draw(x * 2, y * 2);

	person3.setAnchorPercent(0.5, 0.5);
	person3.draw(x * 3, y * 3);

	/*for (int i = 0; i < peopleMax; i++) {
		people[i].setAnchorPercent(0.5, 0.5);
		people[i].draw(peoplePosX[i], peoplePosY[i]);
	}*/

	//falta testear porque se dibujan solo los circulos rojos, si es que se pisan o que pasa.
}