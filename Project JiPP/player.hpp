#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include "constants.hpp"
//klasa reprezentuj¹ca gracza
class player {
	private:

		//zycie
	int HP;
	//predkosc chodzenia
	float SPEED;
	//koordynaty
	sf::Vector2f playerCOORDS;
	//wektor przyspieszenia
	sf::Vector2f playerVelocity;
	//tekstura i sprite
	sf::Texture Texture;
	sf::Sprite Sprite;

public:


	player(int HP, float SPEED, float coordX, float coordY);

	//resetuj zycie
	void resetHP() {
		HP = 100;
	}
	
	int getHP();
	sf::Vector2f getCOORDS();
	float getCOORDSX();
	float getCOORDSY();

	void setCOORDS(float x, float y);
	void setCOORDS(sf::Vector2f COORDS);
	//odwraca kierunek wektora predkosci i dzieli go przez ilestam
	void invertVelocityX();
	void invertVelocityY();
	
	sf::Vector2f getVelocity();
	//odejmuje o ilosc HP
	void looseHP(int HP);
	//Sterowanie graczem
	void controlPlayer(sf::Mouse &mouse, sf::RenderWindow &window);

	//rysowanie gracza
	void drawPlayer(sf::RenderWindow &window);
	
			
		
	
};

#endif