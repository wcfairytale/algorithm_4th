#include "chapter_1.h"
#include "utils/utils.h"

void Exercise_1_1_1()
{
	cout << "(0 + 15) / 2 = " << (0 + 15) / 2 << endl;
	cout << "2.0e-6 * 100000000.1 = " << 2.0e-6 * 100000000.1 << endl;
	cout << "true && false || true && true = "
		<< (true && false || true && true) << endl;
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

	//auto_timer timer;

	cout << mystery(a, b);
}

static int fibonacci_note[1000];

void Exercise_1_1_19()
{
	int n;
	cin >> n;

	memset(fibonacci_note, 0, sizeof(fibonacci_note));

	for (int i = 0; i < n; ++i)
	{
		//auto_timer t;
		cout << "fibonacci " << i << " = "
			<< fibonacci(i, fibonacci_note) << endl;
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

	//auto_timer t;

	cout << ln_factorial(n) << endl;
}

void Exercise_1_1_22()
{
	vector<int> numbers;

	const int n = 1000;

	random_number_list(n, 1, 10000, numbers);
	sort(numbers.begin(), numbers.end());

	int i_key = random_number(0, n);
	int key = numbers[i_key];

#ifdef PRINT_LOG
	int i_found = binary_search(numbers, key, 0, n - 1, 0);
#else
	int i_found = binary_search(numbers, key, 0, n - 1);
#endif

	cout << i_key << ' ' << i_found << endl;
}

void Exercise_1_1_24()
{
	int p, q;
	cin >> p >> q;

	cout << gcd(p, q) << endl;
}

void Exercise_1_1_27()
{
	int n, k;
	double p;
	cin >> n >> k >> p;

	const int n_max_plus_one = 101;

	vector<vector<double>> note;
	note.resize(n_max_plus_one);

	for (int i = 0; i < n_max_plus_one; ++i)
	{
		note[i].resize(n_max_plus_one, -1.0);
	}

	auto_timer t;

	cout << binomial(n, k, p, note) << endl;
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
			if (random_number(0.0f, 1.0f) <= (float)p)
			{
				line(point_arr[i].x, point_arr[i].y,
					point_arr[j].x, point_arr[j].y);
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
	random_number_list(n_number, lo, hi, number_arr);

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
		drawtext(_T(to_string(sect_count[i]).c_str()), &r,
			DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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
	cout << "vec_a = "; vec_a.print();
	cout << " vec_b = "; vec_b.print();
	cout << " vec_c = "; vec_c.print();
	cout << endl;

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

void Exercise_1_1_35()
{
#define SIDES 6
#define N_PROBS 36.0

	int freqs[13];
	memset(freqs, 0, sizeof(freqs));

	for (int i = 1; i <= SIDES; ++i)
	{
		for (int j = 1; j <= SIDES; ++j)
		{
			freqs[i + j]++;
		}
	}

	double probs[13];
	memset(probs, 0, sizeof(probs));

	for (int i = 2; i <= 2 * SIDES; ++i)
	{
		probs[i] = freqs[i] / N_PROBS;
	}

	
	bool matched[13];
	memset(matched, false, sizeof(matched));

	int count[13];
	memset(count, 0, sizeof(count));

	int n = 0;
	int n_matched = 0;
	
	while (true)
	{
		int sum = random_number(1, SIDES + 1) + random_number<int>(1, SIDES + 1);

		++n;

		if (matched[sum])
		{
			continue;
		}

		count[sum]++;

		if (double_equal((double)count[sum] / (double)n, probs[sum], 0.0005))
		{
			matched[sum] = true;
			n_matched++;

			if (n_matched == 11)
			{
				break;
			}
		}
	}

	cout << n << endl;
}

void Exercise_1_1_36()
{
	int n, m;
	cin >> n >> m;

	vector<int> arr;
	arr.resize(m);

	vector<int> count;
	count.resize(m * m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			arr[j] = j;
		}

		shuffle(arr);

		//cout << "shuffle " << i << ": ";

		for (int j = 0; j < m; ++j)
		{
			//cout << arr[j] << ' ';
			count[arr[j] * m + j]++;
		}

		//cout << endl;
	}

	double due = (double)n / (double)m;

	double ave_diff = 0.0;
	double max_diff = -1.0;
	
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int index = i * m + j;

			cout << count[index] << ' ';

			double diff = fabs(double(count[index] - due));

			if (diff > max_diff)
			{
				max_diff = diff;
			}

			ave_diff += diff;
		}

		cout << endl;
	}

	ave_diff /= m * m;

	cout << due << ' ' << ave_diff << ' ' << max_diff << endl;
}

void Exercise_1_1_38()
{
	const int n_numbers = 100000;
	vector<int> numbers;
	random_number_list(n_numbers, 0, 100000000, numbers);
	sort(numbers.begin(), numbers.end());
	
	const int n_test = 200;
	int rand_indexes[n_test];
	
	for (int i = 0; i < n_test; ++i)
	{
		rand_indexes[i] = random_number(0, n_numbers - 1);
	}

	easy_timer timer;
	
	timer.start();

	for (int i = 0; i < n_test; ++i)
	{
		int key = numbers[rand_indexes[i]];
		int i_found = brute_force_search(numbers, key);

		if (key != numbers[i_found])
		{
			cout << "[error] brute_force_search" << endl;
		}
	}

	cout << timer.timer() << " secs" << endl;

	timer.start();

	for (int i = 0; i < n_test; ++i)
	{
		int key = numbers[rand_indexes[i]];

#ifdef PRINT_LOG
		int i_found = binary_search(numbers, key, 0, (int)numbers.size() - 1, 0);
#else
		int i_found = binary_search(numbers, key, 0, (int)numbers.size() - 1);
#endif

		if (key != numbers[i_found])
		{
			cout << "[error] binary_search" << endl;
		}
	}

	cout << timer.timer() << " secs" << endl;
}

void Exercise_1_1_39()
{
	int trials;
	cin >> trials;

	if (trials <= 0)
	{
		return;
	}

	easy_timer timer;

	timer.start();

	int n_numbers[4] = { 1000, 10000, 100000, 1000000 };

	int quantities[4];
	memset(quantities, 0, sizeof(quantities));

	for (int i = 0; i < trials; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int n = n_numbers[j];

			vector<int> numbers_a;
			random_number_list(n, 100000, 1000000, numbers_a);
			sort(numbers_a.begin(), numbers_a.end());

			vector<int> numbers_b;
			random_number_list(n, 100000, 1000000, numbers_b);
			sort(numbers_b.begin(), numbers_b.end());

			for (int k = 0; k < n; ++k)
			{
				int key = numbers_a[k];
				int i_found = binary_search(numbers_b, key, 0, n - 1);

				if (i_found >= 0)
				{
					if (key != numbers_b[i_found])
					{
						cout << "error!" << endl;
					}

					quantities[j]++;
				}
			}
		}
	}

	cout << "time: " << timer.timer() << endl;

	for (int i = 0; i < 4; ++i)
	{
		double ave_quantity = (double)quantities[i] / (double)trials;
		double ratio = ave_quantity / (double)n_numbers[i];

		cout << "n = " << n_numbers[i]
			<< " ave_quantity = " << ave_quantity
			<< ' ' << ratio << endl;
	}
}