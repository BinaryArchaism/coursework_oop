#pragma once

#include "Location.h"

class Point : public Location
{
protected:
	bool visible;
	int colorR;
	int colorG;
	int colorB;
public:
	Point(int x, int y);
	virtual ~Point();
	bool isVisible();
	void moveTo(int x, int y);

	void virtual show() = 0;	//показать фигуру 
	void virtual hide() = 0;    //спрятать фигуру 
};
