#pragma once

#ifndef _Fuel
#define _Fuel

#include "ofMain.h" //Agregamos los métodos y las clases de oF

class Fuel {

public: //Vista y acceso público de estos métodos

	Fuel(); //Constructor

	//Propiedades
	int bx, by, fx, fy;

	//Métodos
	void setup();
	void draw();

	ofImage fuel[2], bioFuel[2];

	//Constantes para ancho y alto de la pantalla en fullscreen
	const float width = 1920;
	const float height = 1080;
};

#endif //!Fuel
