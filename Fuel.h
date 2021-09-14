#pragma once

#ifndef _Fuel
#define _Fuel

#include "ofMain.h" //Agregamos los m�todos y las clases de oF

class Fuel {

public: //Vista y acceso p�blico de estos m�todos

	Fuel(); //Constructor

	//Propiedades
	int bx, by, fx, fy;

	//M�todos
	void setup();
	void draw();

	ofImage fuel[2], bioFuel[2];

	//Constantes para ancho y alto de la pantalla en fullscreen
	const float width = 1920;
	const float height = 1080;
};

#endif //!Fuel
