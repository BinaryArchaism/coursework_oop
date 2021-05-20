#include "Wall2.h"

Wall2::Wall2() : Object() {
	texture.loadFromFile("obj.bmp");
	sprite.setTexture(texture);
	sprite_w = sprite.getTextureRect().width;
	sprite_h = sprite.getTextureRect().height;
}

Wall2::Wall2(int x, int y) : Wall2() {
	this->x = x;
	this->y = y;
}

void Wall2::react() {
	x = 0;
	y = 0;
}