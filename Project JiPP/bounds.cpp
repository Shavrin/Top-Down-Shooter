#include "bounds.hpp"


void checkcollisions(player &Player) {
	if (Player.getCOORDS().x < 0) {
		Player.setCOORDS(1, Player.getCOORDSY());

		Player.invertVelocityX();
	};

	if (Player.getCOORDS().x > WIDTH - 6) {
		Player.setCOORDS(WIDTH - 6, Player.getCOORDSY());
		Player.invertVelocityX();
	};

	if (Player.getCOORDS().y < 0) {
		Player.setCOORDS(Player.getCOORDSX(), 1);

		Player.invertVelocityY();
	};

	if (Player.getCOORDS().y > HEIGHT - 6) {
		Player.setCOORDS(Player.getCOORDSX(), HEIGHT - 6);
		Player.invertVelocityY();
	};

}