#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 5000 + 5
#define maxm 70000 + 5
#define INF 0x3f3f3f3f

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
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  long long maxflow(int s, int t)
  {
    long long flow = 0;
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
          if (e.cap > e.flow && !a[e.to])
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
    memset(a, 0, sizeof(a));
    return flow;
  }

  int dfs(int s)
  {
    int res;
    if (s == 0) res = 0;
    else res = 1;
    for (int i = 0; i < G[s].size(); i++)
    {
      Edge &e = edges[G[s][i]];
      if (!a[e.to] && e.cap > e.flow)
      {
        a[e.to] = 1;
        res += dfs(e.to);
      }
    }
    return res;
  }
};

EdmondKarp ek;

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int n, m;
  while (~scanf("%d%d", &n, &m))
  {
    int s = 0, t = n + 1;
    ek.n = n + 2;
    ek.init(n + 2);
    long long allpos = 0;
    for (int i = 1; i <= n; i++)
    {
      int npl;
      scanf("%d", &npl);
      if (npl >= 0)
      {
        allpos += npl;
        ek.addEdge(s, i, npl);
      }
      else ek.addEdge(i, t, -npl);
    }
    for (int i = 0; i < m; i++)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      ek.addEdge(u, v, INF);
    }
    long long mf = ek.maxflow(s, t);
    //printf("%lld\n", allpos - mf);
    int fire = ek.dfs(s);
    printf("%d %lld\n", fire, allpos - mf);
  }
  return 0;
}
