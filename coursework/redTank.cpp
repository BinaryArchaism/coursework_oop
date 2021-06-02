#include "redTank.h"

redTank::redTank() : aTank() {}

redTank::redTank(int x, int y) : aTank(x, y) {
	tankTexture.loadFromFile("assets/redTank.png");
	tankSprite.setTexture(tankTexture);
}

void redTank::show(sf::RenderWindow* window) {
	tankSprite.setPosition(x, y);
	(*window).draw(tankSprite);
}

void redTank::hide(sf::RenderWindow* window) {

}