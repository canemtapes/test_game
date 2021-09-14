#pragma once

#ifndef _People
#define _People

#include "ofMain.h" //Agregamos los métodos y las clases de oF

class People {

public: //Vista y acceso público de estos métodos

	People(); //Constructor

	//Propiedades
	int peopleMax;
	int x, y;

	//int peoplePosX[6];
	//int peoplePosY[6];
	float speed;

	//Métodos
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


