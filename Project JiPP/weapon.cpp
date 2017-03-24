#include "weapon.hpp"
#include "soundboard.h"

Bullet::Bullet(player &Player, sf::Mouse &mouse, sf::RenderWindow &window) {

	if (!this->bulletTexture.loadFromFile("bulletTexture.png")) {
		std::cout << "Blad ladowania tekstury bulletTexture \n"<<std::endl;
	}


	
	
	bulletSprite.setOrigin(bulletSprite.getGlobalBounds().width / 2, bulletSprite.getGlobalBounds().height / 2);
	
	

	this->position.x = Player.getCOORDS().x;
	this->position.y = Player.getCOORDS().y;

	this->bulletSprite.setPosition(Player.getCOORDS());

	this->target.x = mouse.getPosition(window).x - Player.getCOORDSX();
	this->target.y = mouse.getPosition(window).y - Player.getCOORDSY();
}



float Bullet::getX() {
	return this->position.x;

}


float Bullet::getY() {
	return this->position.y;

}

bool Bullet::isInBounds() {
	if ((this->getX() < 0) || (this->getX() > WIDTH)) {
		return false;
	}
	if ((this->getY() < 0) || (this->getY() > HEIGHT)) {
		return false;
	}
	return true;
}


sf::Sprite Bullet::getbulletSprite(){
	return bulletSprite;
}
void updateBullet(Bullet &bullet) {

	float distance = sqrt(bullet.target.x*bullet.target.x + bullet.target.y*bullet.target.y);

	bullet.target.x = bullet.target.x / distance;
	bullet.target.y = bullet.target.y / distance;

	bullet.position.x += (float)(bullet.target.x * 10);
	bullet.position.y += (float)(bullet.target.y * 10);


	bullet.bulletSprite.setPosition(bullet.position.x, bullet.position.y);

}



void scanBullets(std::vector<Bullet> &bullets) {

	for (size_t i = 0; i < bullets.size(); ++i) {
		if (bullets[i].isInBounds() == true) {
			updateBullet(bullets[i]);
		}
		else{
			bullets.erase(bullets.begin() + i);
		}
	}


}

void drawBullets(std::vector<Bullet> & bullets, sf::RenderWindow &window) {
	for (size_t i = 0; i < bullets.size(); ++i) {


		bullets[i].bulletSprite.setTexture(bullets[i].bulletTexture);

	


		window.draw(bullets[i].bulletSprite);
	}
}


void Pistol::shootBullet(std::vector<Bullet> &bullets, player &Player, sf::Mouse &mouse, sf::RenderWindow &window, soundboard &Soundboard) {
	if(bulletsinMagazine >0){
		Bullet newBullet(Player, mouse, window);
		bulletsinMagazine--;
		bullets.push_back(newBullet);
		Soundboard.playPistolSound();
	}
	

}

void Pistol::reload() {
	//jesli juz nie przeladowywuje
	if (reloading == false) {
		reloadTimer.restart();
		//przeladowywanie true
		reloading = true;
		//jeszcze nie przeladowany
		reloaded = false;
	}
	//jesli przeladowywuje
	if(reloading == true){

		if (reloadTimer.getElapsedTime().asSeconds() >= reloadTime) {
			//jesli minal okreslony czas

			reloading = false;
			reloaded = true;

		}
	
	}
	
	

}


bool Pistol::isReloading() {
	return reloading;
}
bool Pistol::isReloaded() {
	return reloaded;
}
void Pistol::setbulletsinMagazine(int a) {
	bulletsinMagazine = a;
}

void Pistol::setReloading(bool a) {
	reloading = a;
}
void Pistol::setReloaded(bool a) {
	reloaded = a;
}

int Pistol::getmagazineSize() {
	return magazineSize;
}
int Pistol::getbulletsinMagazine() {
	return bulletsinMagazine;
}

int Pistol::getReloadTime() {
	return reloadTime;
}

float Pistol::getReloadTimer() {
	return reloadTimer.getElapsedTime().asSeconds();
}
void Pistol::resetbulletsinMagazine() {
	bulletsinMagazine = magazineSize;
}
