#include <iostream>
#include "point.cpp"

using namespace std;

void test(bool expr)
{
	cout << (expr ? "+" : "-");
}

int main()
{
	vector<float> v_0 {0, 0, 0};
	Point p0(v_0), p_0(v_0);

	cout << "point  tests: ";
	test(p0 == p_0);
	cout << endl << "vector tests: ";
	cout << endl << "matrix tests: ";
	cout << endl;

	return 0;
}