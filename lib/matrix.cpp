typedef vector< vector<point_type> > matrix_type;

class Matrix {

	matrix_type *m = NULL;

public:
	Matrix()
	{
		m = new matrix_type(3, vector<point_type>(3, 0));
	}

	Matrix(int dimension)
	{
		m = new matrix_type(dimension, vector<point_type>(dimension, 0));
	}

	Matrix(int dimension, const point_type value)
	{
		m = new matrix_type(dimension, vector<point_type>(dimension, value));
	}

	//Operators

	vector<point_type> operator[](int index) const
	{
		return (*m)[index];
	}

};