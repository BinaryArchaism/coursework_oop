#pragma once
class Location
{
protected:
	int x, y;
public:
	Location();
	Location(int x, int y);
	~Location();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};

