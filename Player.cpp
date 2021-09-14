#include "Player.h" //Referencia al header donde se declaran los métodos

Player::Player() {
	x = width / 2;
	y = 800;
}

void Player::setup() {
	player.load("img/moto_chica.png");
}

void Player::update() {

}

void Player::draw() {
	player.setAnchorPercent(0.5, 0.5); //eje de la imagen centrada
	player.draw(x, y);
}
