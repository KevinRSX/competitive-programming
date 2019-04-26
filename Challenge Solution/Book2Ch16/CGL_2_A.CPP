#define EPS 1e-10
#define equals(a, b) (fabs((a) - (b)) < EPS)
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

class Point
{
public:
  double x, y;
  Point (double x = 0, double y = 0) : x(x), y(y) {}
  Point operator + (Point p) {return Point(x + p.x, y + p.y); }
  Point operator - (Point p) {return Point(x - p.x, y - p.y); }
  Point operator * (double a) {return Point(a * x, a * y); }
  Point operator / (double a) {return Point(x / a, y / a); }

  double norm() { return x * x + y * y; }
  double abs() { return sqrt(norm()); }

  bool operator < (const Point &p) const
  {
    return x != p.x ? x < p.x : y < p.y;
  }

  bool operator == (const Point &p) const
  {
    return equals(x, p.x) && equals(y, p.y);
  }
};

typedef Point Vector;
typedef vector<Point> Polygon;

struct Segment
{
  Point p1, p2;
};

typedef Segment Line;

class Circle
{
public:
  Point c;
  double r;
  Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};


// dot and cross product
double dot(Vector a, Vector b)
{
  return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b)
{
  return a.x * b.y - a.y * b.x;
}

bool isOrthagonal(Vector a, Vector b)
{
  return equals(dot(a, b), 0.0);
}

bool isOrthagonal(Point a1, Point a2, Point b1, Point b2)
{
  return isOrthagonal(a1 - a2, b1 - b2);
}

bool isParallel(Vector a, Vector b)
{
  return equals(cross(a, b), 0.0);
}

bool isParallel(Point a1, Point a2, Point b1, Point b2)
{
  return isParallel(a1 - a2, b1 - b2);
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    Point p0, p1, p2, p3;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &p0.x, &p0.y, &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);
    if (isOrthagonal(p0, p1, p2, p3))
    {
      printf("1\n");
    }
    else if (isParallel(p0, p1, p2, p3))
    {
      printf("2\n");
    }
    else
    {
      printf("0\n");
    }
  }
}
