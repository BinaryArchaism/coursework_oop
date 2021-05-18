#include <SFML/Graphics.hpp>
#include "Object.h"

Object::Object(int x, int y) : x(x), y(y) {
	texture.loadFromFile("Object_ex.png");
	sprite.setTexture(texture);
}

void Object::show(sf::RenderWindow* window) {
	sprite.setPosition(x, y);
	(*window).draw(sprite);
}
