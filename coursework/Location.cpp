#include "Location.h"

Location::Location() {
	x = 0;
	y = 0;
}

Location::Location(int x, int y) {
	this->x = x;
	this->y = y;
}

Location::~Location() {}

int Location::getX() {
	return x;
}

int Location::getY() {
	return y;
}

void Location::setX(int x) {
	this->x = x;
}

void Location::setY(int y) {
	this->y = y;
}