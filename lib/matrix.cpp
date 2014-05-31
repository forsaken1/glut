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

	const vector<point_type> operator[](int index) const
	{
		return (*m)[index];
	}

	const Matrix operator+(const Matrix &_m) const
	{
		return Matrix();
	}

	const Matrix operator-(const Matrix &_m) const
	{
		return Matrix();
	}

	const Matrix operator*(const point_type) const
	{
		return Matrix();
	}

	const Matrix operator*(const Matrix &_m) const
	{
		return Matrix();
	}

	const Matrix operator!() const
	{
		return inv();
	}

	const point_type operator~() const
	{
		return det();
	}

	bool operator==(const Matrix &_m) const
	{
		return false;
	}

	bool operator!=(const Matrix &_m) const
	{
		return !(*this == _m);
	}

	//Getters

	const point_type get(int i, int j) const
	{
		return (*m)[i][j];
	}

	//Other

	int dimension() const
	{
		return (*m).size();
	}

	const point_type det() const
	{
		return 0;
	}

	const Matrix inv() const
	{
		return Matrix();
	}

};