#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define maxn 300 + 5
#define maxm 90000 + 5
#define INF 0x3f3f3f3f

struct pad
{
  double f, x, y, r;
};

bool touch(pad p1, pad p2)
{
  double dis = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  return dis <= p1.r + p2.r;
}

struct Edge
{
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f) {}
};

struct EdmondKarp
{
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  int a[maxn];
  int p[maxn];

  void init(int n)
  {
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void addEdge(int from, int to, int cap)
  {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    int m = edges.size();
    G[to].push_back(m - 1);
    G[from].push_back(m - 2);
  }

  int maxflow(int s, int t)
  {
    int flow = 0;
    for (;;)
    {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = INF;
      while (!Q.empty())
      {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < G[x].size(); i++)
        {
          Edge &e = edges[G[x][i]];
          if (!a[e.to] && e.cap > e.flow)
          {
            a[e.to] = min(a[x], e.cap - e.flow);
            p[e.to] = G[x][i];
            Q.push(e.to);
          }
        }
        if (a[t]) break;
      }
      if (!a[t]) break;
      for (int u = t; u != s; u = edges[p[u]].from)
      {
        edges[p[u]].flow += a[t];
        edges[p[u] ^ 1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }
};

pad allpads[maxn];
EdmondKarp ek;

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int n;
    scanf("%d", &n);
    ek.init(n);
    int s, t;
    for (int i = 0; i < n; i++)
    {
      scanf("%lf%lf%lf%lf", &allpads[i].f, &allpads[i].x, &allpads[i].y, &allpads[i].r);
      if (allpads[i].f == 400.0) s = i;
      else if (allpads[i].f == 789.0) t = i;
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (touch(allpads[i], allpads[j]))
        {
          if (allpads[i].f < allpads[j].f) ek.addEdge(i, j, 1);
          else if (allpads[i].f > allpads[j].f) ek.addEdge(j, i, 1);
        }
      }
    }
    int res = ek.maxflow(s, t);
    if (res >= 2) printf("Game is VALID\n");
    else printf("Game is NOT VALID\n");
  }
  return 0;
}
