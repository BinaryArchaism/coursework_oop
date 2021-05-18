#include <SFML/Graphics.hpp>
#include "Hero.h"

Hero::Hero(int x, int y) : x(x), y(y) {
	texture.loadFromFile("background.png");
	sprite.setTexture(texture);
}

void Hero::show(sf::RenderWindow* window) {
	sprite.setPosition(x, y);
	(*window).draw(sprite);
}