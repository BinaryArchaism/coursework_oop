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

void Hero::move(int direction) {
	switch (direction)
	{
	case directions::left:
		x -= 2;
		break;
	case directions::right:
		x += 2;
		break;
	case directions::up:
		y -= 2;
		break;
	case directions::down:
		y += 2;
		break;
	default:
		break;
	}
}