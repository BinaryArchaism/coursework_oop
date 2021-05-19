#pragma once

#include "Drawable.h"


class Object : public Drawable
{
	friend class Hero;
	//	friend int Hero::getDistanceToObj(Object &obj);
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int x;
	int y;
public:
	Object();
	Object(int x, int y);
	void show(sf::RenderWindow* window) override;
};