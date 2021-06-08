#include <windows.h>

#include "Walls.h"

extern HDC hdc;

Wall::Wall(int x, int y) : Point(x, y) {
	this->x = x;
	this->y = y;
	visible = false;
	damage = 0;
}

Wall::~Wall() {}

int Wall::getDamage() {
	return damage;
}

void Wall::draw(int x, int y) {
	Rectangle(hdc, x - 20 / 2, y + 100 / 2, x + 20 / 2, y - 50 / 2);
}

void Wall::hide() {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 1, RGB(13, 13, 13));
	SelectObject(hdc, hPen);
	HBRUSH brush;

	brush = CreateSolidBrush(RGB(13, 13, 13));
	SelectObject(hdc, brush);

	draw(x, y);

	DeleteObject(hPen);
	DeleteObject(brush);
	visible = false;
}

WhiteWall::WhiteWall(int x, int y) : Wall(x, y) {
	damage = -2;
	this->x = x;
	this->y = y;
	visible = false;
}

WhiteWall::~WhiteWall() {}

void WhiteWall::show() {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(hdc, hPen);
	HBRUSH brush;

	brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, brush);

	draw(x, y);

	DeleteObject(hPen);
	DeleteObject(brush);
	visible = true;
}

RedWall::RedWall(int x, int y) : Wall(x, y) {
	damage = 2;
	this->x = x;
	this->y = y;
	visible = false;
}

RedWall::~RedWall() {}

void RedWall::show() {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	SelectObject(hdc, hPen);
	HBRUSH brush;

	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, brush);

	draw(x, y);

	DeleteObject(hPen);
	DeleteObject(brush);
	visible = true;
}

GreenWall::GreenWall(int x, int y) : Wall(x, y) {
	damage = 1;
	this->x = x;
	this->y = y;
	visible = false;
}

GreenWall::~GreenWall() {}

void GreenWall::show() {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	SelectObject(hdc, hPen);
	HBRUSH brush;

	brush = CreateSolidBrush(RGB(0, 255, 0));
	SelectObject(hdc, brush);

	draw(x, y);

	DeleteObject(hPen);
	DeleteObject(brush);
	visible = true;
}

MagicWall::MagicWall(int x, int y) : Wall(x, y) {
	damage = 0;
	this->x = x;
	this->y = y;
	visible = false;
}

MagicWall::~MagicWall() {}

void MagicWall::show() {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	SelectObject(hdc, hPen);
	HBRUSH brush;

	brush = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, brush);

	draw(x, y);

	DeleteObject(hPen);
	DeleteObject(brush);
	visible = true;
}

void MagicWall::draw(int x, int y) {
	Rectangle(hdc, x - 20 / 2, y + 20 / 2, x + 20 / 2, y - 20 / 2);
}