#include "redTank.h"

redTank::redTank() : aTank() {}

redTank::redTank(int x, int y) : aTank(x, y) {
}

void redTank::show() {
	tankTexture.loadFromFile("assets/redTank.png");
	tankSprite.setTexture(tankTexture);
	(*window).draw(tankSprite);
}