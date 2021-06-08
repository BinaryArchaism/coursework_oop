#include "Point.h"

Point::Point(int x, int y) : Location(x, y) {
	visible = false;
	this->x = x;
	this->y = y;
	colorR = 255;
	colorG = 255;
	colorB = 255;	
}

Point::~Point(void) {}

bool Point::isVisible(void) {
	return visible;
}

void Point::moveTo(int x, int y) {
	hide();		//сделать точку невидимой
	this->x = x;
	this->y = y;
	if (this->x > 1500) this->x = 1500;
	if (this->x < 100) this->x = 100;
	if (this->y < 100) this->y = 100;
	if (this->y > 900) this->y = 900;
	show();		//показать точку на новом месте
};