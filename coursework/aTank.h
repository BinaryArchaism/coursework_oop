#pragma once

#include "Point.h"

class aTank : public Point
{
protected:
	int x, y;
	sf::Texture tankTexture;
	sf::Texture weaponTexture;
	sf::Sprite tankSprite;
	sf::Sprite weaponSprite;
	int sprite_h;
	int sprite_w;
public:
	aTank();
	aTank(int x, int y);
	virtual void show();
	virtual void hide();
};

