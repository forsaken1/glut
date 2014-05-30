#include "point.cpp"
#include <math.h>

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

	const Vector operator=(const Vector &v)
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

	const Point get_start() const
	{
		return *start;
	}

	const Point get_end() const
	{
		return *end;
	}

	// Others

	const point_type length() const
	{
		point_type result = 0;

		for(int i = 0; i < start->dimension(); ++i)
		{
			result += pow((*start)[i] - (*end)[i], 2);
		}
		return sqrt(result);
	}
};
