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

	Vector(const Point &_end)
	{
		start = new Point(0, 0, 0);
		end = new Point(_end);
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

	const Vector operator*(point_type number) const
	{
		return Vector(*start * number, *end * number);
	}

	const point_type operator*(const Vector &v) const
	{
		return (*end - *start) * (v.get_end() - v.get_start());
	}

	const Vector operator^(const Vector &v) const
	{
		Point p1(*end - *start), p2(v.get_end() - v.get_start()), p(dimension());

		for(int i = 0; i < dimension(); ++i)
		{
			p[i] = p1[i + 1] * p2[i + 2] - p1[i + 2] * p2[i + 1];
		}
		return Vector(p);
	}

	const Vector operator+(const Vector &v) const
	{
		return Vector(*start + v.get_start(), *end + v.get_end());
	}

	const Vector operator-(const Vector &v) const
	{
		return Vector(*start - v.get_start(), *end - v.get_end());
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

	int dimension() const
	{
		if(start->dimension() == end->dimension())
			return start->dimension();

		return 0;
	}

	const point_type length() const
	{
		point_type result = 0;

		for(int i = 0; i < start->dimension(); ++i)
		{
			result += pow( fabs((*start)[i] - (*end)[i]), 2);
		}
		return (point_type)sqrt(result);
	}

	const Vector normalize() const
	{
		const point_type len = length();

		if(len != 0)
			return Vector( (*end - *start) / Point(dimension(), len) );

		return Vector();
	}
};
