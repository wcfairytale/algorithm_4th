#include "test_data_gen.h"

int random_int(int range_min, int range_max)
{
	return range_min + (int)(
		(double)(range_max - range_min) * ((double)rand() / (double)(RAND_MAX + 1)));
}

void random_int_list(int n, int range_min, int range_max, vector<int>& list)
{
	list.clear();

	for (int i = 0; i < n; ++i)
	{
		list.push_back(random_int(range_min, range_max));
	}
}

float random_float(float range_min, float range_max)
{
	return range_min + (float)(
		(double)(range_max - range_min) * ((double)rand() / (double)(RAND_MAX + 1)));
}

void random_int_list(int n, float range_min, float range_max, vector<float>& list)
{
	list.clear();

	for (int i = 0; i < n; ++i)
	{
		list.push_back(random_float(range_min, range_max));
	}
}

double random_double(double range_min, double range_max)
{
	return range_min + (range_max - range_min) * ((double)rand() / (double)(RAND_MAX + 1));
}

void random_double_list(int n, double range_min, double range_max, vector<double>& list)
{
	list.clear();

	for (int i = 0; i < n; ++i)
	{
		list.push_back(random_double(range_min, range_max));
	}
}