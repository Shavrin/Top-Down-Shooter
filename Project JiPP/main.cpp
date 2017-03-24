
/*Autor: Kacper Olek


*/


#include <vector>
#include <iostream>
#include <Windows.h>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>

#include "constants.hpp"
#include "player.hpp"
#include "bounds.hpp"
#include "crosshair.hpp"
#include "weapon.hpp"
#include "enemy.hpp"
#include "game.hpp"

#include "soundboard.h"
#include "menu.hpp"
#include "hud.hpp"

#include "pointSystem.hpp"

#include "deathscreen.hpp"



void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);
}






int  main() {

	pointManager pmanager;
	sf::Event e;
	player P(100, 5, HEIGHT / 2, WIDTH / 2);
	hudmanager HUD;



	//t³o
	sf::Texture background;
	if (!background.loadFromFile("background.png")) {
		std::cout << "Blad ladowania tekstury \n";
	}
	sf::Sprite backgroundsprite;
	backgroundsprite.setTexture(background);
	backgroundsprite.setPosition(sf::Vector2f(0, 0));
	//


	deathmanager Dmanager;
	menu menu;

	//Okno
	sf::VideoMode WindowType(WIDTH, HEIGHT);
	sf::RenderWindow window(WindowType, "Generic Shootah", sf::Style::Close);


	sf::Mouse mouse;
	Crosshair Cross;

	std::vector<Bullet> activeBullets;
	std::vector<Enemy> activeEnemys;


	game Game;


	Pistol pistolet;

	Weapon *weaponpointer = &pistolet;
	//zegar respawnu przeciwnika
	sf::Clock enemyTiming;
	sf::Time enemySpawn = sf::seconds(3);


	//zegar gry dla framerate'u
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	//niewidzialny kursor
	window.setMouseCursorVisible(false);

	//muzyka tla

	soundboard Soundboard;
	Soundboard.playBackgroundMusic();


	//stan gry
	_gameState  gamestate = Menu;







	while (window.isOpen()) {

	
		switch (gamestate) {

			//stan MENU
		case Menu: {

			//czysc
			window.clear();
			
			menu.handleMenu(e, window, gamestate);
			Cross.updateCrosshair(mouse, window);

			menu.draw(window, mouse);

			Cross.drawCrosshair(window);


			//wyswietlaj
			window.display();

				break;

		}









				   //stan gry
		case Running: {
			//interpolacja miedzy klatkami
			bool interpolation = false;

			//roznica czasowa miedzy klatkami
			timeSinceLastUpdate += clock.restart();


			//handlowanie wydarzeniami

			while (window.pollEvent(e)) {
				if (e.type == sf::Event::Closed) {
					window.close();
				}

				if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Escape)) {
					window.close();
				}

				//strzelanie
				if ((e.type == sf::Event::MouseButtonPressed) && (e.key.code == sf::Mouse::Left)) {
					if (!pistolet.isReloading()) {
						pistolet.shootBullet(activeBullets, P, mouse, window, Soundboard);
					}
				}

				
				//przeladowywanie
				if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::R)) {

					if ((pistolet.getbulletsinMagazine() >= 0) && (pistolet.getbulletsinMagazine() < pistolet.getmagazineSize())) {
						if (pistolet.isReloaded() == false && pistolet.isReloading() == false) {
							Soundboard.playReloadSound();

							pistolet.reload();
						}
					}
				}





			}

			// logika gry

			while (timeSinceLastUpdate >= TimePerFrame) {

				//Resetuje licznik czasu w odpowiednim momencie
				if (!Game.getInitialized()) {
					pmanager.resetTimer();
					Game.setInitialized(true);
				}

				//interpolacja on
				interpolation = true;
				// reloading checker
				if (pistolet.isReloading() == true) {
					pistolet.reload();
				}

				if (pistolet.isReloaded() == true) {

					pistolet.setbulletsinMagazine(pistolet.getmagazineSize());
					pistolet.setReloaded(false);
				}
				//


				//aktualizacja hud

				HUD.updateHUD(P, pmanager.getTime(), weaponpointer);


				//spawning przeciwnikow
				if (enemyTiming.getElapsedTime().asSeconds() >= enemySpawn.asSeconds()) {
					spawn(activeEnemys);

					enemyTiming.restart();
				}
				//sprawdzanie kolizji potworek pocisk
				for (size_t i = 0; i < activeEnemys.size(); i++) {
					activeEnemys[i].checkBullets(activeBullets, Soundboard);
					
				}


				//sterowanie graczem
				P.controlPlayer(mouse, window);
				//skanowanie aktywnych kul
				scanBullets(activeBullets);
				//celownik
				Cross.updateCrosshair(mouse, window);
				//kolizje gracza ze scianami
				checkcollisions(P);
				//laser
				Cross.updateLaser(mouse, window, P);
				//skanowanie przeciwnikow i ich aktualizacja
				scanEnemys(activeEnemys, P, pmanager,Soundboard);
				//jesli gracz umrze to game over
				if (P.getHP() <= 0) {
					gamestate = Gameover;
				}


				timeSinceLastUpdate -= TimePerFrame;



			}

			// rysowanie grafiki
			if (interpolation) {

			
				window.clear();


				//t³o
				window.draw(backgroundsprite);

				//hpbar
				HUD.drawHpBar(window);

				//laser
				Cross.drawLaser(window);
				//gracz
				P.drawPlayer(window);

				//przypominajka o przeladowaniu
				if (pistolet.getbulletsinMagazine() == 0) {
					HUD.drawReloadReminder(window);
				}
				//rysowanie kul
				drawBullets(activeBullets, window);
				//rysowanie przeciwnikow
				drawEnemys(activeEnemys, window, P);
				//rysowanie lasera
				Cross.drawCrosshair(window);
				//czas
				HUD.drawTimeIndicator(window);
				//amunicja
				HUD.drawammoIndicator(window);
				//reload timer
				if (pistolet.isReloading() == true) {

					HUD.drawReloadTimer(window);

				}
				window.display();
			}
			break;

		}


		//stan game over
		case Gameover: {
			if (!Dmanager.getInitialized()) {
				//jesli nie sa zainicjalizowanie to zainicjalizuj wyniki
				Dmanager.initializeResults(pmanager);
			}
			else {

				while (window.pollEvent(e)) {
					if (e.type == sf::Event::Closed) {
						window.close();
					}
					//reset wszystkiego
					if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Escape)) {
						pmanager.resetTimer();
						pmanager.restartPoints();
						P.resetHP();
						resetEnemys(activeEnemys);
						pistolet.resetbulletsinMagazine();
						gamestate = Menu;
					}
				}


				window.clear(sf::Color::Black);
				//celownik
				Cross.updateCrosshair(mouse, window);
				//rysowanie ekranu smierci z wynikami
				Dmanager.drawDeathscreen(window);
				Dmanager.drawResults(window);
				Cross.drawCrosshair(window);
				window.display();
			}
			break;

		}


		}

	}
	return EXIT_SUCCESS;
}
