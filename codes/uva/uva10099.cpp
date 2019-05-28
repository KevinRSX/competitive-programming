#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#define maxn 100 + 5
#define maxm 10000 + 5
using namespace std;

struct edge
{
  int from, to, w;
  bool operator<(const edge &e) const
  {
    return w > e.w;
  }
};

int f[maxn], s[maxn], tot = 0;
int n, r;
edge E[maxm];

void addEdge(int u, int v, int w)
{
  E[tot].from = u;
  E[tot].to = v;
  E[tot++].w = w;
}

int find(int n)
{
  if (f[n] == n) return n;
  else return f[n] = find(f[n]);
}

void u_by_height(int fa, int fb)
{
  if (s[fa] < s[fb])
  {
    f[fa] = fb;
    s[fa] = s[fa] + s[fb];
  }
  else
  {
    f[fb] = fa;
    s[fb] = s[fb] + s[fa];
  }
}

int kruskal(int source, int dest)
{
  for (int i = 0; i < maxn; i++)
  {
    f[i] = i;
    s[i] = 1;
  }
  sort(E, E + tot);
  int retval = 0;
  for (int i = 0; i < tot; i++)
  {
    int u = E[i].from;
    int v = E[i].to;
    int w = E[i].w;
    int t1 = find(u), t2 = find(v);
    if (t1 != t2)
    {
      retval = w;
      f[t1] = t2;
    }
    if (find(source) == find(dest)) break;
  }
  return retval;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int kase = 0;
  while (~scanf("%d%d", &n, &r) && (n || r))
  {
    tot = 0;
    for (int i = 0; i < r; i++)
    {
      int s, d, t;
      scanf("%d%d%d", &s, &d, &t);
      addEdge(s, d, t);
    }
    int s, d, t;
    scanf("%d%d%d", &s, &d, &t);
    int len = kruskal(s, d);
    printf("Scenario #%d\n", ++kase);
    printf("Minimum Number of Trips = %d\n\n", t / (len - 1) + (t % (len - 1) != 0));
  }
}
