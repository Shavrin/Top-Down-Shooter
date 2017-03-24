#include "menu.hpp"
#include <iostream>
#include "constants.hpp"
#include "game.hpp"
menu::menu() {
	
	if (!backgroundTexture.loadFromFile("background.png")) {

	}

	if (!menuFont.loadFromFile("finalf.ttf")) {
		
	}
	if (!titleFont.loadFromFile("finalf.ttf")) {

	}

	background.setTexture(backgroundTexture);
	background.setPosition(0, 0);
	titleText.setCharacterSize(80);
	titleText.setFont(titleFont);
	titleText.setColor(sf::Color::Black);
	titleText.setString("GENERIC SHOOTAH!");
	titleText.setOrigin(titleText.getGlobalBounds().width / 2, titleText.getGlobalBounds().height / 2);
	titleText.setStyle(sf::Text::Italic);
	titleText.setPosition(WIDTH / 2, HEIGHT / 7);



	menuText[0].setString("PLAY");
	menuText[1].setString("EXIT");
	


	for (int i = 0; i < 2; i++) {
		menuText[i].setFont(menuFont);
		menuText[i].setCharacterSize(75);
		menuText[i].setColor(sf::Color::Black);
		menuText[i].setOrigin(menuText[i].getGlobalBounds().width / 2, menuText[i].getGlobalBounds().height / 2);
		menuText[i].setStyle(sf::Text::Bold);
	}

	

	menuText[0].setPosition(WIDTH / 2, HEIGHT / 4 * 2);
	menuText[1].setPosition(WIDTH / 2, HEIGHT / 4 * 3);






	
	selectedItem = -1;






}

void menu::draw(sf::RenderWindow &window,sf::Mouse &mouse) {

	//sprawdzanie ktora opcja jest wybrana
	selectedItem = -1;
	if (mouse.getPosition(window).x >= menuText[0].getPosition().x - menuText[0].getGlobalBounds().width / 2 && mouse.getPosition(window).x <= menuText[0].getPosition().x + menuText[0].getGlobalBounds().width / 2) {

		if (mouse.getPosition(window).y >= menuText[0].getPosition().y - menuText[0].getGlobalBounds().height / 2 && mouse.getPosition(window).y <= menuText[0].getPosition().y + menuText[0].getGlobalBounds().height / 2) {
			selectedItem = 0;
		}

		if (mouse.getPosition(window).y >= menuText[1].getPosition().y - menuText[1].getGlobalBounds().height / 2 && mouse.getPosition(window).y <= menuText[1].getPosition().y + menuText[1].getGlobalBounds().height / 2) {
			selectedItem = 1;
		}


	


	}


	//handlowanie z tym
	switch (selectedItem) {
	case 0:
			menuText[0].setColor(sf::Color::Red);
			break;

	case 1:

			menuText[1].setColor(sf::Color::Red);
			break;


	case -1:
		menuText[0].setColor(sf::Color::Black);
		menuText[1].setColor(sf::Color::Black);

			break;
	}

	//rysuj tlo i tytu;
	window.draw(background);
	window.draw(titleText);
	//no i opcje
		for (int i = 0; i < 2; i++) {
		window.draw(menuText[i]);

	}
}


void menu::handleMenu(sf::Event &e,sf::RenderWindow &window,enum _gameState &gamestate) {

		while (window.pollEvent(e)) {

			if (e.type == sf::Event::Closed) {
				window.close();
			}


			switch (e.key.code) {


		
		

			case sf::Mouse::Left:{
				switch (selectedItem) {

				case 0: gamestate = Running;
					break;

				case 1: window.close();
					break;

				}
			default: break;
				break;
				}
			}
		}


	}

