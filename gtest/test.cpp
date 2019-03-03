#include "pch.h"
#include "../algorithm/utils/string.h"
#include "../algorithm/adts/rational.h"

TEST(test_string, test_check_circular_shift) {
	EXPECT_TRUE(check_circular_shift("ACTGACG", "TGACGAC"));

	EXPECT_FALSE(check_circular_shift("ACTGACG", "ACTGAC"));
	EXPECT_FALSE(check_circular_shift("ACTGACG", "ACTGACX"));
}

TEST(test_adt, test_rational) {
	Rational origin_a = Rational(10, 6);

	Rational a = origin_a;
	EXPECT_TRUE(a.ToString() == string("5/3")) << a.ToString();

	Rational b = Rational(5, 6);
	Rational a_plus_b = a.Plus(b);
	EXPECT_TRUE(a_plus_b.ToString() == string("5/2")) << a_plus_b.ToString();

	a = origin_a;
	Rational a_minus_b = a.Minus(b);
	EXPECT_TRUE(a_minus_b.ToString() == string("5/6")) << a_minus_b.ToString();

	a = origin_a;
	Rational a_times_b = a.Times(b);
	EXPECT_TRUE(a_times_b.ToString() == string("25/18")) << a_times_b.ToString();

	a = origin_a;
	Rational a_divided_by_b = a.DevidedBy(b);
	EXPECT_TRUE(a_divided_by_b.ToString() == string("2")) << a_divided_by_b.ToString();

	a = origin_a;
	EXPECT_FALSE(a.Equals(b)) << a.ToString() << " should != " << b.ToString();

	Rational c = origin_a;
	EXPECT_TRUE(a.Equals(c)) << a.ToString() << " should = " << c.ToString();
}