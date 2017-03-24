
#include "player.hpp"

#include <iostream>

//w zaleznosci jaki klawisz jest nacisniety - dodawany jest odpowiednia wartosc do wektora predkosci
//jesli nie jest nacisniety jedne przycisk to wartosc zeruje sie
void player::controlPlayer(sf::Mouse &mouse,sf::RenderWindow &window) {
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
		if (playerVelocity.x > -MAXSPEED) {

			playerVelocity.x = playerVelocity.x - 0.5f;

		}
	}
	else if (playerVelocity.x < 0) { playerVelocity.x += 0.25f; }

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		if (playerVelocity.x < MAXSPEED) {

			playerVelocity.x = playerVelocity.x + 0.5f;
		}
	}
	else if (playerVelocity.x > 0) { playerVelocity.x -= 0.25f; }



	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
		if (playerVelocity.y > -MAXSPEED) {

			playerVelocity.y = playerVelocity.y - 0.5f;
		}
	}
	else if (playerVelocity.y < 0) { playerVelocity.y += 0.25f; }


	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
		if (playerVelocity.y < MAXSPEED) {
			playerVelocity.y = playerVelocity.y + 0.5f;
		}
	}
	else if (playerVelocity.y > 0) { playerVelocity.y -= 0.25f; }



	//aktualizacja pozycji
	playerCOORDS.x = (float)(playerCOORDS.x + playerVelocity.x);
	playerCOORDS.y = (float)(playerCOORDS.y + playerVelocity.y);

	//no i rotacja
	float distX = mouse.getPosition(window).x - playerCOORDS.x;
	float distY = mouse.getPosition(window).y - playerCOORDS.y;

	float angle = atan2(distY, distX);
	angle = (float)(angle * (180 / PI));


	Sprite.setOrigin((float)(Sprite.getTextureRect().width / 2), (float)(Sprite.getTextureRect().height / 2));

	Sprite.setRotation(angle);
	Sprite.setPosition(playerCOORDS.x,playerCOORDS.y);
}

void player::drawPlayer(sf::RenderWindow &window) {
	window.draw(Sprite);


}

sf::Vector2f player::getCOORDS() {
	return this->playerCOORDS;

}

float player::getCOORDSX() {
	return playerCOORDS.x;

}

float player::getCOORDSY() {
	return playerCOORDS.y;


}

int player::getHP() {
	return this->HP;

}

sf::Vector2f player::getVelocity() {
	return playerVelocity;

}


void player::invertVelocityX() {
	playerVelocity.x = -playerVelocity.x;

}
void player::invertVelocityY() {
	playerVelocity.y = -playerVelocity.y;


}

player::player(int HP, float SPEED, float coordX, float coordY) {
	this->HP = HP;
	this->SPEED = SPEED;
	this->playerCOORDS.x = coordX;
	this->playerCOORDS.y = coordY;
	
	this->playerVelocity = sf::Vector2f(0, 0);

	if (!this->Texture.loadFromFile("playertexture.png")) {

		std::cout << "Blad ladowania tekstury gracza\n";
	}

	this->Sprite.setTexture(this->Texture);
	
	

}

void player::setCOORDS(float x, float y) {
	this->playerCOORDS.x = x;
	this->playerCOORDS.y = y;
}
void player::setCOORDS(sf::Vector2f COORDS) {
	this->playerCOORDS = COORDS;

}

void player::looseHP(int HP) {
	this->HP = this->HP - HP;
}