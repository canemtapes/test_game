#pragma once

#ifndef _Player
#define _Player

#include "ofMain.h" //Agregamos los métodos y las clases de oF

class Player {

public: //Vista y acceso público de estos métodos

	Player(); //Constructor

	//Propiedades
	int x, y;

	//Métodos
	void setup();
	void update();
	void draw();

	ofImage player;

	//Constantes para ancho y alto de la pantalla en fullscreen
	const float width = 1920;
	const float height = 1080;
};

#endif //!Player

