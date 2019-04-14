#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 500 + 5
#define maxm 1000000 + 5

struct edge
{
  int from, to;
  unsigned int w;
};

bool cmp(edge e1, edge e2)
{
  return e1.w > e2.w;
}

edge E[maxm];
int u[maxn], s[maxn];

int find(int i)
{
  if (u[i] == i) return i;
  return u[i] = find(u[i]);
}

int younion(int v1, int v2)
{
  int f1 = find(v1), f2 = find(v2);
  if (f1 != f2)
  {
    u[f1] = f2;
    s[f2] = s[f1] + s[f2];
  }
  return s[f2];
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, m;
  while (~scanf("%d%d", &n, &m) && (n || m))
  {
    for (int i = 0; i <= n; i++)
    {
      u[i] = i;
      s[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d%d", &E[i].from, &E[i].to, &E[i].w);
    }
    sort(E, E + m, cmp);
    int max_ppa = E[0].w;
    int res = 0;
    for (int i = 0; i < m; i++)
    {
      if (E[i].w < max_ppa) break;
      res = max(younion(E[i].from, E[i].to), res);
    }
    printf("%d\n", res);
  }
  return 0;
}
