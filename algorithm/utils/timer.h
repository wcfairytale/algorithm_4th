#pragma once

#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

class easy_timer
{
public:
	easy_timer() : start_clock(0), elapsed_clock(0) {}
	~easy_timer() {}

	void start();
	void pause();
	void resume();

	// return secs
	double timer();

private:
	clock_t start_clock;
	clock_t elapsed_clock;
};

class auto_timer
{
public:
	auto_timer() : start_clock(clock()) {}
	~auto_timer()
	{
		cout << (double)((clock() - start_clock))
			/ (double)CLOCKS_PER_SEC << "secs" << endl;
	}

private:
	clock_t start_clock;
};