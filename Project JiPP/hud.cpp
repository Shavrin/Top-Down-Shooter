
#include "hud.hpp"


	hudmanager::hudmanager() {

		if (!hpbarTexture.loadFromFile("hpBarTexture.png")) {
			std::cout << "Blad ladowania tekstury" << std::endl;
		}
		pHpBarTexture = &hpbarTexture;

		hpbar.setTexture(pHpBarTexture);

		hpbar.setPosition(50, 50);
		if (!timeindicatorFont.loadFromFile("timeIndicator.ttf")) {
			std::cout << "Blad ladowania czcionki timeIndicator.ttf";
		}
		timeindicator.setFont(timeindicatorFont);

		timeindicator.setCharacterSize(25);

		timeindicator.setPosition((float)(WIDTH / 2.25), 50);
		timeindicator.setString("00:00");
		timeindicator.setColor(sf::Color::Yellow);

		if (!ammoIndicatorTexture.loadFromFile("ammoIndicator.png")) {
			std::cout << "Blad ladowania tekstury ammoindicator";
		}

		pammoIndicatorTexture = &ammoIndicatorTexture;
		ammoIndicator.setSize(sf::Vector2f(150, 25));
		ammoIndicator.setTexture(pammoIndicatorTexture);
		ammoIndicator.setPosition((float)(WIDTH / 1.35), 50);

		ammoIndicatorText.setFont(timeindicatorFont);
		ammoIndicatorText.setPosition((float)(WIDTH / 1.35), 20);
		ammoIndicatorText.setCharacterSize(25);
		ammoIndicatorText.setColor(sf::Color::Red);


		if (!reloadReminderTexture.loadFromFile("reloadReminderTexture.png")) {

			//do sth
		}
		reloadReminderSprite.setTexture(reloadReminderTexture);
		reloadReminderSprite.setPosition((float)(WIDTH / 1.35), 70);





	}



	void hudmanager::drawHpBar(sf::RenderWindow &window) {
		window.draw(hpbar);
	}
	void hudmanager::drawTimeIndicator(sf::RenderWindow &window) {
		window.draw(timeindicator);
	}
	void hudmanager::drawammoIndicator(sf::RenderWindow &window) {
		window.draw(ammoIndicator);

	}
	void hudmanager::drawReloadTimer(sf::RenderWindow &window) {

		window.draw(ammoIndicatorText);

	}
	void hudmanager::drawReloadReminder(sf::RenderWindow &window) {
		window.draw(reloadReminderSprite);

	}
	void hudmanager::updateHUD(player &P, float Time, Weapon *wep) {
		this->hpbar.setSize(sf::Vector2f((float)P.getHP() * 2, 25));
		this->hpbar.setPosition(50, 50);


	//zamiana floata na string
		std::string timestring = std::to_string((int)Time);
		timeindicator.setString(timestring);

		timeindicator.setOrigin(timeindicator.getGlobalBounds().width / 2, timeindicator.getGlobalBounds().height / 2);

		ammoIndicator.setSize(sf::Vector2f((float)((*wep).getbulletsinMagazine() * 14), 25));

		


		std::string ammostring = std::to_string((*wep).getReloadTime() - (*wep).getReloadTimer());
		ammoIndicatorText.setString(ammostring);


	}



