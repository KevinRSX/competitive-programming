#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 200 + 5
#define maxm 40000 + 5
#define INF 0x3f3f3f3f

struct Edge
{
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f) {}
};

struct Point
{
  double x, y;
};

int l, w, n, d;
double dis(Point a, Point b)
{
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

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
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  int maxFlow(int s, int t)
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
            p[e.to] = G[x][i];
            a[e.to] = min(a[x], e.cap - e.flow);
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

EdmondKarp ek;

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int kase = 0;
  while (~scanf("%d%d%d%d", &l, &w, &n, &d) && (l || w || n || d))
  {
    ek.init(2 * n + 2);
    Point robot[maxn]; // 1...n: in, n+1...2n: out
    // 0: s, 2n+1: t
    for (int i = 1; i <= n; i++)
    {
      scanf("%lf%lf", &robot[i].x, &robot[i].y);
      robot[i + n].x = robot[i].x;
      robot[i + n].y = robot[i].y;
    }
    for (int i = 1; i <= n; i++)
    {
      if (w - robot[i].y <= d)
      {
        ek.addEdge(0, i, 1);
      }
      if (robot[i + n].y <= d)
      {
        ek.addEdge(i + n, 2 * n + 1, 1);
      }
      ek.addEdge(i, i + n, 1);
      for (int j = i + 1; j <= n; j++)
      {
        if (dis(robot[i], robot[j]) <= 2 * d)
        {
          ek.addEdge(i + n, j, 1);
          ek.addEdge(j + n, i, 1);
        }
      }
    }
    printf("Case %d: %d\n", ++kase, ek.maxFlow(0, 2 * n + 1));
  }
  return 0;
}
