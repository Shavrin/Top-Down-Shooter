#pragma once
#ifndef HUD_HPP
#define HUD_HPP
#include <SFML\Graphics.hpp>
#include <iostream>
#include "constants.hpp"
#include "player.hpp"
#include <sstream>
#include <string>
#include "weapon.hpp"
//Klasa reprezentujaca hud gry
class hudmanager {
private:
	//HP BAR
	sf::RectangleShape hpbar;
	sf::Texture hpbarTexture;
	sf::Texture *pHpBarTexture;
	//indykator czasu
	sf::Font timeindicatorFont;
	sf::Text timeindicator;
	//indykator amunicji
	sf::RectangleShape ammoIndicator;
	sf::Texture ammoIndicatorTexture;
	sf::Texture *pammoIndicatorTexture;
	sf::Text ammoIndicatorText;
	
	//przypominajka o przeladowaniu
	sf::Texture reloadReminderTexture;
	sf::Sprite reloadReminderSprite;


public:
	hudmanager();
	

	//rysuj pasek zycia
	void drawHpBar(sf::RenderWindow &window);
	//Rysuj licznik czasu
	void drawTimeIndicator(sf::RenderWindow &window);
	//rysuj pasek amunicji
	void drawammoIndicator(sf::RenderWindow &window);
	//rysuj licznik przeladowania
	void drawReloadTimer(sf::RenderWindow &window);
	//rysuj przypominajke o przeladowaniu
	void drawReloadReminder(sf::RenderWindow &window);
	//aktualizuj dane huda
	void updateHUD(player &P, float Time, Weapon *wep);
};

#endif // !HUD_HPP
