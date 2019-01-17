#define _USE_MATH_DEFINES	//used before importing cmath to enable math constant M_PI

#include <iostream>
#include <iomanip>
#include <cmath>

struct Point
{
	double x;
	double y;
};


void koch(int depth, Point start, Point end)
{
	using namespace std;
	cout.precision(8);
	cout << std::fixed;

	if (depth == 0)
	{
		return;
	}
	
	Point s, t, u;
	double sixty = M_PI * 60 / 180;
	s.x = (2 * start.x + end.x) / 3.0;
	s.y = (2 * start.y + end.y) / 3.0;
	t.x = (start.x + 2 * end.x) / 3.0;
	t.y = (start.y + 2 * end.y) / 3.0;
	u.x = (t.x - s.x)*cos(sixty) - (t.y - s.y)*sin(sixty) + s.x;
	u.y = (t.x - s.x)*sin(sixty) + (t.y - s.y)*cos(sixty) + s.y;

	koch(depth - 1, start, s);
	cout << s.x << ' ' << s.y << endl;
	koch(depth - 1, s, u);
	cout << u.x << ' ' << u.y << endl;
	koch(depth - 1, u, t);
	cout << t.x << ' ' << t.y << endl;
	koch(depth - 1, t, end);
}

int main()
{
	Point a, b;
	int n;
	std::cin >> n;
	a.x = 0.0, a.y = 0.0;
	b.x = 100.0, b.y = 0;
	std::cout << a.x << ' ' << a.y << std::endl;
	koch(n, a, b);	
	std::cout << b.x << ' ' << b.y << std::endl;
	return 0;
}