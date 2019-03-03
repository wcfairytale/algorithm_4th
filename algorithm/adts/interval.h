#pragma once

class Interval1D
{
public:
	Interval1D() : left(0.0f), right(0.0f) {}
	Interval1D(float l, float r) : left(l), right(r) {}
	~Interval1D() {}

	void Print() const;

	float left;
	float right;
};

class Interval2D
{
public:
	Interval2D() {}
	Interval2D(float w_l, float w_r, float h_l, float h_r)
		: width(w_l, w_r), height(h_l, h_r) {}
	~Interval2D() {}

	void Print() const;

	Interval1D width;
	Interval1D height;
};

bool Intersect(const Interval1D& inter_a, const Interval1D& inter_b);
bool Contain(const Interval1D& inter_a, const Interval1D& inter_b);

bool Intersect(const Interval2D& inter_a, const Interval2D& inter_b);
bool Contain(const Interval2D& inter_a, const Interval2D& inter_b);
