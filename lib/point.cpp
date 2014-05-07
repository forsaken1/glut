#include <vector>

using namespace std;

typedef float point_type;

class Point {

	vector<point_type> v;

public:
	Point(vector<point_type> _v)
	{
		v = _v;
	}

	Point(point_type* _start, point_type* _end)
	{
		
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

	bool operator==(Point &p)
	{
		return v == p.getVector();
	}

	// Getters

	vector<point_type> getVector() const
	{
		return v;
	}
};