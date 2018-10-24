#include "chapter_1.h"
#include "utils.h"

void Exercise_1_1_1()
{
	cout << "(0 + 15) / 2 = " << (0 + 15) / 2 << endl;
	cout << "2.0e-6 * 100000000.1 = " << 2.0e-6 * 100000000.1 << endl;
	cout << "true && false || true && true = " << (true && false || true && true) << endl;
}

void Exercise_1_1_3()
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

void Exercise_1_1_6()
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

void Exercise_1_1_7()
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

void Exercise_1_1_8()
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
	{
		return "";
	}

	string t = to_string(n);

	return exR1(n - 3) + t + exR1(n - 2) + t;
}

void Exercise_1_1_16()
{
	int n;
	cin >> n;

	cout << exR1(n);
}

static int mystery(int a, int b)
{
	if (b == 0)
	{
		return 0;
	}

	if (b % 2 == 0)
	{
		return mystery(a + a, b / 2);
	}

	return mystery(a + a, b / 2) + a;
}

static int mystery2(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}

	if (b % 2 == 0)
	{
		return mystery2(a * a, b / 2);
	}

	return mystery2(a * a, b / 2) * a;
}

void Exercise_1_1_18()
{
	int a, b;
	cin >> a >> b;

	//easy_timer t;

	cout << mystery2(a, b);
}

static int fibonacci_note[1000];

static int fibonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	if (fibonacci_note[n] != 0)
	{
		return fibonacci_note[n];
	}

	//fibonacci_note[n] = fibonacci(n - 1) + fibonacci(n - 2);

	//return fibonacci_note[n];
	return fibonacci(n - 1) + fibonacci(n - 2);
}

void Exercise_1_1_19()
{
	int n;
	cin >> n;

	memset(fibonacci_note, 0, sizeof(fibonacci_note));

	for (int i = 0; i < n; ++i)
	{
		easy_timer t;
		cout << "fibonacci " << i << " = " << fibonacci(i) << endl;
	}
}

static double ln_factorial(int n)
{
	// hint: log8 = log(2 * 4) = log2 + log4
	if (n == 1) return 0;

	return ln_factorial(n - 1) + log(double(n));
}

void Exercise_1_1_20()
{
	int n;
	cin >> n;

	easy_timer t;

	cout << ln_factorial(n) << endl;
}

static int binary_search(const vector<int>& numbers, int key, int lo, int hi, int depth)
{
	for (int i = 0; i < depth; ++i)
	{
		cout << "  ";
	}

	cout << lo << ' ' << hi << endl;

	if (lo > hi)
	{
		return -1;
	}

	if (numbers[lo] == key) return lo;
	if (numbers[hi] == key) return hi;
	
	int mid = (lo + hi) / 2;

	if (numbers[mid] == key)
	{
		return mid;
	}
	else if (numbers[mid] < key)
	{
		return binary_search(numbers, key, mid + 1, hi, depth + 1);
	}
	else
	{
		return binary_search(numbers, key, lo, mid - 1, depth + 1);
	}
}

void Exercise_1_1_22()
{
	vector<int> numbers;

	const int n = 1000;

	random_int_list(n, 1, 10000, numbers);
	sort(numbers.begin(), numbers.end());

	int i_key = random_int(0, n);
	int key = numbers[i_key];

	int i_found = binary_search(numbers, key, 0, n - 1, 0);

	cout << i_key << ' ' << i_found << endl;
}

// Euclid
static int gcd(int p, int q)
{
	cout << p << ' ' << q << endl;

	if (q == 0)
	{
		return p;
	}

	int r = p % q;

	return gcd(q, r);
}

void Exercise_1_1_24()
{
	int p, q;
	cin >> p >> q;

	cout << gcd(p, q) << endl;
}

#define BINOMAIL_N_MAX 100
static double binomial_data[BINOMAIL_N_MAX + 1][BINOMAIL_N_MAX + 1];

static double binomial(int n, int k, double p)
{
	if ((n == 0) && (k == 0))
	{
		return 1.0;
	}

	if ((n < 0) || (k < 0))
	{
		return 0.0;
	}

	if (binomial_data[n][k] >= 0.0)
	{
		return binomial_data[n][k];
	}

	binomial_data[n][k] = (1 - p) * binomial(n - 1, k, p) + p * binomial(n - 1, k - 1, p);

	return binomial_data[n][k];
}

void Exercise_1_1_27()
{
	int n, k;
	double p;
	cin >> n >> k >> p;

	for (int i = 0; i <= BINOMAIL_N_MAX; ++i)
	{
		for (int j = 0; j <= BINOMAIL_N_MAX; ++j)
		{
			binomial_data[i][j] = -1.0;
		}
	}

	easy_timer t;

	cout << binomial(n, k, p) << endl;
}

void Exercise_1_1_31()
{
	int n;
	double p;
	cin >> n >> p;

	initgraph(800, 600, SHOWCONSOLE);

	double cur_angle = 0.0;
	double t_angle = PI_2 / n;

	struct point_t
	{
		int x;
		int y;
	};

	vector<point_t> point_arr;
	point_arr.resize(n);

	for (int i = 0; i < n; ++i, cur_angle += t_angle)
	{
		point_arr[i].x = 400 + (int)(cos(cur_angle) * 200.0f);
		point_arr[i].y = 300 + (int)(sin(cur_angle) * 200.0f);
		circle(point_arr[i].x, point_arr[i].y, 5);
	}

	int n_line = 0;
	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (random_float(0.0f, 1.0f) <= (float)p)
			{
				line(point_arr[i].x, point_arr[i].y, point_arr[j].x, point_arr[j].y);
				n_line++;
			}

			count++;
		}
	}

	cout << n_line << ' ' << count << endl;

	_getch();
	closegraph();
}

void Exercise_1_1_32()
{
	int n;
	double lo, hi;
	cin >> n >> lo >> hi;

	int n_number = n * 100;
	vector<double> number_arr;
	random_double_list(n_number, lo, hi, number_arr);

	vector<int> sect_count;
	sect_count.resize(n, 0);

	for (int i = 0; i < n_number; ++i)
	{
		double t_number = number_arr[i];

		if (t_number < lo || hi < t_number)
		{
			continue;
		}

		int i_sect = (int)((double)n * (t_number - lo) / (hi - lo));
		sect_count[i_sect]++;
	}

	initgraph(800, 600, SHOWCONSOLE);

	int cur_left = 100;
	int t_left = ((800 - 100) - 100) / n;
	int bottom = 200;

	for (int i = 0; i < n; ++i)
	{
		rectangle(cur_left, 500 - sect_count[i] * 3, cur_left + t_left, 500);

		RECT r = { cur_left, 500 - sect_count[i] * 3, cur_left + t_left, 500 };
		drawtext(_T(to_string(sect_count[i]).c_str()), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		cur_left += t_left;
	}

	_getch();
	closegraph();
}

void Exercise_1_1_33()
{
	EasyVector vec_a(3); vec_a[0] = 1; vec_a[1] = 2; vec_a[2] = 3;
	EasyVector vec_b(3); vec_b[0] = 4; vec_b[1] = 5; vec_b[2] = 6;
	EasyVector vec_c(4); vec_c[0] = 7; vec_c[1] = 8; vec_c[2] = 9; vec_c[3] = 10;
	cout << "vec_a = {1, 2, 3}, vec_b = {4, 5, 6}, vec_c = {7, 8, 9, 10}" << endl;

	EasyMatrix mtx_a(2, 3);
	mtx_a[0][0] = 1; mtx_a[0][1] = 2; mtx_a[0][2] = 3;
	mtx_a[1][0] = 4; mtx_a[1][1] = 5; mtx_a[1][2] = 6;
	cout << "mtx_a = {{1, 2, 3}, {4, 5, 6}}" << endl;

	EasyMatrix mtx_b(3, 2);
	mtx_b[0][0] = 1; mtx_b[0][1] = 2;
	mtx_b[1][0] = 3; mtx_b[1][1] = 4;
	mtx_b[2][0] = 5; mtx_b[2][1] = 6;
	cout << "mtx_b = {{1, 2}, {3, 4}, {5, 6}}" << endl;

	cout << endl;

	cout << "VectorDot(vec_a, vec_b) = " << VectorDot(vec_a, vec_b) << endl;
	cout << "VectorDot(vec_a, vec_c) = " << VectorDot(vec_a, vec_c) << endl;

	EasyMatrix t_mtx = MatrixMultiply(mtx_a, mtx_b);
	cout << "MatrixMultiply(mtx_a, mtx_b) = "; t_mtx.print(); cout << endl;
	t_mtx = MatrixMultiply(mtx_a, mtx_a);
	cout << "MatrixMultiply(mtx_a, mtx_a) = "; t_mtx.print(); cout << endl;

	t_mtx = MatrixTranspose(mtx_a);
	cout << "MatrixTranspose(mtx_a) = "; t_mtx.print(); cout << endl;

	EasyVector t_vec = MatrixMultiplyVector(mtx_a, vec_a);
	cout << "MatrixMultiplyVector(mtx_a, vec_a) = "; t_vec.print(); cout << endl;

	t_vec = VectorMultiplyMatrix(vec_a, mtx_b);
	cout << "VectorMultiplyMatrix(vec_a, mtx_b) = "; t_vec.print(); cout << endl;
}