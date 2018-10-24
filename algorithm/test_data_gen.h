#pragma once

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

#define PI		3.1415926
#define PI_2	6.2831853

// random [range_min, range_max)
int random_int(int range_min, int range_max);
void random_int_list(int n, int range_min, int range_max, vector<int>& list);

float random_float(float range_min, float range_max);
void random_float_list(int n, float range_min, float range_max, vector<float>& list);

double random_double(double range_min, double range_max);
void random_double_list(int n, double range_min, double range_max, vector<double>& list);