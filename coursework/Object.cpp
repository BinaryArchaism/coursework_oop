#include <SFML/Graphics.hpp>
#include "Object.h"

Object::Object() : x(0), y(0) {
	texture.loadFromFile("Object_ex.png");
	sprite.setTexture(texture);
}

Object::Object(int x, int y) : Object() {
	this->x = x;
	this->y = y;
}

void Object::show(sf::RenderWindow* window) {
	sprite.setPosition(x, y);
	(*window).draw(sprite);
}
