#define EPS 1e-10
#define equals(a, b) (fabs((a) - (b)) < EPS)
#include <cstdio>
#include <cmath>
#include <vector>
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
  Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
  Segment(double x1, double y1, double x2, double y2)
  {
    p1 = Point(x1, y1);
    p2 = Point(x2, y2);
  }
};

typedef Segment Line;

// dot and cross product
double dot(Vector a, Vector b)
{
  return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b)
{
  return a.x * b.y - a.y * b.x;
}

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

int main()
{
  Point p0, p1;
  scanf("%lf%lf%lf%lf", &p0.x, &p0.y, &p1.x, &p1.y);
  int q;
  scanf("%d", &q);
  while (q--)
  {
    Point p2;
    scanf("%lf%lf", &p2.x, &p2.y);
    int retval = ccw(p0, p1, p2);
    if (retval == COUNTER_CLOCKWISE) printf("COUNTER_CLOCKWISE\n");
    else if (retval == CLOCKWISE) printf("CLOCKWISE\n");
    else if (retval == ONLINE_BACK) printf("ONLINE_BACK\n");
    else if (retval == ONLINE_FRONT) printf("ONLINE_FRONT\n");
    else printf("ON_SEGMENT\n");
  }
  return 0;
}
