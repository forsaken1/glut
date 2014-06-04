typedef vector< vector<point_type> > matrix_type;

class Matrix {

	matrix_type *m = NULL;

	const Matrix operation(const Matrix &_m, char oper) const
	{
		int dim = dimension();

		if(dim != _m.dimension())
			return Matrix(dim);

		matrix_type result = *m, r = _m.get_matrix();

		for(int i = 0; i < result.size(); ++i)
		{
			for(int j = 0; j < result[i].size(); ++j)
			{
				switch(oper)
				{
					case '+': result[i][j] += r[i][j]; break;
					case '-': result[i][j] -= r[i][j]; break;
					case '*': result[i][j] *= r[i][j]; break;
				}
			}
		}
		return Matrix(result);
	}

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

	Matrix(const matrix_type _m)
	{
		m = new matrix_type(_m);
	}

	Matrix(const Matrix &_m)
	{
		m = new matrix_type(_m.get_matrix());
	}

	Matrix(initializer_list< initializer_list<point_type> > list)
	{
		vector< initializer_list<point_type> > setVec = list;
		vector< vector<point_type> > v;

		for(vector< initializer_list<point_type> >::iterator i = setVec.begin(); i != setVec.end(); ++i)
		{
			v.push_back(vector<point_type>(*i));
		}
		m = new matrix_type(v);
	}

	//Operators

	const Matrix operator=(const Matrix &_m)
	{
		m = new matrix_type(_m.get_matrix());
	}

	const vector<point_type> operator[](int index) const
	{
		return (*m)[index];
	}

	const Matrix operator+(const Matrix &_m) const
	{
		return operation(_m, '+');
	}

	const Matrix operator-(const Matrix &_m) const
	{
		return operation(_m, '-');
	}

	const Matrix operator*(const point_type number) const
	{
		return operation(Matrix(dimension(), number), '*');
	}

	const Matrix operator*(const Matrix &_m) const
	{
		matrix_type l = *m, r = _m.get_matrix();
		
		for(int i = 0; i < m->size(); i++)
		{
			for(int j = 0; j < (*m)[i].size(); j++)
			{
				l[i][j] = 0;

				for(int k = 0; k < m->size(); k++)
					l[i][j] += (*m)[i][k] * r[k][j];
			}
		}
		return Matrix(l);
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
		return *m == _m.get_matrix();
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

	const matrix_type get_matrix() const
	{
		return *m;
	}

	//Other

	int dimension() const
	{
		return m->size();
	}

	const point_type det() const
	{
		point_type det = 1;
		matrix_type mass = *m;

		for(int i = 0; i < mass.size(); ++i)
		{
			for(int j = i + 1; j < mass[i].size(); ++j)
			{
				if(mass[i][i] == 0)
					return 0;

				point_type b = mass[j][i] / mass[i][i];

				for(int k = i; k < mass[i].size(); ++k)
					mass[j][k] = mass[j][k] - mass[i][k] * b;
			}
			det *= mass[i][i];
		}
		return det;
	}

	const Matrix inv() const
	{
		int i, j, k, cnt_str = m->size();
		matrix_type mass = *m, M_obr(cnt_str, vector<point_type>(cnt_str, 0));

		for(i = 0; i < cnt_str; ++i)
			M_obr[i][i] = 1;

		point_type a, b;

		for(i = 0; i < cnt_str; ++i)
		{
			a = mass[i][i];

			for(j = i + 1; j < cnt_str; j++)
			{
				b = mass[j][i];

				for(k = 0; k < cnt_str; ++k)
				{
					mass[j][k] = mass[i][k] * b - mass[j][k] * a;
					M_obr[j][k] = M_obr[i][k] * b - M_obr[j][k] * a;
				}
			}
		}

		point_type sum;

		for(i = 0; i < cnt_str; ++i)
		{
			for(j = cnt_str - 1; j >= 0; --j)
			{
				sum = 0;

				for(k = cnt_str - 1; k > j; --k)
					sum += mass[j][k] * M_obr[k][i];

				if(mass[j][j] == 0)
					return *this;

				M_obr[j][i] = (M_obr[j][i] - sum) / mass[j][j];
			}
		}
		return Matrix(M_obr);
	}

	const string to_string() const
	{
		string result = "";
		char buff[10];

		for(int i = 0; i < m->size(); ++i)
		{
			result += "{ ";
			for(int j = 0; j < (*m)[i].size(); ++j)
			{
				sprintf(buff, "%f", (*m)[i][j]);
				result += string(buff) + (j + 1 == (*m)[i].size() ? string("") : string(", "));
			}
			result += " }, ";
		}
		return result;
	}

};