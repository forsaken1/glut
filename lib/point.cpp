#include <vector>
#include <string>
#include <stdio.h>

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
		v = p.get_vector();
	}

	// Operators

	Point operator=(const Point &p)
	{
		v = p.get_vector();
	}

	bool operator==(const Point &p)
	{
		return v == p.get_vector();
	}

	bool operator!=(const Point &p)
	{
		return v != p.get_vector();
	}

	// Getters

	vector<point_type> get_vector() const
	{
		return v;
	}

	// Others

	string to_string()
	{
		string result = "";
		char buff[10];

		for(int i = 0; i < v.size(); ++i)
		{
			sprintf(buff, "%f", v[i]);
			result += string(buff) + string("; ");
		}
		return result;
	}
};