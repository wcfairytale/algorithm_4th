#pragma once

#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n, int* note);

double binomial(int n, int k, double p, vector<vector<double>>& note);

int gcd(int p, int q);

template<typename T>
int brute_force_search(const vector<T>& numbers, T key)
{
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] == key)
		{
			return (int)i;
		}
	}

	return -1;
}

template<typename T>
#ifdef PRINT_LOG
int binary_search(const vector<T>& numbers, T key, int lo, int hi, int depth)
#else
int binary_search(const vector<T>& numbers, T key, int lo, int hi)
#endif
{
#ifdef PRINT_LOG
	for (int i = 0; i < depth; ++i)
	{
		cout << "  ";
	}

	cout << lo << ' ' << hi << endl;
#endif

	if (lo > hi)
	{
		return -1;
	}

	if (numbers[lo] == key)
	{
		return lo;
	}
	else if (numbers[hi] == key)
	{
		return hi;
	}

	int mid = (lo + hi) / 2;

	if (numbers[mid] == key)
	{
		return mid;
	}
	else if (numbers[mid] < key)
	{
#ifdef PRINT_LOG
		return binary_search(numbers, key, mid + 1, hi, depth + 1);
#else
		return binary_search(numbers, key, mid + 1, hi);
#endif
	}
	else
	{
#ifdef PRINT_LOG
		return binary_search(numbers, key, lo, mid - 1, depth + 1);
#else
		return binary_search(numbers, key, lo, mid - 1);
#endif
	}
}