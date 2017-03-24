#pragma once
#ifndef POINTSYSTEM_H
#define POINTSYSTEM_H
#include <SFML\Graphics.hpp>

//klasa reprezentujaca system punktow
class pointManager {
private:
	//punkty duh
	int points;
	//licznik czasu gry
	sf::Clock timeCounter;

public:
	//dodaj ppunkt
	void addPoint(int point);

	float getTime();
	//resetuj zegar
	void resetTimer();
	//resetuj punkty
	void restartPoints();

	pointManager();

	int getPoints();

};



#endif