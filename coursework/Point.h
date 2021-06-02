#pragma once

#include <SFML/Graphics.hpp>
#include "Location.h"

class Point : public Location
{
protected:
	bool visible;
public:
	Point();
	Point(int x, int y);
	void moveTo(int x, int y, sf::RenderWindow*);
	bool isVisible();
	virtual void show(sf::RenderWindow*) = 0;
	virtual void hide(sf::RenderWindow*) = 0;
};

