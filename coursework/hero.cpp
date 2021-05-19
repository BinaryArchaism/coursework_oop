#include <SFML/Graphics.hpp>
#include "Hero.h"

#include <iostream>

Hero::Hero() : x(0), y(0) {
	texture.loadFromFile("hero_ex.png");
	sprite.setTexture(texture);
}

Hero::Hero(int x, int y) : Hero() {
	this->x = x;
	this->y = y;
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

int Hero::getDistanceToObj(Object &obj) {
	int x_dist = abs(obj.x -this->x);
	int y_dist = abs(obj.y -this->y);
	int result = sqrt((x_dist*x_dist) + (y_dist*y_dist));
	return result;
}

void Hero::printer() {
	std::cout << "it HERO-parent\n";
}