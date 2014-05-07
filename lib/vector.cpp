#include "point.cpp"

class Vector {

	Point start, end;

public:
	Vector()
	{
		start = Point(0, 0, 0);
		end = Point(0, 0, 0);
	}

	Vector(Point _start, Point _end)
	{
		start = _start;
		end = _end;
	}
};