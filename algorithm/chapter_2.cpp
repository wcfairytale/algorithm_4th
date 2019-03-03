#include "chapter_2.h"
#include "adts/point.h"
#include "adts/interval.h"
#include "adts/rational.h"
#include "utils/utils.h"

void Exercise_1_2_1()
{
	int n;
	cin >> n;

	// gen n points
	vector<Point2D> points;

	for (int i = 0; i < n; ++i)
	{
		Point2D p;
		float theta = random_number(0.0f, (float)PI_2);
		float r = sqrt(random_number(0.0f, 1.0f));
		p.x = sin(theta) * r;
		p.y = cos(theta) * r;

		points.push_back(p);
	}

	// find the cloest pair
	double min_dist = 2.0f;
	int i1 = 0;
	int i2 = 0;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			float dist = distance_2d(
				points[i].x, points[i].y,
				points[j].x, points[j].y);

			if (dist < min_dist)
			{
				min_dist = dist;
				i1 = i;
				i2 = j;
			}
		}
	}

	cout << min_dist << endl;

	// paint
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT, SHOWCONSOLE);

	// draw points
	const int center_x = SCREEN_WIDTH / 2;
	const int center_y = SCREEN_HEIGHT / 2;
	const int point_size = 2;
	const int radius = center_y - point_size;

	for (int i = 0; i < n; ++i)
	{
		circle(
			(int)(points[i].x * radius) + center_x,
			(int)(points[i].y * radius) + center_y,
			point_size);
	}

	// draw line between closest pair
	line(
		(int)(points[i1].x * radius) + center_x,
		(int)(points[i1].y * radius) + center_y,
		(int)(points[i2].x * radius) + center_x,
		(int)(points[i2].y * radius) + center_y);

	_getch();
	closegraph();
}

void Exercise_1_2_2()
{
	/*
	5
	100 300
	200 400
	0 80
	50 500
	550 580
	*/
	int n;
	cin >> n;

	// input n pair of double
	vector<Interval1D> inters;

	for (int i = 0; i < n; ++i)
	{
		Interval1D inter;
		cin >> inter.left >> inter.right;

		inters.push_back(inter);
	}

	// prints all pairs that intersact
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			const Interval1D& inter_a = inters[i];
			const Interval1D& inter_b = inters[j];

			if (Intersect(inter_a, inter_b))
			{
				inter_a.Print();
				cout << " intersect with ";
				inter_b.Print();
				cout << endl;
			}
		}
	}

	// paint
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT, SHOWCONSOLE);

	int top = 100;
	const int left = 100;
	const int height = 30;
	const int gap = 5;

	string temp_str;

	for (int i = 0; i < n; ++i)
	{
		int t_left = left + (int)(inters[i].left + 0.5);
		int t_right = left + (int)(inters[i].right + 0.5);
		fillrectangle(t_left, top, t_right, top + height);

		int text_top = top + height / 2 - textheight('0') / 2;

		temp_str = _Floating_to_string("%.2lf", inters[i].left);
		t_left -= textwidth(temp_str.c_str()) + 10;
		outtextxy(t_left, text_top, temp_str.c_str());

		temp_str = _Floating_to_string("%.2lf", inters[i].right);
		outtextxy(t_right + gap + 1, text_top, temp_str.c_str());

		top += height + 10;
	}

	_getch();
	closegraph();
}

void Exercise_1_2_3()
{
	// 5 0 600

	int n;
	float min, max;
	cin >> n >> min >> max;

	// gen n interval2d
	vector<Interval2D> inters;

	for (int i = 0; i < n; ++i)
	{
		float w_l = random_number(min, max);
		float w_r = random_number(min, max);

		if (w_l > w_r)
		{
			swap(w_l, w_r);
		}

		float h_l = random_number(min, max);
		float h_r = random_number(min, max);

		if (h_l > h_r)
		{
			swap(h_l, h_r);
		}

		Interval2D inter(w_l, w_r, h_l, h_r);
		inters.push_back(inter);
	}

	// count intersect and being contained num
	int n_intersect = 0;
	int n_be_contained = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			const Interval2D& inter_a = inters[i];
			const Interval2D& inter_b = inters[j];

			if (Intersect(inter_a, inter_b))
			{
				++n_intersect;
			}

			if (Contain(inter_a, inter_b))
			{
				++n_be_contained;
			}
		}
	}

	cout << "number of intersect = " << n_intersect << '\n'
		<< "number of be contained = " << n_be_contained << endl;

	// paint
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT, SHOWCONSOLE);

	for (int i = 0; i < n; ++i)
	{
		const Interval2D& inter = inters[i];

		rectangle(
			(int)inter.width.left, (int)inter.height.left,
			(int)inter.width.right, (int)inter.height.right);
	}

	_getch();
	closegraph();
}

void Exercise_1_2_6()
{
	// case1: ACTGACG TGACGAC
	// case2: ACTGACG ACTGAC
	// case3: ACTGACG ACTGACX
	string a, b;
	cin >> a >> b;

	cout << a << " and " << b << " are";

	if (!check_circular_shift(a, b))
	{
		cout << "n\'t";
	}
	
	cout << " shifts of one another" << endl;
}

static string mystery(string s)
{
	size_t n = s.length();

	if (n <= 1)
	{
		return s;
	}

	string a = s.substr(0, n / 2);
	string b = s.substr(n / 2);

	return mystery(b) + mystery(a);
}

void Exercise_1_2_7()
{
	// case1: ABCDEFGH
	// case1: ABCDEFG
	string a;
	cin >> a;

	cout << "mystery(" << a << ") = " << mystery(a) << endl;
}

void Exercise_1_2_16()
{
	Rational origin_a = Rational(10, 6);

	Rational a = origin_a;
	cout << "a = " << a.ToString() << endl;

	Rational b = Rational(5, 6);
	cout << "b = " << b.ToString() << endl;

	Rational a_plus_b = a.Plus(b);
	cout << "a.Plus(b) = " << a_plus_b.ToString() << endl;

	a = origin_a;
	Rational a_minus_b = a.Minus(b);
	cout << "a.Minus(b) = " << a_minus_b.ToString() << endl;

	a = origin_a;
	Rational a_times_b = a.Times(b);
	cout << "a.Times(b) = " << a_times_b.ToString() << endl;

	a = origin_a;
	Rational a_divided_by_b = a.DevidedBy(b);
	cout << "a.DevidedBy(b) = " << a_divided_by_b.ToString() << endl;

	a = origin_a;
	bool result = a.Equals(b);
	cout << "a.Equals(b) = " << to_string(result) << endl;

	Rational c = origin_a;
	cout << "c = " << c.ToString() << endl;
	result = a.Equals(c);
	cout << "a.Equals(c) = " << to_string(result) << endl;
}