#pragma once

#include "Drawable.h"


class Object : public Drawable
{
	friend class Hero;
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	int sprite_h;
	int sprite_w;
	int x;
	int y;
public:
	Object();
	Object(int x, int y);
	void show(sf::RenderWindow* window) override;
	virtual void react() = 0;
};