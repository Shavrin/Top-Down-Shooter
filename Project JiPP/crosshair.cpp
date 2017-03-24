#include "crosshair.hpp"



Crosshair::Crosshair() {

	if (!crosshairTexture.loadFromFile("crosshairTexture.png")) {

	}
	crosshairSprite.setTexture(crosshairTexture);
	crosshairSprite.setOrigin(crosshairSprite.getGlobalBounds().width / 2, crosshairSprite.getGlobalBounds().height / 2);


	
}

void Crosshair::drawCrosshair(sf::RenderWindow &window) {
	window.draw(crosshairSprite);


}

void Crosshair::drawLaser(sf::RenderWindow &window) {
	window.draw(laser);

}


void Crosshair::updateCrosshair(sf::Mouse &mouse, sf::RenderWindow &window) {

	crosshairSprite.setPosition((float)(mouse.getPosition(window).x), (float)(mouse.getPosition(window).y));

}


void Crosshair::updateLaser(sf::Mouse &mouse, sf::RenderWindow &window, player &Player) {
	laser.setFillColor(sf::Color::Red);
	laser.setOutlineThickness(0);
	float distX = mouse.getPosition(window).x - Player.getCOORDSX();
	float distY = mouse.getPosition(window).y - Player.getCOORDSY();

	float Distance = sqrt(distX*distX + distY*distY);

	laser.setPosition(Player.getCOORDSX(), Player.getCOORDSY());
	laser.setSize(sf::Vector2f(1, WIDTH / 8));
	float angle = atan2(distY, distX);
	angle = (float)(angle * (180 / PI) - 90);
	laser.setRotation(angle);

}