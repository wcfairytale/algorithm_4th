#include "chapter_1.h"

void init_funcs_1_1(FuncMap& funcs)
{
	funcs.insert(make_pair(FUNC_1_1_1, new Exercise_1_1_1));
	funcs.insert(make_pair(FUNC_1_1_3, new Exercise_1_1_3));
	funcs.insert(make_pair(FUNC_1_1_6, new Exercise_1_1_6));
	funcs.insert(make_pair(FUNC_1_1_7, new Exercise_1_1_7));
	funcs.insert(make_pair(FUNC_1_1_8, new Exercise_1_1_8));
	funcs.insert(make_pair(FUNC_1_1_16, new Exercise_1_1_16));
}

void init_funcs_1(FuncMap& funcs)
{
	init_funcs_1_1(funcs);
}

void Exercise_1_1_1::Proc()
{
	cout << "(0 + 15) / 2 = " << (0 + 15) / 2 << endl;
	cout << "2.0e-6 * 100000000.1 = " << 2.0e-6 * 100000000.1 << endl;
	cout << "true && false || true && true = " << (true && false || true && true) << endl;
}

void Exercise_1_1_3::Proc()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (a == b && b == c)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}
}

void Exercise_1_1_6::Proc()
{
	int f = 0;
	int g = 1;

	for (int i = 0; i <= 15; i++)
	{
		cout << f << endl;

		f = f + g;
		g = f - g;
	}
}

void Exercise_1_1_7::Proc()
{
	double t = 9.0;

	while (abs(t - 9.0 / t) > 0.001)
	{
		t = (9.0 / t + t) / 2.0;
	}

	cout << t << endl;

	int sum = 0;

	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < i; j++)
		{
			sum++;
		}
	}

	cout << sum << endl;

	sum = 0;

	for (int i = 1; i < 1000; i *= 2)
	{
		for (int j = 0; j < 1000; j++)
		{
			sum++;
		}
	}

	cout << sum << endl;
}

void Exercise_1_1_8::Proc()
{
	int n;
	cin >> n;

	string t = "1";
	string s = "";
	
	while (n > 0)
	{
		t[0] = char('0' + n % 2);
		s = t + s;

		n /= 2;
	}

	cout << s << endl;
}

static string exR1(int n)
{
	if (n <= 0)
		return "";

	string t = to_string(n);

	return exR1(n - 3) + t + exR1(n - 2) + t;
}

void Exercise_1_1_16::Proc()
{
	int n;
	cin >> n;

	cout << exR1(n);
}