#pragma once

#include <iostream>
#include <vector>

using namespace std;

class EasyVector
{
public:
	EasyVector() {}
	EasyVector(int n) { data.resize(n, 0.0); }
	EasyVector(const EasyVector& vec) { data = vec.data; }

	size_t size() const { return data.size(); }

	void print()
	{
		cout << '{';

		for (size_t i = 0; i < data.size(); ++i)
		{
			cout << data[i];

			if (i != data.size() - 1)
			{
				cout << ',';
			}
		}

		cout << '}';
	}

	double& operator[] (size_t index)
	{
		if (index >= data.size())
		{
			return data[0];
		}

		return data[index];
	}

	const double& operator[] (size_t index) const
	{
		if (index >= data.size())
		{
			return data[0];
		}

		return data[index];
	}

public:
	vector<double> data;
};

typedef const EasyVector& CEasyVector;

class EasyMatrix
{
public:
	EasyMatrix() : n_row(0), n_col(0) {}
	EasyMatrix(int row, int col)
		: n_row(row), n_col(col)
	{
		data.resize(n_row * n_col, 0.0);
	}

	EasyMatrix(const EasyMatrix& mtx)
	{
		data = mtx.data;
		n_row = mtx.n_row;
		n_col = mtx.n_col;
	}

	double* operator[] (size_t row)
	{
		if ((int)row >= n_row)
		{
			return NULL;
		}

		return data.data() + (int)row * n_col;
	}

	const double* const operator[] (size_t row) const
	{
		if ((int)row >= n_row)
		{
			return NULL;
		}

		return data.data() + (int)row * n_col;
	}

	void print()
	{
		cout << '{';

		for (int i = 0; i < n_row; ++i)
		{
			cout << '{';

			for (int j = 0; j < n_col; ++j)
			{
				cout << (*this)[i][j];

				if (j != n_col - 1)
				{
					cout << ',';
				}
			}

			cout << '}';

			if (i != n_row - 1)
			{
				cout << ',';
			}
		}

		cout << '}';
	}

public:
	vector<double> data;
	int n_row;
	int n_col;
};

typedef const EasyMatrix& CEasyMatrix;

double VectorDot(CEasyVector& vec_a, CEasyVector& vec_b);

EasyMatrix MatrixMultiply(CEasyMatrix mtx_a, CEasyMatrix mtx_b);
EasyMatrix MatrixTranspose(CEasyMatrix mtx);
EasyVector MatrixMultiplyVector(CEasyMatrix mtx, CEasyVector vec);
EasyVector VectorMultiplyMatrix(CEasyVector vec, CEasyMatrix mtx);