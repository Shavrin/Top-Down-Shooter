#pragma once

#ifndef SOUNDBOARD_H
#define SOUNDBOARD_H

#include <iostream>
#include <SFML\Audio.hpp>

//klasa reprezentujaca dzwieki gry

class soundboard{
private:
	//muzyka w tle
	sf::Music backgroundmusic;
	//strzal pistoletu
	sf::Sound pistolSound;
	sf::SoundBuffer pistolSoundHolder;
	//potworek
	sf::Sound monsterOuch;
	sf::SoundBuffer monsterOuchBuffer;
	//przeladowanie
	sf::Sound pistolReload;
	sf::SoundBuffer pistolReloadBuffer;
	//uderzenie potworka
	sf::Sound playerOuch;
	sf::SoundBuffer playerOuchBuffer;

public:
	soundboard();


	// ^^
	void playMonsterOuch();
	void playBackgroundMusic();
	void stopBackgroundMusic();
	void playPistolSound();
	void playReloadSound();
	void playPlayerOuch();
};






#endif