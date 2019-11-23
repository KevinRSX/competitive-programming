#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 10000 + 5
#define INF 0x3f3f3f3f

struct Point
{
  double x, y;
  Point(double ax = 0.0, double ay = 0.0): x(ax), y(ay) {}
};

bool cmp(Point p1, Point p2)
{
  return p1.x < p2.x;
}

double dist(Point p1, Point p2)
{
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

Point pset[maxn];
double mindist(int start, int end)
{
  if (start + 1 == end) return dist(pset[start], pset[end]);
  if (start == end) return INF;
  int mid = (start + end) / 2;
  double dis = min(mindist(start, mid - 1), mindist(mid + 1, end));
  int l = mid, r = mid;
  while (l >= start && pset[mid].x - pset[l].x <= dis) l--;
  while (r <= end && pset[r].x - pset[mid].x <= dis) r++;
  for (int i = l + 1; i < r; i++)
  {
    for (int j = i + 1; j < r; j++)
    {
      dis = min(dis, dist(pset[i], pset[j]));
    }
  }
  return dis;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n;
  while (~scanf("%d", &n) && n)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%lf%lf", &pset[i].x, &pset[i].y);
    }
    sort(pset, pset + n, cmp);
    double res = mindist(0, n - 1);
    if (res >= 10000.0) printf("INFINITY\n");
    else printf("%.4lf\n", res);
  }
  return 0;
}
