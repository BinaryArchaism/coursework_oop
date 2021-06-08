#pragma once

#include <windows.h>

#include "Point.h"
#include "Walls.h"

class iTank {
	virtual void gun(int x, int y) = 0; // ��������� �����
	virtual void tower(int x, int y) = 0; // ��������� �����
	virtual void caterpillars(int x, int y) = 0; // ��������� �������
};

class Tank : public Point, public iTank
{
protected:
	int health;
	int speed;
public:
	Tank(int x, int y);
	virtual ~Tank();

	int getSpeed();
	bool collision(Wall* wall); // �������� ���������������

	virtual void hide();

	void printHealth();
	int getHealth();
	void takeDamage(int damage); // ������� ���� (��������� �������� �� ����������� ��������)
	virtual void gun(int x, int y);
	virtual void tower(int x, int y);
	virtual void caterpillars(int x, int y);
};

class RedTank : public Tank
{
public:
	RedTank(int x, int y);
	virtual ~RedTank();

	virtual void show();
};

class RedTankDamaged : public RedTank
{
public:
	RedTankDamaged(int x, int y);
	virtual ~RedTankDamaged();

	virtual void show();
	virtual void tower(int x, int y);
};

class BlueTank : public Tank
{
public:
	BlueTank(int x, int y);
	virtual ~BlueTank();

	virtual void show();
};