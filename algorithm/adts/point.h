#pragma once

class Point2D
{
public:
	Point2D() : x(0.0f), y(0.0f) {};
	Point2D(float _x, float _y) : x(_x), y(_y) {};

	~Point2D() {};

	float x;
	float y;
};