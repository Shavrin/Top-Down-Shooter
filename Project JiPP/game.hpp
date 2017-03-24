#pragma once
//Stany gry
enum _gameState { Menu,Running, Pause, Gameover };

//klasa reprezentuj¹ca gre
class game {
private:
	bool initialized;
public:

	//ustawia czy gra jest za³adowana
	void setInitialized(bool H) {
		initialized = H;
	}
	
	bool getInitialized() {
		return initialized;
	}

	game() {
		initialized = false;

	}


};