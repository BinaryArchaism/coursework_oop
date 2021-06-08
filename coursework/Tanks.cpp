#include <windows.h>

#include "Tanks.h"
#include <iostream>

extern HDC hdc;

Tank::Tank(int x, int y) : Point(x, y) {
	this->x = x;
	this->y = y;
	visible = false;
}

Tank::~Tank() {}

int Tank::getSpeed() {
	return speed;
}

bool Tank::collision(Wall* wall) {
	if (abs(this->x - (*wall).getX()) < 50 && abs(this->y - (*wall).getY()) < 70 && wall->isVisible())
		return true;
	else
		return false;
} 

int Tank::getHealth() {
	return health;
}

void Tank::printHealth() {
	std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"; // —тираем прошлую строку со здоровьем
	if (health > 9) std::cout << "\b";
	std::cout << "Tank's health: " << health;
}

void Tank::takeDamage(int damage) {
	health -= damage;
}

void Tank::hide() {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 1, RGB(13, 13, 13));
	SelectObject(hdc, hPen);
	HBRUSH brush;

	brush = CreateSolidBrush(RGB(13, 13, 13));
	SelectObject(hdc, brush);

	gun(x, y);
	tower(x, y);
	caterpillars(x, y);

	DeleteObject(hPen);
	DeleteObject(brush);
	visible = false;
}

void Tank::gun(int x, int y) {
	Rectangle(hdc, x + 40 - 40 / 2, y + 20 / 2, x + 40 + 40 / 2, y - 20 / 2);
}

void Tank::tower(int x, int y) {
	Rectangle(hdc, x - 50 / 2, y + 50 / 2, x + 50 / 2, y - 50 / 2);
}

void Tank::caterpillars(int x, int y) {
	Ellipse(hdc, x - 100 / 2, y + 40 + 30 / 2, x + 100 / 2, y + 40 - 30 / 2);
}

RedTank::RedTank(int x, int y) : Tank(x, y) {
	health = 10;
	speed = 3;
	this->x = x;
	this->y = y;
	visible = false;
}

RedTank::~RedTank() {}

void RedTank::show() {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	SelectObject(hdc, hPen);
	HBRUSH brush;

	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, brush);

	gun(x, y);
	tower(x, y);
	caterpillars(x, y);

	DeleteObject(hPen);
	DeleteObject(brush);
	visible = true;
}

RedTankDamaged::RedTankDamaged(int x, int y) : RedTank(x, y) {
	speed = -2; // ћен€ем направление движени€ на противоположное
	this->x = x;
	this->y = y;
	visible = false;
}

RedTankDamaged::~RedTankDamaged() {}

void RedTankDamaged::tower(int x, int y) {
	Rectangle(hdc, x - 50 / 2, y + 50 / 2, x + 50 / 2, y - 25 / 2);
}

void RedTankDamaged::show() {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	SelectObject(hdc, hPen);
	HBRUSH brush;

	brush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, brush);

	gun(x, y);
	tower(x, y);
	caterpillars(x, y);

	DeleteObject(hPen);
	DeleteObject(brush);
	visible = true;
}

BlueTank::BlueTank(int x, int y) : Tank(x, y) {
	health = 6;
	speed = 2;
	this->x = x;
	this->y = y;
	visible = false;
}

BlueTank::~BlueTank() {}

void BlueTank::show() {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	SelectObject(hdc, hPen);
	HBRUSH brush;

	brush = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, brush);

	gun(x, y);
	tower(x, y);
	caterpillars(x, y);

	DeleteObject(hPen);
	DeleteObject(brush);
	visible = true;
}
