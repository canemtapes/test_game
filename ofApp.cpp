#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowShape(960, 540); //Tamaño de la ventana por default

	ofSetFrameRate(60); //Seteamos el framerate en 60
	ofHideCursor(); //Ocultamos el cursor

	//Las variables boolenas
	fullScreen = false;
	pause = true;
	agree = false;
	jetOn = false;
	alienOn = false;

	//Cargamos las imagenes
	bg.load("img/background_root.png");
	jet.load("img/jet.png");
	alien.load("img/alien.png");

	//Cargamos los sonidos
	intro.load("audio/intro.wav");
	intro.play();
	normal.load("audio/juegonormal.wav");
	normal.play();
	fast.load("audio/juegorapido.wav");
	fast.play();

	//Cargamos las fuentes
	resourceFT.load("lucon.ttf", 20);
	messageFT.load("lucon.ttf", 40);
	//Cargamos los textos
	resource_text = "Recursos = 0";
	message_text = "¡Presiona ENTER para jugar!";
	//Posicionamos los textos
	messageTextPos.x = width / 2 - messageFT.stringWidth(message_text) / 2;
	messageTextPos.y = height / 2;

	//Inicializamos las variables de tipo enteras
	resources = 0;
	peopleMax = 6;
	//barra de tiempo
	timeBarHeight = 20;
	initialWidthTimeBar = 1000;
	timeBarWidth = initialWidthTimeBar;
	//Posicionamos la barra de tiempo
	timeBarPosition.set(width / 2 - initialWidthTimeBar / 2, height - height / 16);
	totalTime = 6.0f; //Tiempo total

	//Cargamos el setup de la clase Player
	player.setup();
	//Clase People
	for (int i = 0; i < peopleMax; i++) {
		people[i].setup();
	}
	//Clase Fuel
	for (int i = 0; i < 2; i++) {
		bioFuel[i].setup();
		fuel[i].setup();
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	//Si el juego no esta en PAUSA
	if (!pause) {

		//Timer
		timer();

		//Colisión personaje y personas
		playerCrash();

		//Colisión personaje y fuel
		fuelCollector();

		//Escenario/Paisaje
		scenery();

		//Actualizacion personas
		for (int i = 0; i < peopleMax; i++) {
			people[i].update();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	//Si el usuario presiona f/F escalamos todo para la pantalla completa
	if (fullScreen)
		ofScale(ofGetScreenWidth() / width, ofGetScreenHeight() / height);
	else
		ofScale(ofGetWidth() / width, ofGetHeight() / height);

	//Dibujamos las imagenes con sus respectivas posiciones dinamicas
	bg.draw(0, 0, width, height);
	jet.draw(jetPos);
	alien.draw(alienPos);

	//Color de la barra de tiempo
	ofSetColor(ofColor::red);
	ofDrawRectangle(timeBarPosition, timeBarWidth, timeBarHeight);

	//Color del texto de recursos
	ofSetColor(ofColor::white);
	resourceFT.drawString(resource_text, 20, 60);

	//Si esta en pausa muestra el texto "Presiona ENTER para jugar"
	if (pause) {
		ofSetColor(ofColor::white);
		messageFT.drawString(message_text, messageTextPos.x, messageTextPos.y);
	}

	//Fuel
	for (int i = 0; i < 2; i++) {
		bioFuel[i].draw();
		fuel[i].draw();
	}
	//Jugador
	player.draw();
	//Personas
	for (int i = 0; i < peopleMax; i++) {
		people[i].draw();
	}
}

//--- CALLBACK, esta escuchando si el usuario presiona determinada tecla ---------------
void ofApp::keyPressed(int key) {

	//Si presiona f/F
	if (key == 'f' || key == 'F') {
		fullScreen = !fullScreen;
		ofToggleFullscreen(); //fullscreen
	}

	//Si presiona ENTER
	if (key == OF_KEY_RETURN) {

		//Reseteamos recursos y tiempo
		resources = 0;
		totalTime = 6.0f;
		ofResetElapsedTimeCounter();
		//Pausa se vuelve false
		pause = !pause;
		//Volvemos a posicionar al jugador en la posición de origen.
		player.x = width / 2;
		player.y = height - 200;

		//Reseteamos las posiciones de las personas
		for (int i = 0; i < peopleMax; i++) {
			people[i].x = ofRandom(500, 1200);
			people[i].y = ofRandom(-1, -20);
		}
		//Reseteamos las posiciones de los bidones
		for (int i = 0; i < 2; i++) {
			fuel[i].fx = ofRandom(500, 1200);
			fuel[i].fy = ofRandom(100, 950);
			bioFuel[i].bx = ofRandom(500, 1200);
			bioFuel[i].by = ofRandom(100, 950);
		}

		//Las teclas de movimiento responden
		agree = true;

		soundSettings();
	}

	//Si no esta en pausa estas teclas responden
	if (agree) {
		//Si presiona flecha derecha
		if (key == OF_KEY_RIGHT && player.x < 1380) {
			//El juegador se mueve a la derecha en de 25 en 25
			player.x += 25;
			//Se suma medio segundo al tiempo total
			totalTime += 0.5f;

			agree = false;
		}

		//Si presiona flecha izquierda
		if (key == OF_KEY_LEFT && player.x > 490) {

			player.x -= 25;

			totalTime += 0.5f;

			agree = false;
		}

		//Si presiona flecha arriba
		if (key == OF_KEY_UP) {

			player.y -= 25;

			totalTime += 0.5f;

			agree = false;
		}

		//Si presiona flecha abajo
		if (key == OF_KEY_DOWN) {

			player.y += 25;

			totalTime += 0.5f;

			agree = false;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

	//Si no esta en pausa, agree es true.
	if (!pause) {
		agree = true;
	}
}

//--------------------------------------------------------------
void ofApp::timer() {
	//La barra de tiempo se ira actualizando segun el tiempo va pasando
	timeBarWidth = initialWidthTimeBar - initialWidthTimeBar * (ofGetElapsedTimef() / totalTime);

	//Si el tiempo se termina
	if (timeBarWidth <= 0.0f)
	{
		pause = true; //Se pausa el juego

		//Se muestra este mensaje en esta posición.
		message_text = "¡Te quedaste sin tiempo! ¡La nave ha despegado!";
		messageTextPos.x = width / 2 - (messageFT.stringWidth(message_text) / 2);
	}
}

//--------------------------------------------------------------
void ofApp::scenery() {
	//Si la nube esta en false
	if (!jetOn) {
		speed = ofRandom(1, 2); //velocidad de la nube random entre 1 y 3
		jetPos.set(ofRandom(200), -400); //la nube comienza fuera de la pantalla
		jetOn = true; //inicia el movimiento
	}
	else { //cuando esta en estado true
		jetPos.y += speed; //la posicion aumenta en relación a la velocidad
		if (jetPos.y > height) jetOn = false; //Si sale de la pantalla vuelve a iniciar el ciclo
	}

	if (!alienOn) {
		speed = ofRandom(1, 3); //velocidad de la nube random entre 1 y 3
		alienPos.set(ofRandom(1300, 1900), -900); //la nube comienza fuera de la pantalla
		alienOn = true; //inicia el movimiento
	}
	else { //cuando esta en estado true
		alienPos.y += speed; //la posicion aumenta en relación a la velocidad
		if (alienPos.y > height) alienOn = false; //Si sale de la pantalla vuelve a iniciar el ciclo
	}
}

void ofApp::soundSettings() {
	if (OF_KEY_RETURN) {

		if (!pause) {
			if (intro.isPlaying()) {
				intro.stop();
				normal.setLoop(true);
				normal.play();
			}
		}
		else if (pause && normal.isPlaying()) {
			normal.stop();
			intro.setLoop(true);
			intro.play();
		}
	}
}

//Colisión entre personaje y personas --------------------------
void ofApp::playerCrash() {
	for (int i = 0; i < 6; i++) {
		if ((people[i].y > player.y - 25) && (people[i].y < player.y + 25) && (people[i].x > player.x - 25) && (people[i].x < player.x + 25)) {
			pause = true;
			agree = false;

			//Se muestra este mensaje en esta posición.
			message_text = "¡Colisión!";
			messageTextPos.x = width / 2 - (messageFT.stringWidth(message_text) / 2);
		}
	}
}

//Colisión entre personaje y combustible -----------------------
void ofApp::fuelCollector() {
	//Texto que muestra el estado de los recursos recolectados
	resource_text = "Recursos = " + ofToString(resources);

	//PP agarra combustible contaminante
	for (int i = 0; i < 6; i++) {
		if ((fuel[i].fy > player.y - 25) && (fuel[i].fy < player.y + 25) && (fuel[i].fx > player.x - 25) && (fuel[i].fx < player.x + 25)) {
			resources += 5;
			totalTime -= 5;

			fuel[i].fx = ofRandom(500, 1200);
			fuel[i].fy = ofRandom(100, 950);
		}
	}

	//PP agarra combustible ecológico
	for (int i = 0; i < 6; i++) {
		if ((bioFuel[i].by > player.y - 25) && (bioFuel[i].by < player.y + 25) && (bioFuel[i].bx > player.x - 25) && (bioFuel[i].bx < player.x + 25)) {
			resources += 10;
			totalTime += 10;

			bioFuel[i].bx = ofRandom(500, 1200);
			bioFuel[i].by = ofRandom(100, 950);
		}
	}
}