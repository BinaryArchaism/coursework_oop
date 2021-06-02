#include <SFML/Graphics.hpp>
#include "Point.h"

Point::Point() : Location() {
	visible = true;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
	visible = true;
}

bool Point::isVisible() {
	return visible;
}

void Point::moveTo(int x, int y, sf::RenderWindow* window) {
	hide(window);
	setX(x);
	setY(y);
	show(window);
}

