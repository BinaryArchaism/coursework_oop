#pragma once
#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "Object.h"
class View
{
private:
	sf::RenderWindow* window;
	Hero* hero;
	Object* obj;
public:
	View(sf::RenderWindow*, Hero*, Object*);
	void show();
};

