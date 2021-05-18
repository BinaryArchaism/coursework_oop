class Movable
{
protected:
	virtual void move(int direction) = 0;
public:
	enum directions {
		left,
		right,
		up,
		down
	};
};