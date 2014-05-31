#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

typedef float point_type;

class Point {

	vector<point_type> *v = NULL;

	const Point operation(vector<point_type> r, char oper) const
	{
		vector<point_type> l = *v;

		for(int i = 0; i < v->size(); ++i)
		{
			switch(oper)
			{
				case '+': l[i] += r[i]; break;
				case '-': l[i] -= r[i]; break;
				case '/': l[i] /= r[i]; break;
			}
		}
		return Point(l);
	}

public:
	Point()
	{
		v = new vector<point_type>(3, 0);
	}

	Point(int dimension)
	{
		v = new vector<point_type>(dimension, 0);
	}

	Point(int dimension, const point_type value)
	{
		v = new vector<point_type>(dimension, value);
	}

	Point(vector<point_type> _v)
	{
		v = new vector<point_type>(_v);
	}

	Point(point_type x, point_type y, point_type z)
	{
		v = new vector<point_type>();
		v->push_back(x);
		v->push_back(y);
		v->push_back(z);
	}

	Point(point_type x, point_type y, point_type z, point_type t)
	{
		v = new vector<point_type>();
		v->push_back(x);
		v->push_back(y);
		v->push_back(z);
		v->push_back(t);
	}

	Point(const Point &p)
	{
		v = new vector<point_type>(p.get_vector());
	}

	~Point()
	{
		delete v;
	}

	// Operators

	const Point operator=(const Point &p)
	{
		v = new vector<point_type>(p.get_vector());

		return *this;
	}

	bool operator==(const Point &p) const
	{
		return *v == p.get_vector();
	}

	bool operator!=(const Point &p) const
	{
		return *v != p.get_vector();
	}

	const Point operator*(point_type number) const
	{
		vector<point_type> mult = *v;

		for(int i = 0; i < mult.size(); ++i)
		{
			mult[i] *= number;
		}
		return Point(mult);
	}

	const point_type operator*(const Point &p) const
	{
		point_type result = 0;

		for(int i = 0; i < v->size(); ++i)
		{
			result += (*v)[i] * p[i];
		}
		return result;
	}

	const Point operator/(const Point &p) const
	{
		return operation(p.get_vector(), '/');
	}

	const Point operator+(const Point &p) const
	{
		return operation(p.get_vector(), '+');
	}

	const Point operator-(const Point &p) const
	{
		return operation(p.get_vector(), '-');
	}

	const point_type operator[](int index) const
	{
		if(0 <= index && index < v->size())
			return (*v)[index];
		
		return 0;
	}

	// Getters

	const vector<point_type> get_vector() const
	{
		return *v;
	}

	// Others

	const int dimension() const
	{
		return v->size();
	}

	const string to_string() const
	{
		string result = "";
		char buff[10];

		for(int i = 0; i < v->size(); ++i)
		{
			sprintf(buff, "%f", (*v)[i]);
			result += string(buff) + string("; ");
		}
		return result;
	}
};
