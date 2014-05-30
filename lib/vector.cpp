#include "point.cpp"

class Vector {

	Point start, end;

public:
	Vector()
	{
		start = Point(0, 0, 0);
		end = Point(0, 0, 0);
	}

	Vector(const Point &_start, const Point &_end)
	{
		start = _start;
		end = _end;
	}

	Vector(const Vector &v)
	{
		start = v.get_start();
		end = v.get_end();
	}

	// Operators

	bool operator=(const Vector &v)
	{
		start = v.get_start();
		end = v.get_end();
	}

	// Getters

	Point get_start() const
	{
		return start;
	}

	Point get_end() const
	{
		return end;
	}
};
