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
  Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
  Segment(double x1, double y1, double x2, double y2)
  {
    p1 = Point(x1, y1);
    p2 = Point(x2, y2);
  }
};

typedef Segment Line;

class Circle
{
public:
  Point c;
  double r;
  Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};

double dot(Vector a, Vector b)
{
  return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b)
{
  return a.x * b.y - a.y * b.x;
}

Point project(Segment s, Point p)
{
  Vector base = s.p2 - s.p1;
  double r = dot(p - s.p1, base) / base.norm();
  return s.p1 + base * r;
}

Point reflect(Segment s, Point p)
{
  return p + (project(s, p) - p) * 2.0;
}

int main()
{
  double x1, y1, x2, y2;
  scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
  Segment s(x1, y1, x2, y2);
  int q;
  scanf("%d", &q);
  while (q--)
  {
    Point p;
    scanf("%lf%lf", &p.x, &p.y);
    Point ref = reflect(s, p);
    printf("%.8lf %.8lf\n", ref.x, ref.y);
  }
  return 0;
}
