#include "pointSystem.hpp"


void pointManager::addPoint(int point) {
	points += point;


}
int pointManager::getPoints() {
	return points;

}

float pointManager::getTime() {
	return timeCounter.getElapsedTime().asSeconds();

}

pointManager::pointManager() {
	points = 0;

}
void pointManager::resetTimer() {
	timeCounter.restart();

}
void pointManager::restartPoints() {
	points = 0;

}
