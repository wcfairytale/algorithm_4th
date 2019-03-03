#pragma once
#include <iostream>
#include <string>

using namespace std;

class Rational
{
public:
	Rational() : numerator(0), denominator(0) {}
	Rational(int n, int d);
	~Rational() {};

	Rational Plus(const Rational& r);
	Rational Minus(const Rational& r);
	Rational Times(const Rational& r);
	Rational DevidedBy(const Rational& r);
	bool Equals(const Rational& r) const;
	string ToString();

	int numerator;
	int denominator;
};