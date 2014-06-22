#include <iostream>
#include <stdlib.h>
#include "vector.cpp"
#include "matrix.cpp"

#define EPS 0.000001

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

void test_equal_matrix(const Matrix &_l, const Matrix &_r)
{
	matrix_type l = _l.get_matrix(), r = _r.get_matrix();

	for(int i = 0; i < l.size(); ++i)
	{
		for(int j = 0; j < l[i].size(); ++j)
		{
			if(fabs(l[i][j] - r[i][j]) > EPS)
			{
				cout << "-";
				return;
			}
		}
	}
	cout << "+";
}

void end_test_block()
{
	cout << " ";
}

int main()
{
	vector<point_type> v_0(3, 0);
	Point p0(v_0), p_0(0, 0, 0), p1(1, 0, 0);

	//Point tests
	cout << "point  tests: ";

	//equal
	test_true(p0 == p_0);
	test_false(p0 != p_0);
	test_true(p0 != p1);
	test_false(p0 == p1);
	end_test_block();

	//operator[]
	test_true(p0[0] == 0);
	test_true(p1[0] == 1);
	test_true(p_0[-1] == 0);
	end_test_block();

	//multiply
	test_true( Point(1, 2, 3) * 5 == Point(5, 10, 15) );
	test_false( Point(1, 2, 3) * 5 == Point(5, 10, 14) );
	test_true( Point(1, 2, -5) * Point(4, 8, 1) == 15 );
	end_test_block();
	
	//divide
	test_true( Point(9, 15, 45) / Point(3, 3, 3) == Point(3, 5, 15) );
	end_test_block();

	//addition
	test_true( Point(1, 2, 3) + Point(3, 2, 1) == Point(4, 4, 4));
	end_test_block();

	//substraction
	test_true( Point(1, 3, 5) - Point(1, 3, 5) == p0 );
	test_false( Point(0, 0, 0) - Point(1, 1, 1) == p0 );
	end_test_block();


	/* ------ */
	Vector v0, v1(p0, p_0), v2(Point(1, 0, 0));
	Vector v3(p0, Point(1, 1, 1)), v4(p0, Point(4, 5, 3));
	Vector v5(Point(1, -1, 3), Point(0, 1, -2)), v6(Point(1, -1, 3), Point(4, -4, 0));

	// Vector tests
	cout << endl << "vector tests: ";

	//equal
	test_true(v0 == v1);
	test_true(v0 != v2);
	test_false(v0 == v2);
	test_false(v0 != v1);
	end_test_block();

	//length
	test_equal(v2.length(), 1);
	test_equal(v3.length(), 1.7320508075688772);
	test_not_equal(v3.length(), 1.5);
	test_not_equal(v3.length(), 2);
	end_test_block();

	//multiply
	test_true( (v3 * 3) == Vector(Point(3, 3, 3)) );
	test_false( (v3 * 3) == Vector(Point(3, 3, 1)) );
	end_test_block();

	//addition
	test_true( v0 + v0 == v0 );
	test_true( v0 + v1 == v0 );
	test_true( v0 + v3 == v3 );
	test_true( v0 + v3 == Vector(Point(1, 1, 1)) );
	test_true( v3 + v4 == Vector(Point(5, 6, 4)) );
	test_true( Vector(Point(1, 1, 1), Point(2, 2, 2)) + Vector(Point(3, 3, 3), Point(4, 4, 4)) 
		== Vector(Point(4, 4, 4), Point(6, 6, 6)) );
	end_test_block();

	//substruction
	test_true( v2 - Vector(Point(1, 0, 0)) == v0 );
	test_false( v1 - Vector(Point(1, 0, 0)) == v0 );
	end_test_block();

	//scalar multiply
	test_true( v5 * v6 == 6 );
	end_test_block();

	//normalize
	test_not_equal(v5.length(), 1);
	test_not_equal(v6.length(), 1);
	test_equal(v5.normalize().length(), 1);
	test_equal(v6.normalize().length(), 1);
	end_test_block();

	//vector multiply
	test_true( (v5 ^ v6) == Vector(Point(-21, -18, -3)) );
	end_test_block();


	/* ------ */
	Matrix m, m0, m1(4), m2(4, 1);
	Matrix m3(4, 5), m4(4, 125), m5(4, 15);
	Matrix m6 {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Matrix m7 {{1, 2, 1}, {4, 5, 3}, {3, 8, 2}};

	//Matrix tests
	cout << endl << "matrix tests: ";

	//init
	test_equal(m0[2][2], 0);
	test_equal(m1[3][3], 0);
	test_equal(m2[3][3], 1);
	test_equal(m6[0][2], 3);
	test_equal(m6[1][1], 5);
	test_equal(m6[2][0], 7);
	test_true(m0.dimension() == 3);
	test_true(m1.dimension() == 4);
	test_true(m6.dimension() == 3);
	test_equal(m2.get(1, 1), 1);
	end_test_block();

	//equal
	test_false(m0 == m1);
	m0 = m1;
	test_true(m0.dimension() == 4);
	test_true(m0 == m1);
	end_test_block();

	//addition
	test_true(m2 + m0 == m2);
	test_true(m3 + m3 + m3 == m5);
	end_test_block();

	//subscription
	test_true(m0 - m0 == m0);
	test_true(m5 - m3 - m3 == m3);
	end_test_block();

	//multiply
	test_true(m0 * 100 == m0);
	test_true(m3 * 25 == m4);
	test_true(m2 * m0 == m0);
	test_true(m6 * m7 == Matrix{{18, 36, 13}, {42, 81, 31}, {66, 126, 49}});
	test_true(m7 * m6 == Matrix{{16, 20, 24}, {45, 57, 69}, {49, 62, 75}});
	end_test_block();

	//determinant
	test_equal(~m0, 0);
	test_equal(~m2, 0);
	test_equal(~m6, 0);
	test_equal(~m7, 5);
	end_test_block();

	//invariant
	test_true(!m2 == m2);
	test_true(m6 == !!m6);
	test_true(!m6 == m6);
	test_equal_matrix(m7, !!m7);
	test_equal_matrix(m7 * !m7, Matrix{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
	test_equal_matrix(!m7, Matrix{{-2.8, 0.8, 0.2}, {0.2, -0.2, 0.2}, {3.4, -0.4, -0.6}});
	test_true(!Matrix{{1, 2}, {3, 4}} == Matrix{{-2, 1}, {1.5, -0.5}});
	end_test_block();

	cout << endl;

	return 0;
}
