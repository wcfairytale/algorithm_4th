#pragma once

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

static mt19937 g_rng;

inline void init_rng()
{
	srand((unsigned int)time(NULL));
}

// random [range_min, range_max)
template<typename T>
T old_random_number(T range_min, T range_max)
{
	return range_min + (T)((range_max - range_min) * ((double)rand() / (double)(RAND_MAX + 1)));
}

template<typename T>
void old_random_number_list(int n, T range_min, T range_max, vector<T>& list)
{
	list.clear();

	for (int i = 0; i < n; ++i)
	{
		list.push_back(random_number(range_min, range_max));
	}
}

// random [range_min, range_max]
template<typename T>
inline T random_number(T range_min, T range_max)
{
	uniform_real_distribution<T> dist(range_min, range_max);
	return dist(g_rng);
}

template<>
inline int random_number<int>(int range_min, int range_max)
{
	uniform_int_distribution<int> dist(range_min, range_max);
	return dist(g_rng);
}

template<typename T>
inline void random_number_list(int n, T range_min, T range_max, vector<T>& list)
{
	list.clear();

	uniform_real_distribution<T> dist(range_min, range_max);

	for (int i = 0; i < n; ++i)
	{
		list.push_back(dist(g_rng));
	}
}

template<>
inline void random_number_list<int>(int n, int range_min, int range_max, vector<int>& list)
{
	list.clear();

	uniform_int_distribution<int> dist(range_min, range_max);

	for (int i = 0; i < n; ++i)
	{
		list.push_back(dist(g_rng));
	}
}

template<typename T>
void shuffle(vector<T>& arr)
{
	int n = (int)arr.size();

	for (int i = 0; i < n; ++i)
	{
		int i_rand = random_number(i, n);
		T t = arr[i];
		arr[i] = arr[i_rand];
		arr[i_rand] = t;
	}
}