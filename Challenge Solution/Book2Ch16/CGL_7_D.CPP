#define EPS 1e-10
#define equals(a, b) (fabs((a) - (b)) < EPS)
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
using namespace std;

// definition of turning
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

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
  Segment() {}
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


// dot and cross product
double dot(Vector a, Vector b)
{
  return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b)
{
  return a.x * b.y - a.y * b.x;
}

// orthogonality
bool isOrthagonal(Vector a, Vector b)
{
  return equals(dot(a, b), 0.0);
}

bool isOrthagonal(Point a1, Point a2, Point b1, Point b2)
{
  return isOrthagonal(a1 - a2, b1 - b2);
}

bool isOrthagonal(Segment s1, Segment s2)
{
  return isOrthagonal(s1.p1 - s1.p2, s2.p1 - s2.p2);
}

// parallelism
bool isParallel(Vector a, Vector b)
{
  return equals(cross(a, b), 0.0);
}

bool isParallel(Point a1, Point a2, Point b1, Point b2)
{
  return isParallel(a1 - a2, b1 - b2);
}

bool isParallel(Segment s1, Segment s2)
{
  return isParallel(s1.p1 - s1.p2, s2.p1 - s2.p2);
}

// projection & reflection
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

// distance
double getDistance(Point a, Point b)
{
  return (a - b).abs();
}

double getDistanceLP(Line l, Point p)
{
  return abs(cross(l.p1 - l.p2, p - l.p1)) / (l.p2 - l.p1).abs();
}

double getDistanceSP(Segment s, Point p)
{
  if (dot(p - s.p1, s.p2 - s.p1) < 0) return getDistance(p, s.p1);
  if (dot(p - s.p2, s.p1 - s.p2) < 0) return getDistance(p, s.p2);
  return getDistanceLP(s, p);
}

bool intersect(Point p1, Point p2, Point p3, Point p4);
bool intersect(Segment s1, Segment s2);
double getDistanceSS(Segment s1, Segment s2)
{
  if (intersect(s1, s2)) return 0.0;
  return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)), \
            min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

//ccw
int ccw(Point p0, Point p1, Point p2)
{
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPS) return CLOCKWISE;
  if (dot(a, b) < -EPS) return ONLINE_BACK;
  if (a.norm() < b.norm()) return ONLINE_FRONT;
  return ON_SEGMENT;
}

// intersection
bool intersect(Point p1, Point p2, Point p3, Point p4)
{
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && \
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2)
{
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

// Cross point
Point getCrossPoint(Segment s1, Segment s2)
{
  Vector base = s2.p2 - s2.p1;
  double d1 = abs(cross(base, s1.p1 - s2.p1));
  double d2 = abs(cross(base, s1.p2 - s2.p1));
  double t = d1 / (d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1) * t;
}

// Cross points of a circle and a line
pair<Point, Point> getCrossPoints(Circle c, Line l)
{
  Vector pr = project(l, c.c);
  Vector e = (l.p2 - l.p1) / (l.p2 - l.p1).abs();
  double base = sqrt(c.r * c.r - (pr - c.c).norm());
  return make_pair(pr + e * base, pr - e * base);
}

int main()
{
  Circle c;
  scanf("%lf%lf%lf", &c.c.x, &c.c.y, &c.r);
  int q;
  scanf("%d", &q);
  while (q--)
  {
    Line l;
    scanf("%lf%lf%lf%lf", &l.p1.x, &l.p1.y, &l.p2.x, &l.p2.y);
    Point cp1 = getCrossPoints(c, l).first;
    Point cp2 = getCrossPoints(c, l).second;
    if (cp2 < cp1)
    {
      Point temp = cp1;
      cp1 = cp2;
      cp2 = temp;
    }
    printf("%.8lf %.8lf %.8lf %.8lf\n", cp1.x, cp1.y, cp2.x, cp2.y);
  }
  return 0;
}
