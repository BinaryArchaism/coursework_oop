#include "Wall.h"

Wall::Wall() : Object() {
	texture.loadFromFile("obj.bmp");
	sprite.setTexture(texture);
	sprite_w = sprite.getTextureRect().width;
	sprite_h = sprite.getTextureRect().height;
}

Wall::Wall(int x, int y) : Wall() {
	this->x = x;
	this->y = y;
}

void Wall::react() {
	x += rand() % 100 - 50;
	y += rand() % 100 - 50;
}