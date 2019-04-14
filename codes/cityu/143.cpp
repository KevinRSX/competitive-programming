#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define maxn 100 + 5
#define maxm 10000 + 5

struct edge
{
  int from, to, w;
};

bool cmp(edge e1, edge e2)
{
  return e1.w < e2.w;
}

edge E[maxm];
int u[maxm], n, m;

int find(int i)
{
  if (u[i] == i) return i;
  else return u[i] = find(u[i]);
}

int kruskal(int l, int r)
{
  for (int i = 0; i < 2 * m - 1; i++) u[i] = i;
  int cnt = 0, max_edge = 0;
  for (int i = l; i <= r; i++)
  {
    int p1 = E[i].from;
    int p2 = E[i].to;
    int w = E[i].w;
    int t1 = find(p1), t2 = find(p2);
    if (t1 != t2)
    {
      max_edge = w;
      u[find(p1)] = p2;
      cnt++;
    }
    if (cnt == n - 1)
    {
      return max_edge - E[l].w;
    }
  }
  if (cnt < n - 1) return -1;
  else return max_edge - E[l].w;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  while (~scanf("%d%d", &n, &m) && (n || m))
  {
    int e = 0;
    while (e < 2 * m)
    {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      E[e].from = u;
      E[e].to = v;
      E[e].w = w;
      e++;
      E[e].from = v;
      E[e].to = u;
      E[e].w = w;
      e++;
    }
    sort(E, E + 2 * m, cmp);
    int res = kruskal(0, 2 * m - 1);
    bool found = false;
    if (res >= 0) found = true;
    for (int i = 1; i <= 2 * m - n + 1; i++)
    {
      int tmp = kruskal(i, 2 * m - 1);
      if (!found && tmp >= 0)
      {
        found = true;
        res = tmp;
      }
      else if (found && tmp < res && tmp >= 0)
      {
        res = tmp;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
