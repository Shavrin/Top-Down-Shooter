

#include "enemy.hpp"
#include "player.hpp"
#include "pointSystem.hpp"
#include "soundboard.h"
#include <iostream>


void Enemy::looseHP(int HP) {
	this->hp = hp - HP;
}

Enemy::Enemy() {
	this->hp = 100;
	this->attackSpeed = 1;
	this->movementSpeed = 3.5;
	//losowanie gdzie sie zespawnuje
	int spawnupdownleftright = rand() % 5+1;
	
	switch (spawnupdownleftright) {
	//lewo
	
	case 1:
		this->coords.x = -5;
		this->coords.y = (float)(HEIGHT / (rand() % 5 + 1));
		break;
	//prawo
	case 2:
		this->coords.x = WIDTH + 5;
		this->coords.y = (float)(HEIGHT / (rand() % 5 + 1));
		break;
	//gora
	
	case 3: 
		this->coords.y = -5;
		this->coords.x = (float)(WIDTH / (rand() % 5 + 1));
		break;
	
	//dol
	case 4:
		this->coords.y = HEIGHT + 5;
		this->coords.x = (float)(WIDTH / (rand() % 5 + 1));
		break;

	
	}
	if (!this->Texture.loadFromFile("enemySpriteSheet.png") ){

	}


	this->Sprite.setOrigin(Sprite.getGlobalBounds().width / 2, Sprite.getGlobalBounds().height / 2);

	this->Sprite.setPosition(coords);

	

	



}

int Enemy::getHP() {
	return this->hp;

}

void Enemy::checkBullets(std::vector<Bullet> &activeBullets, soundboard &Soundboard) {

	//dla kazdego pocisku jesli jest przechodzi przez potworka to potworek traci hp + dzwiek + kula znika
	for (size_t i = 0; i < activeBullets.size(); i++) {
		if (this->Sprite.getGlobalBounds().intersects(activeBullets[i].getbulletSprite().getGlobalBounds())) {
			this->looseHP(PISTOL_DAMAGE);
			Soundboard.playMonsterOuch();

			activeBullets.erase(activeBullets.begin()+ i);
		}

	}


}

void resetEnemys(std::vector<Enemy> &activeEnemys) {
	activeEnemys.clear();
}


void Enemy::update(player &Player,soundboard &Soundboard) {

	this->target = Player.getCOORDS() - coords;

	float distance = sqrt(target.x*target.x + target.y*target.y);
	//jesli dystans jest wiekszy od 30 to podozaj za graczem
		if (distance > 30) {

			this->target.x = target.x / distance;
			this->target.y = target.y / distance;


			this->coords.x += (float)(target.x * movementSpeed);
			this->coords.y += (float)(target.y * movementSpeed);




		}//jesli nie to atakuj
		else {
			if (this->attackTiming.getElapsedTime().asSeconds() > this->attackSpeed) {
				//co sekunde -20hp
				Soundboard.playPlayerOuch();
				Player.looseHP(20);
				//resetuj zegar
				this->attackTiming.restart();
			}
		}
	
	this->Sprite.setPosition(this->coords);

}


void Enemy::draw(sf::RenderWindow &window) {
	window.draw(this->Sprite);
}


void scanEnemys(std::vector<Enemy> &activeEnemys,player &player,pointManager &pmanager, soundboard &Soundboard) {
	for (size_t i = 0; i < activeEnemys.size(); ++i) {
		if (activeEnemys[i].getHP()>0) {
			//jesli ma powyzej 0 hp to aktualizuj
			activeEnemys[i].update(player,Soundboard);
		}
		else {

			//jesli nie to dodaj punkt dla gracza i usun przeciwnika z wektora

			pmanager.addPoint(1);
			activeEnemys.erase(activeEnemys.begin() + i);
		}

	}
}

void spawn(std::vector<Enemy> &activeEnemys) {
	Enemy newEnemy;
	activeEnemys.push_back(newEnemy);
}


void drawEnemys(std::vector<Enemy> & activeEnemys, sf::RenderWindow &window,player &P) {

	//do rotacji w strone gracza
	float distX, distY, angle;


	for (size_t i = 0; i < activeEnemys.size(); i++) {
		activeEnemys[i].Sprite.setTexture(activeEnemys[i].Texture);
		distX = P.getCOORDSX() - activeEnemys[i].getCoords().x;
		distY = P.getCOORDSY() - activeEnemys[i].getCoords().y;
		
		angle = atan2(distY, distX);
		angle = (float)(angle * (180 / PI) - 90);
		activeEnemys[i].setRotation(angle);




		activeEnemys[i].draw(window);
	}
}

