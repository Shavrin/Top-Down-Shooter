
#include "deathscreen.hpp"



bool deathmanager::getInitialized() {
	return initialized;
}
	deathmanager::deathmanager() {
		if (!scoreFont.loadFromFile("timeIndicator.ttf"))
			std::cout << "Couldn't load font";

		scoreText.setFont(scoreFont);

		timeSurvived.setFont(scoreFont);
		killedMonsters.setFont(scoreFont);

		if (!deathscreenBackgroundTexture.loadFromFile("deathscreenBackground.png")) {
			std::cout << "couldnt load png";
		}

		if (!deathscreenFont.loadFromFile("finalf.ttf")) {
			//do sth
		}

		deathscreenText.setFont(deathscreenFont);

		deathscreenText.setString("YOU DIED \n    \n SCORE  \n \n TIME SURVIVED  \n \n KILLED MONSTERS \n \n PRESS ESC TO GO BACK TO MENU");

		deathscreenText.setCharacterSize(50);
		deathscreenText.setColor(sf::Color::Black);

		deathscreenText.setOrigin(deathscreenText.getGlobalBounds().width / 2, deathscreenText.getGlobalBounds().height / 2);
		deathscreenText.setPosition(WIDTH / 2, HEIGHT / 2);

		deathscreenBackgroundSprite.setTexture(deathscreenBackgroundTexture);
		deathscreenBackgroundSprite.setPosition(sf::Vector2f(0, 0));

		scoreText.setCharacterSize(50);
		scoreText.setColor(sf::Color::Red);

		timeSurvived.setCharacterSize(50);
		killedMonsters.setCharacterSize(50);


		timeSurvived.setColor(sf::Color::Red);
		killedMonsters.setColor(sf::Color::Red);

		initialized = false;
	}

	void deathmanager::initializeResults(pointManager &pmanager) {

		int score = (int)pmanager.getTime() * pmanager.getPoints();
	

		scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2);
		scoreText.setPosition((float)(WIDTH / 1.8), (float)(HEIGHT / 3));


		timeSurvived.setOrigin(timeSurvived.getGlobalBounds().width / 2, timeSurvived.getGlobalBounds().height / 2);
		timeSurvived.setPosition((float)(WIDTH / 1.8), (float)(HEIGHT / 2.2));


		killedMonsters.setOrigin(killedMonsters.getGlobalBounds().width / 2, killedMonsters.getGlobalBounds().height / 2);
		killedMonsters.setPosition((float)(WIDTH / 1.8), (float)(HEIGHT / 1.7));

		killedMonsters.setString(std::to_string(pmanager.getPoints()));

		timeSurvived.setString(std::to_string(pmanager.getTime()));


		scoreText.setString(std::to_string(score));
		initialized = true;

	}

	void deathmanager::drawDeathscreen(sf::RenderWindow &window) {
		window.draw(deathscreenBackgroundSprite);

	}

	void deathmanager::drawResults(sf::RenderWindow &window) {
		window.draw(scoreText);
		window.draw(timeSurvived);
		window.draw(killedMonsters);
		window.draw(deathscreenText);
	}









