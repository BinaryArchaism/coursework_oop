#pragma once

#include "Point.h"

class Wall : public Point
{
protected:
	int damage;
public:
	Wall(int x, int y);
	virtual ~Wall();

	virtual int getDamage();
	
	virtual void draw(int x, int y);

	virtual void hide();
};

class WhiteWall : public Wall
{
public:
	WhiteWall(int x, int y);
	virtual ~WhiteWall();

	virtual void show();
};

class RedWall : public Wall
{
public:
	RedWall(int x, int y);
	virtual ~RedWall();

	virtual void show();
};

class GreenWall : public Wall
{
public:
	GreenWall(int x, int y);
	virtual ~GreenWall();

	virtual void show();
};

class MagicWall : public Wall
{
public:
	MagicWall(int x, int y);
	virtual ~MagicWall();

	virtual void draw(int x, int y);

	virtual void show();
};
