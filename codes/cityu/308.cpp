#include <cstdio>
#include <cassert>
#include <algorithm>
#define maxn 500 + 5
#define maxm 250000 + 5
using namespace std;

struct edge
{
  int from, to, w;
};

bool cmp(edge e1, edge e2)
{
  return e1.w < e2.w;
}

int digit_diff(int a, int b)
{
  if (a >= b)
  {
    return min(a - b, b - a + 10);
  }
  else
  {
    return min(b - a, a - b + 10);
  }
}

int pos_diff(int a, int b)
{
  return digit_diff(a % 10, b % 10) + digit_diff((a / 10) % 10, (b / 10) % 10) +\
    digit_diff((a / 100) % 10, (b / 100) % 10) +\
    digit_diff((a / 1000) % 10, (b / 1000) % 10);
}

int nodes[maxn], n, m, u[maxm];
edge E[maxm];

int find(int i)
{
  if (u[i] == i) return i;
  return u[i] = find(u[i]);
}

int kruskal()
{
  for (int i = 0; i < n; i++) u[i] = i;
  sort(E, E + m, cmp);
  int cnt = 0, tot = 0;
  for (int i = 0; i < m; i++)
  {
    int p1 = E[i].from, p2 = E[i].to;
    int w = E[i].w;
    int t1 = find(p1), t2 = find(p2);
    if (t1 != t2)
    {
      u[t1] = t2;
      tot += w;
      cnt++;
    }
    if (cnt == n - 1) return tot;
  }

  assert(cnt >= n-1);
  return tot;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &n);
    int min_dist = 100;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &nodes[i]);
      int tmp_diff = pos_diff(0, nodes[i]);
      if (tmp_diff < min_dist)
      {
        min_dist = tmp_diff;
      }
    }
    m = 0;
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        E[m].from = i;
        E[m].to = j;
        E[m].w = pos_diff(nodes[i], nodes[j]);
        m++;
      }
    }
    printf("%d\n", kruskal() + min_dist);
  }
  return 0;
}
