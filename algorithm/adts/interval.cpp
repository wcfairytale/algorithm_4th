#include "interval.h"
#include <iostream>

using namespace std;

void Interval1D::Print() const
{
	cout << '[' << left << ',' << right << ']';
}

void Interval2D::Print() const
{
	;
}

bool Intersect(const Interval1D& inter_a, const Interval1D& inter_b)
{
	return !(inter_a.right < inter_b.left || inter_b.right < inter_a.left)
		&& !Contain(inter_a, inter_b) && !Contain(inter_b, inter_a);
}

bool Contain(const Interval1D& inter_a, const Interval1D& inter_b)
{
	return inter_a.left <= inter_b.left && inter_b.right <= inter_a.right;
}

bool Intersect(const Interval2D& inter_a, const Interval2D& inter_b)
{
	return !(
		inter_a.width.right < inter_b.width.left
		|| inter_b.width.right < inter_a.width.left
		|| inter_a.height.right < inter_b.height.left
		|| inter_b.height.right < inter_a.height.left)
		&& !Contain(inter_a, inter_b) && !Contain(inter_b, inter_a);
}

bool Contain(const Interval2D& inter_a, const Interval2D& inter_b)
{
	return Contain(inter_a.width, inter_b.width)
		&& Contain(inter_a.height, inter_b.height);
}