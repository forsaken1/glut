#include <iostream>
#include <stdlib.h>
#include "vector.cpp"

#define EPS 0.0000001

using namespace std;

void test_true(bool expr)
{
	cout << (expr ? "+" : "-");
}

void test_false(bool expr)
{
	cout << (expr ? "-" : "+");
}

void test_equal(point_type l, point_type r)
{
	cout << (fabs(l - r) < EPS ? "+" : "-");
}

void test_not_equal(point_type l, point_type r)
{
	cout << (fabs(l - r) > EPS ? "+" : "-");
}

int main()
{
	vector<point_type> v_0(3, 0);
	Point p0(v_0), p_0(0, 0, 0), p1(1, 0, 0);

	cout << "point  tests: ";
	test_true(p0 == p_0);
	test_false(p0 != p_0);
	test_true(p0 != p1);
	test_false(p0 == p1);
	test_true(p0[0] == 0);
	test_true(p1[0] == 1);
	test_true(p_0[-1] == 0);

	Vector v0, v1(p0, p_0), v2(Point(0, 0, 0), Point(1, 0, 0));
	Vector v3(p0, Point(1, 1, 1));

	cout << endl << "vector tests: ";
	test_true(v0 == v1);
	test_true(v0 != v2);
	test_false(v0 == v2);
	test_false(v0 != v1);
	test_equal(v2.length(), 1);
	test_equal(v3.length(), 1.7320508075688772);
	test_not_equal(v3.length(), 1.5);
	test_not_equal(v3.length(), 2);

	cout << endl << "matrix tests: ";
	cout << endl;

	return 0;
}
