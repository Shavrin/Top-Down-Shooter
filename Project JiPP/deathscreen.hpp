#pragma once
#ifndef DEATHSCREEN_HPP
#define DEATHSCREEN_HPP
#include "SFML\Graphics.hpp"
#include <iostream>
#include "pointSystem.hpp"
#include "constants.hpp"
#include <string>
//Klasa reprezentuj¹ca ekran smierci

class deathmanager {
private:

	//Czcionki
	sf::Font scoreFont;
	sf::Font deathscreenFont;
	

	//Poszczegolne wyswietlane dane
	sf::Text scoreText;
	sf::Text timeSurvived;
	sf::Text killedMonsters;
	sf::Text deathscreenText;

	//Tlo
	sf::Texture deathscreenBackgroundTexture;
	sf::Sprite deathscreenBackgroundSprite;


	//Czy zainizjalizowany
	bool initialized;

public:
	//konst
	deathmanager();
	
	bool getInitialized();
		//inicjalizuje wyniki gry
	void initializeResults(pointManager &pmanager);
	//Wyswietla ekran smierci 
	void drawDeathscreen(sf::RenderWindow &window);
	//wyswietla wyniki
	void drawResults(sf::RenderWindow &window);
	





};


#endif // !DEATHSCREEN_HPP
