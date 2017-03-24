#pragma once
#ifndef ENEMY_H
#define ENEMY_H



#include "weapon.hpp"

#include "constants.hpp"
#include <SFML\Graphics.hpp>
#include "pointSystem.hpp"
#include "soundboard.h"

//klasa reprezentuj¹ca przeciwnika
class Enemy {
private:
	int hp;
	float movementSpeed;//unit per frame

	int attackSpeed; //w sekundach

	sf::Vector2f coords; // obecne koordynaty
	sf::Vector2f target; //koordynaty celu

	//sprite i tekstura
	sf::Texture Texture;
	sf::Sprite Sprite;

	sf::Clock attackTiming; //zegar odmierzajacy czas miedzy atakami

public:


	Enemy();
	//Zwraca ilosc hp
	int getHP();
	//sprawdza czy kula nie uderzyla w sprite'a enemy
	void checkBullets(std::vector<Bullet> &activeBullets, soundboard &Soundboard);
	//Odejmuja okreslona liczbe hp
	void looseHP(int HP);
	//aktualizuje polozenie przeciwnika -> porusza sie w linii prostej w strone gracza
	void update(player &Player, soundboard &Sounboard);
	//Rysuje Enemy
	void draw(sf::RenderWindow &window);

	sf::Sprite getSprite() {
		return Sprite;
	}

	sf::Texture getTexture() {
		return this->Texture;
	}

	sf::Vector2f getCoords() {
		return coords;
	}


	void setSprite(sf::Sprite &sprite) {
		Sprite = sprite;
	}
	void setTexture(sf::Texture &texture) {
		Texture = texture;
	}
	void setCoords(sf::Vector2f &coord) {
		coords = coord;
	}
	void setRotation(float angle) {
		Sprite.setRotation(angle);
	}
	void setTexturetoSprite(sf::Texture &text) {
		Sprite.setTexture(text);
	}

	//Rysuje wszystkich przeciwnikow w wektorze z przeciwnikami
	friend void drawEnemys(std::vector<Enemy> &activeEnemys, sf::RenderWindow &window, player &P);

};

//Czysci wektor przeciwnikow
void resetEnemys(std::vector<Enemy> &activeEnemys);
//Skanuje wektor przeciwnikow i sprawdza czy ktorys nie ma HP ponizej 0, jesli tak to go usuwa
void scanEnemys(std::vector<Enemy> &activeEnemys,player &player, pointManager &pmanager, soundboard &Soundboard);
//Spawnuje przeciwnika na granicach okna
void spawn(std::vector<Enemy> &activeEnemys);

#endif ENEMY_H