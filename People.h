#pragma once

#ifndef _People
#define _People

#include "ofMain.h" //Agregamos los m�todos y las clases de oF

class People {

public: //Vista y acceso p�blico de estos m�todos

	People(); //Constructor

	//Propiedades
	int peopleMax;
	int x, y;

	//int peoplePosX[6];
	//int peoplePosY[6];
	float speed;

	//M�todos
	void setup();
	void update();
	void draw();

	ofImage person1,
			person2,
			person3;

	//ofImage people[6];

	//Constantes para ancho y alto de la pantalla en fullscreen
	const float width = 1920;
	const float height = 1080;
};

#endif //!People


