#include "math.h"

double VectorDot(CEasyVector vec_a, CEasyVector vec_b)
{
	if (vec_a.size() != vec_b.size())
	{
		return 0.0f;
	}

	double result = 0.0f;

	for (size_t i = 0; i < vec_a.size(); ++i)
	{
		result += vec_a[i] * vec_b[i];
	}

	return result;
}

EasyMatrix MatrixMultiply(CEasyMatrix mtx_a, CEasyMatrix mtx_b)
{
	if (mtx_a.n_col != mtx_b.n_row)
	{
		return EasyMatrix();
	}

	EasyMatrix out_mtx(mtx_a.n_row, mtx_b.n_col);

	double t = 0.0;

	for (int i = 0; i < mtx_a.n_row; ++i)
	{
		for (int j = 0; j < mtx_b.n_col; ++j)
		{
			t = 0.0;

			for (int k = 0; k < mtx_a.n_col; ++k)
			{
				t += mtx_a[i][k] * mtx_b[k][j];
			}

			out_mtx[i][j] = t;
		}
	}

	return out_mtx;
}

EasyMatrix MatrixTranspose(CEasyMatrix mtx)
{
	EasyMatrix out_mtx(mtx.n_col, mtx.n_row);

	for (int i = 0; i < mtx.n_row; ++i)
	{
		for (int j = 0; j < mtx.n_col; ++j)
		{
			out_mtx[j][i] = mtx[i][j];
		}
	}

	return out_mtx;
}

EasyVector MatrixMultiplyVector(CEasyMatrix mtx, CEasyVector vec)
{
	if (mtx.n_col != (int)vec.size())
	{
		return EasyVector();
	}

	EasyVector out_vec(mtx.n_row);

	for (int i = 0; i < mtx.n_row; ++i)
	{
		for (int j = 0; j < mtx.n_col; ++j)
		{
			out_vec[i] += mtx[i][j] * vec[j];
		}
	}

	return out_vec;
}

EasyVector VectorMultiplyMatrix(CEasyVector vec, CEasyMatrix mtx)
{
	if ((int)vec.size() != mtx.n_row)
	{
		return EasyVector();
	}

	EasyVector out_vec(mtx.n_col);

	for (int j = 0; j < mtx.n_col; ++j)
	{
		for (int i = 0; i < mtx.n_row; ++i)
		{
			out_vec[j] += vec[i] * mtx[i][j];
		}
	}

	return out_vec;
}