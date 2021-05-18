#pragma once
class Movable
{
public:
	virtual void move(int direction) = 0;
	enum directions {
		left,
		right,
		up,
		down
	};
};