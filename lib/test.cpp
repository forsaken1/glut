#include <iostream>
#include "vector.cpp"

using namespace std;

void test_true(bool expr)
{
	cout << (expr ? "+" : "-");
}

void test_false(bool expr)
{
	cout << (expr ? "-" : "+");
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

	Vector v0, v1(p0, p_0), v2(Point(0, 0, 0), Point(1, 0, 0));

	cout << endl << "vector tests: ";
	test_true(v0 == v1);
	test_true(v0 != v2);
	cout << endl << "matrix tests: ";
	cout << endl;

	return 0;
}
