#include <SFML/Graphics.hpp>
#include "Object.h"

Object::Object() {}

void Object::show(sf::RenderWindow* window) {
	sprite.setPosition(x - sprite_w/2, y - sprite_h/2);
	(*window).draw(sprite);
}
