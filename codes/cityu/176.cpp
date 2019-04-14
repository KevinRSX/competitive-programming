#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define maxn 100 + 5
#define maxm 10000 + 5
#define INF 0x3f3f3f3f

struct Edge
{
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f){}
};

struct EdmondKarp
{
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  int p[maxn];
  int a[maxn];

  void init(int n)
  {
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void addEdge(int from, int to, int cap)
  {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, cap, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  int MaxFlow(int s, int t)
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
  int n, kase = 1;
  while (~scanf("%d", &n) && n)
  {
    ek.init(n);
    int s, t, c;
    scanf("%d%d%d", &s, &t, &c);
    for (int i = 0; i < c; i++)
    {
      int u, v, cap;
      scanf("%d%d%d", &u, &v, &cap);
      ek.addEdge(u, v, cap);
    }
    printf("Network %d\n", kase++);
    printf("The bandwidth is %d.\n\n", ek.MaxFlow(s, t));
  }
}
