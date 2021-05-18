#include <SFML/Graphics.hpp>
#include "Object.h"

Object::Object(int x, int y) : x(x), y(y) {
	texture.loadFromFile("bicycle.jpg");
	sprite.setTexture(texture);
}

void Object::show(sf::RenderWindow* window) {
	sprite.setPosition(x, y);
	(*window).draw(sprite);
}
