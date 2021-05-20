#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
class Wall2 : public Object
{
public:
	Wall2();
	Wall2(int x, int y);
	void react() override;
};

