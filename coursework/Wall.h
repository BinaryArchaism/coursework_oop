#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
class Wall : public Object
{
public:
	Wall();
	Wall(int x, int y);
	void react() override;
};

