#include <cstdio>
#include <utility>
#include <cmath>
using namespace std;
#define maxn 200
#define INFTY 0xffffff

struct point
{
  double x, y;
};

double dist(point p1, point p2)
{
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

point V[maxn + 5];
int p[maxn + 5], d[maxn + 5];
bool vis[maxn + 5];

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int n, kase = 1;
  while (~scanf("%d", &n) && n != 0)
  {
    for (int i = 0; i < maxn + 5; i++)
    {
      V[i].x = V[i].y = 0;
      p[i] = -1;
      vis[i] = false;
      d[i] = INFTY;
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%lf%lf", &V[i].x, &V[i].y);
    }

    d[0] = 0;
    while (true)
    {
      int mincost = INFTY, u;
      for (int i = 0; i < n; i++)
      {
        if (!vis[i] && d[i] < mincost)
        {
          mincost = d[i];
          u = i;
        }
      }

      if (mincost == INFTY) break;
      vis[u] = true;

      for (int i = 0; i < n; i++)
      {
        double tmp_d = dist(V[u], V[i]);
        if (!vis[i] && tmp_d < d[i])
        {
          d[i] = tmp_d;
          p[i] = u;
        }
      }
    }
    double fd = 0;
    for (int k = 1; p[k] != -1; k = p[k])
    {
      if (dist(V[k], V[p[k]]) > fd)
      {
        fd = dist(V[k], V[p[k]]);
      }
    }
    printf("Scenario #%d\n", kase++);
    printf("Frog Distance = %.3lf\n\n", fd);
  }
}
