#pragma once
//Stany gry
enum _gameState { Menu,Running, Pause, Gameover };

//klasa reprezentująca gre
class game {
private:
	bool initialized;
public:

	//ustawia czy gra jest załadowana
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