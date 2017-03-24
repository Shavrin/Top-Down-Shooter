#pragma once


#ifndef CROSSHAIR_H
#define CROSSHAIR_H


#include <SFML\Graphics.hpp>
#include <cmath>
#include "player.hpp"

//Reprezentuje celownik oraz "laser"
class Crosshair {

private:
	sf::Sprite crosshairSprite;
	sf::Texture crosshairTexture;
	sf::RectangleShape laser;
public:

	//konst
	Crosshair();

	//aktualizuje pozycje celownika w oparciu o wspolrzednie myszki wzgledem okna
	void updateCrosshair(sf::Mouse &mouse, sf::RenderWindow &window);

	//aktualizuje pozycje poczatku lasera i jego rotacje w oparciu o pozycje gracza i pozycje myszki
	void updateLaser(sf::Mouse &mouse, sf::RenderWindow &window, player &Player);



	//Rysuje laser
	void drawLaser(sf::RenderWindow &window);
	
	//Rysuje celownik
	void drawCrosshair(sf::RenderWindow &window);


};
#endif