#include "rational.h"
#include "../utils/algorithm.h"

Rational::Rational(int n, int d)
{
	int t_gcd = gcd(n, d);

	if (t_gcd > 1)
	{
		n /= t_gcd;
		d /= t_gcd;
	}

	numerator = n;
	denominator = d;
};

Rational Rational::Plus(const Rational& r)
{
	int t_n = numerator * r.denominator + r.numerator * denominator;
	int t_d = denominator * r.denominator;

	numerator = t_n;
	denominator = t_d;

	return Rational(t_n, t_d);
}

Rational Rational::Minus(const Rational& r)
{
	int t_n = numerator * r.denominator - r.numerator * denominator;
	int t_d = denominator * r.denominator;

	numerator = t_n;
	denominator = t_d;

	return Rational(t_n, t_d);
}

Rational Rational::Times(const Rational& r)
{
	int t_n = numerator * r.numerator;
	int t_d = denominator * r.denominator;

	numerator = t_n;
	denominator = t_d;

	return Rational(t_n, t_d);
}

Rational Rational::DevidedBy(const Rational& r)
{
	int t_n = numerator * r.denominator;
	int t_d = denominator * r.numerator;

	numerator = t_n;
	denominator = t_d;

	return Rational(t_n, t_d);
}

bool Rational::Equals(const Rational& r) const
{
	return numerator == r.numerator && denominator == r.denominator;
}

string Rational::ToString()
{
	if (denominator == 1)
	{
		return to_string(numerator);
	}
	else
	{
		return to_string(numerator) + "/" + to_string(denominator);
	}
}