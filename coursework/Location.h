#pragma once
class Location
{
protected:
	// ����������
	int x;
	int y;
public:
	Location(int x, int y);
	~Location();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};
