#pragma once

#ifndef _Player
#define _Player

#include "ofMain.h" //Agregamos los m�todos y las clases de oF

class Player {

public: //Vista y acceso p�blico de estos m�todos

	Player(); //Constructor

	//Propiedades
	int x, y;

	//M�todos
	void setup();
	void update();
	void draw();

	ofImage player;

	//Constantes para ancho y alto de la pantalla en fullscreen
	const float width = 1920;
	const float height = 1080;
};

#endif //!Player

