#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100 + 5
#define maxm 10000 + 5
using namespace std;

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
  return u[i] = find(u[i]);
}

int kruskal()
{
  for (int i = 0; i < maxm; i++) u[i] = i;
  int cnt = 0, min_edge = 0;
  sort(E, E + m, cmp);
  for (int i = m - 1; i >= 0; i--)
  {
    int v1 = E[i].from, v2 = E[i].to, w = E[i].w;
    int t1 = find(v1), t2 = find(v2);
    if (t1 != t2)
    {
      min_edge = w;
      u[t1] = t2;
      cnt++;
    }
  }
  return min_edge;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  for (int c = 1; c <= T; c++)
  {
    scanf("%d%d", &n, &m);
    m *= 2;
    int e = 0;
    while (e < m)
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
    printf("Case #%d: %d\n", c, kruskal());
  }
  return 0;
}
