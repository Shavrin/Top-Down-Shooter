#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include <SFML\Graphics.hpp>
#include <string>
#include "player.hpp"
#include <iostream>
#include "soundboard.h"



//klasa reprezentujaca pocisk
class Bullet {
private:
	//
	sf::Sprite bulletSprite;
	sf::Texture bulletTexture;

	//czy leci
	bool isActive; 
	//cel
	sf::Vector2f target;
	//pozycja
	sf::Vector2f position;


	


public:
	Bullet(player &Player, sf::Mouse &mouse, sf::RenderWindow &window);
	float getX();
	float getY();
	//sprawdza czy jest w oknie

	bool isInBounds();
	sf::Sprite getbulletSprite();

	//aktualizuje pozycje pocisku
friend 	void updateBullet(Bullet &bullet);
//rysuje pociski w wektorze
friend void drawBullets(std::vector<Bullet> & bullets, sf::RenderWindow &window);

//skanuje czy kule sa w obrebie okna, jak nie to usuwa z wektora
friend void scanBullets(std::vector<Bullet> &bullets);

};

//










class Weapon {
	//stats
protected:	
	//nazwa
	std::string name;


//pojemnosc magazynka i ilosc kul
	int magazineSize;
	int bulletsinMagazine;

	

	int reloadTime; //w sekundach

	sf::Clock reloadTimer;

	bool reloading;//czy przeladowywuje
	bool reloaded;//czy przeladowany

public:
	virtual bool isReloading() = 0;
	virtual bool isReloaded() = 0;
	virtual int getmagazineSize() = 0;
	virtual int getbulletsinMagazine() = 0;


	virtual void setReloading(bool  a) = 0;
	virtual void setReloaded(bool a) = 0;

	virtual void setbulletsinMagazine(int a) = 0;
	virtual void shootBullet(std::vector<Bullet> &bullets, player &Player, sf::Mouse &mouse,sf::RenderWindow &window, soundboard &Soundboard) = 0;
	virtual void reload() = 0;

	virtual void resetbulletsinMagazine() = 0;
	virtual int getReloadTime() = 0;
	virtual float getReloadTimer() = 0;

};


class Pistol :public Weapon {
public:
	Pistol(){
		name = "Pistolet";
	
		magazineSize = 8;
		bulletsinMagazine = 8;
		reloadTime = 2;
		reloading = false;
		reloaded = true;
	}



	bool isReloading();
	bool isReloaded();
	int getmagazineSize();
	int getbulletsinMagazine();
	void setbulletsinMagazine(int a);
	void setReloading(bool a);
	 void setReloaded(bool a);

	 void resetbulletsinMagazine();

	 int getReloadTime();
	 float getReloadTimer();

	//strzal
	void shootBullet(std::vector<Bullet> &bullets, player &Player, sf::Mouse &mouse, sf::RenderWindow &window, soundboard &Soundboard);
	//przeladowywanie
	void reload();
};

#endif