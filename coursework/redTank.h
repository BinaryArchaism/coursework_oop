#pragma once

#include "aTank.h"

class redTank : public aTank
{
private:
	sf::Texture tankTexture;
	sf::Texture weaponTexture;
	sf::Sprite tankSprite;
	sf::Sprite weaponSprite;
public:
	redTank();
	redTank(int x, int y);
	virtual void show(sf::RenderWindow*);
	virtual void hide(sf::RenderWindow*);
};

