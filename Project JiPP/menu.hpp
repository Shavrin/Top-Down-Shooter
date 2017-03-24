#pragma once
#ifndef MENU_H
#define MENU_H

#include <SFML\Graphics.hpp>
//klasa reprezentuj¹ca menu
class menu {
private:
	//wybrana pozycja
	short int selectedItem;

	//czcionka i text menu
	sf::Font menuFont;
	sf::Text menuText[2];
	//tytul
	sf::Font titleFont;
	sf::Text titleText;
	//t³o
	sf::Sprite background;
	sf::Texture backgroundTexture;

public:
	menu();
	//rysuj menu
	void draw(sf::RenderWindow &window,sf::Mouse &mouse);

	//obsluga menu
	void handleMenu(sf::Event &event, sf::RenderWindow &window,enum _gameState &gamestate);

};

#endif