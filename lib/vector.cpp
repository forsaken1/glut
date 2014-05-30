#include "point.cpp"

class Vector {

	Point *start = NULL, *end = NULL;

public:
	Vector()
	{
		start = new Point(0, 0, 0);
		end = new Point(0, 0, 0);
	}

	Vector(const Point &_start, const Point &_end)
	{
		start = new Point(_start);
		end = new Point(_end);
	}

	Vector(const Vector &v)
	{
		start = new Point(v.get_start());
		end = new Point(v.get_end());
	}

	~Vector()
	{
		delete start;
		delete end;
	}

	// Operators

	Vector operator=(const Vector &v)
	{
		start = new Point(v.get_start());
		end = new Point(v.get_end());

		return *this;
	}

	bool operator==(const Vector &v) const
	{
		return *start == v.get_start() && *end == v.get_end();
	}

	bool operator!=(const Vector &v) const
	{
		return !(*this == v);
	}

	// Getters

	Point get_start() const
	{
		return *start;
	}

	Point get_end() const
	{
		return *end;
	}

	// Others

	point_type length() const
	{
		return 1;
	}
};
