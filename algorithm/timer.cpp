#include "timer.h"

void easy_timer::start()
{
	start_clock = clock();
	elapsed_clock = 0;
}

void easy_timer::pause()
{
	elapsed_clock += clock() - start_clock;
}

void easy_timer::resume()
{
	start_clock = clock();
}

double easy_timer::timer()
{
	return (double)(elapsed_clock + (clock() - start_clock)) / (double)CLOCKS_PER_SEC;
}