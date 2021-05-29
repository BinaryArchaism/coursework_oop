#pragma once

#include <SFML/Graphics.hpp>
#include "Location.h"

class Point : public Location
{
protected:
	bool visible;
	sf::RenderWindow* window;
public:
	Point(sf::RenderWindow* window);
	Point(int x, int y, sf::RenderWindow* window);
	void moveTo(int x, int y);
	bool isVisible();
	virtual void show() = 0;
	virtual void hide() = 0;
};

