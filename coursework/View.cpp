#include "View.h"

View::View(sf::RenderWindow* window, Hero* hero, Object* obj) {
	this->window = window;
	this->hero = hero;
	this->obj = obj;
}

void View::show() {
	(*obj).show(window);
	(*hero).show(window);
}