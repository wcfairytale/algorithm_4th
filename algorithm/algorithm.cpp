#include "algorithm.h"

int fibonacci(int n, int* note)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}

	if (note != NULL && note[n] != 0)
	{
		return note[n];
	}

	//note[n] = fibonacci(n - 1, note) + fibonacci(n - 2, note);

	//return note[n];
	return fibonacci(n - 1, note) + fibonacci(n - 2, note);
}

double binomial(int n, int k, double p, vector<vector<double>>& note)
{
	if ((n == 0) && (k == 0))
	{
		return 1.0;
}

	if ((n < 0) || (k < 0))
	{
		return 0.0;
	}

	if (note[n][k] >= 0.0)
	{
		return note[n][k];
	}

	note[n][k] = (1 - p) * binomial(n - 1, k, p, note) + p * binomial(n - 1, k - 1, p, note);

	return note[n][k];
}

int gcd(int p, int q)
{
#ifdef PRINT_LOG
	cout << p << ' ' << q << endl;
#endif

	if (q == 0)
	{
		return p;
	}

	int r = p % q;

	return gcd(q, r);
}