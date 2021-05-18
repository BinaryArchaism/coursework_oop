#pragma once

#include "Drawable.h"
#include "Movable.h"
#include "Object.h"

class Hero : public Drawable, public Movable
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int x;
	int y;
public:
	Hero(int x, int y);
	void show(sf::RenderWindow* window) override;
	void move(int direction) override;
	int getDistanceToObj(Object&);
};