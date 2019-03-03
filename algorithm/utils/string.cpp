#include "string.h"

bool check_circular_shift(const string& a, const string& b)
{
	return (a.length() == b.length()) && (b + b).find(a) != string::npos;
}