#include <vector>

using namespace std;

typedef float point_type;

class Point {

	vector<point_type> v;

public:
	Point()
	{
		v = vector<point_type>();
	}

	Point(vector<point_type> _v)
	{
		v = _v;
	}

	Point(point_type x, point_type y, point_type z)
	{
		v = vector<point_type>();
		v.push_back(x);
		v.push_back(y);
		v.push_back(z);
	}

	Point(point_type x, point_type y, point_type z, point_type t)
	{
		v = vector<point_type>();
		v.push_back(x);
		v.push_back(y);
		v.push_back(z);
		v.push_back(t);
	}

	Point(const Point &p)
	{
		v = p.getVector();
	}

	// Operators

	Point operator=(const Point &p)
	{
		v = p.getVector();
	}

	bool operator==(const Point &p)
	{
		return v == p.getVector();
	}

	bool operator!=(const Point &p)
	{
		return v != p.getVector();
	}

	// Getters

	vector<point_type> getVector() const
	{
		return v;
	}
};