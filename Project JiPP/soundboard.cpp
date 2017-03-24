#include "soundboard.h"


	soundboard::soundboard() {


		if (!backgroundmusic.openFromFile("MenuMusicRoundabout.ogg")) {
			std::cout << "Blad ladowania pliku ogg \n";
		}
		if (!pistolSoundHolder.loadFromFile("pistolSound.ogg")) {
			std::cout << "Blad ladowania pliku ogg" << std::endl;
		}
		pistolSound.setBuffer(pistolSoundHolder);
		pistolSound.setVolume(100);

		backgroundmusic.setVolume(50);
		backgroundmusic.setLoop(true);

		if (!monsterOuchBuffer.loadFromFile("monsterOuch.wav")) {
			std::cout << "Couldn't load monsterOuch.wav";
		}
		monsterOuch.setBuffer(monsterOuchBuffer);
		monsterOuch.setVolume(100);

		if(!pistolReloadBuffer.loadFromFile("reloadSound.ogg")) {

		}

		pistolReload.setBuffer(pistolReloadBuffer);

		pistolReload.setVolume(100);


		if (!playerOuchBuffer.loadFromFile("playerOuchSound.ogg")) {

		}
		playerOuch.setBuffer(playerOuchBuffer);
		playerOuch.setVolume(100);

	}

	void soundboard::playMonsterOuch() {
		monsterOuch.play();
	}

	void soundboard::playBackgroundMusic() {
		backgroundmusic.play();

	}
	void soundboard::stopBackgroundMusic() {
		backgroundmusic.stop();
	}
	void soundboard::playPistolSound() {
		pistolSound.play();
	}


	void soundboard::playReloadSound() {
		pistolReload.play();
	}


	void soundboard::playPlayerOuch() {
		playerOuch.play();
	}









