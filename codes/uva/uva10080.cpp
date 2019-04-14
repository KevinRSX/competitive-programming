#include <cstdio>
#include <cstring>
#include <cmath>
#define maxn 100 + 5

int n, m, s, v;
bool bp[maxn][maxn];
bool chw[maxn];
int res[maxn];

struct point
{
  double x, y;
};

point gopher[maxn], hole[maxn];

bool match(point p1, point p2)
{
  double d = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  if (v * s >= d) return true;
  else return false;
}

bool find(int x)
{
  for (int j = 1; j <= m; j++)
  {
    if (bp[x][j] && chw[j])
    {
      chw[j] = false;
      if (res[j] == 0 || find(res[j]))
      {
        res[j] = x;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  while (~scanf("%d%d%d%d", &n, &m, &s, &v))
  {
    memset(bp, 0, sizeof(bp));
    for (int i = 1; i <= n; i++)
    {
      scanf("%lf%lf", &gopher[i].x, &gopher[i].y);
    }
    for (int i = 1; i <= m; i++)
    {
      scanf("%lf%lf", &hole[i].x, &hole[i].y);
    }
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (match(gopher[i], hole[j])) bp[i][j] = true;
      }
    }

    int ans = 0;
    memset(res, 0, sizeof(res));
    for (int i = 1; i <= n; i++)
    {
      memset(chw, true, sizeof(chw));
      if (find(i)) ans++;
    }
    printf("%d\n", n - ans);
  }
}
