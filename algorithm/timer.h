#pragma once

#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

class easy_timer
{
public:
	easy_timer()
	{
		start = clock();
	}

	~easy_timer()
	{
		cout << "used " << (clock() - start) / (double)CLOCKS_PER_SEC << " secs" << endl;
	}

private:
	clock_t start;
};