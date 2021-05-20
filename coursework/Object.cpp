#include <SFML/Graphics.hpp>
#include "Object.h"

Object::Object() : x(0), y(0) {
	texture.loadFromFile("obj.bmp");
	sprite.setTexture(texture);
	sprite_w = sprite.getTextureRect().width;
	sprite_h = sprite.getTextureRect().height;
}

Object::Object(int x, int y) : Object() {
	this->x = x;
	this->y = y;
}

void Object::show(sf::RenderWindow* window) {
	sprite.setPosition(x - sprite_w/2, y - sprite_h/2);
	(*window).draw(sprite);
}
