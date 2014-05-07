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
	vector<float> v_0(3, 0);
	Point p0(v_0), p_0(0, 0, 0), p1(1, 0, 0);

	cout << "point  tests: ";
	test_true(p0 == p_0);
	test_false(p0 != p_0);
	test_true(p0 != p1);
	test_false(p0 == p1);

	//Vector v();
	//Vector v1(Point({0, 0, 0}), Point({1, 0, 0}));
	//Vector v1(p0, {1, 0, 0});
	//Vector v2({0, 0, 0}, p1);
	//Vector v3({0, 0, 0}, {1, 0, 0});

	cout << endl << "vector tests: ";
	//test_true(v0 == v1);
	cout << endl << "matrix tests: ";
	cout << endl;

	return 0;
}