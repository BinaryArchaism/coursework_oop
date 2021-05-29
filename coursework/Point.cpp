#include <SFML/Graphics.hpp>
#include "Point.h"

Point::Point(sf::RenderWindow*) : Location() {
	visible = true;
	this->window = window;
}

Point::Point(int x, int y, sf::RenderWindow* window) {
	this->x = x;
	this->y = y;
	visible = true;
	this->window = window;
}

bool Point::isVisible() {
	return visible;
}

void Point::moveTo(int x, int y) {
	hide();
	setX(x);
	setY(y);
	show();
}

