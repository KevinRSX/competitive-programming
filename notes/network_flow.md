# 最大流问题

## 增广路算法

### Edmonds-Karp

```c++
struct Edge
{
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f) {}
};

struct EdmondsKarp
{
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];	// G[i][j]: the index in edges of the j-th edge of the i-th vertex
  int a[maxn]; 	// minimum residual value from an augmenting path
  // can be used as vis[] array in bfs
  int p[maxn];	// parent node in an s-t path
};

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
      if (a[t]) break;	// augmenting path found
    }
    if (!a[t]) break;		// no more augmenting path, maxflow reached
    for (int u = t; u != s; u = edges[p[u]].from)
    {
      edges[p[u]].flow += a[t];
      edges[p[u] ^ 1].flow -= a[t];
    }
    flow += a[t];
  }
  return flow;
}
```



## 最小费用最大流问题

思路和Edmonds-Karp一致，但每次用SPFA而不是BFS找增广路。

```c++
struct Edge
{
  int from, to, cap, flow, cost;
  Edge(int u, int v, int c, int f, int w): from(u), to(v), cap(c), flow(f), cost(w);
  {}
};

struct MCMF
{
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  int inq[maxn];
  int d[maxn];
  int p[maxn];
  int a[maxn];
  
  void init(init n)
	{
  	this->n = n;
  	for (int i = 0; i < n; i++) G[i].clear();
  	edges.clear();
	}
};

void AddEdge(int from, int to, int cap, int cost)
{
  edges.push_back(Edge(from, to, cap, 0, cost));
  edges.push_back(Edge(to, from, 0, 0, -cost));
  m = edges.size();
  G[from].push_back(m - 2);
  G[to].push_back(m - 1);
}

bool spfa(int s, int t, int &flow, long long &cost)
{
  for (int i = 0; i < n; i++) d[i] = INF;
  memset(inq, 0, sizeof(inq));
  d[s] = 0;
  inq[s] = 1;
  p[s] = 0;
  a[s] = INF;
  
  queue<int> Q;
  Q.push(s);
  while (!Q.empty())
  {
    int u = Q.front();
    Q.pop();
    inq[u] = 0;
    for (int i = 0; i < G[u].size(); i++)
    {
      Edge &e = edges[G[u][i]];
      if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
      {
        d[e.to] = d[u] + e.cost;
        p[e.to] = G[u][i];
        a[e.to] = min(a[u], e.cap - e.flow);
        if (!inq[e.to])
        {
          Q.push(e.to);
          inq[e.to] = 1;
        }
      }
    }
  }
  if (d[t] == INF) return false;
  flow += a[t];
  cost += (long long)d[t] * (long long)a[t];
  for (int u = t; u != s; u = edges[p[u]].from)
  {
    edges[p[u]].flow += a[t];
    edges[p[u]^1].flow -= a[t];
  }
}
  
int MincostMaxflow(int s, int t, long long &cost)
{
  int flow = 0, cost = 0;
  while (BellmanFord(s, t, flow, cost));
  return flow;
}
```



# 二分图匹配



## 匈牙利算法

```c++
#include <cstdio>
#include <cstring>
using namespace std;
int match[501];	// match[i] is the match for i
int n, m, s;
bool mp[401][401];	// mp[i][j] == true shows there is an edge between i and j
bool chw[501];

bool find(int x)
{
  for (int j = 1; j <= m; j++)
  {
    if (mp[x][j])
    {
      if (chw[j])
      {
        chw[j] = false;
        if (match[j] == 0 || find(match[j]))
        {
          match[j] = x;
          return true;
        }
      }
    }
  }
  return false;
}

int main()
{
  scanf("%d%d", &n, &m);
  memset(mp, false, sizeof(mp));
  for (int i = 1; i <= n; i++)
  {
    int kk, y;
    scanf("%d", &kk);
    for (int j = 1; j <= kk; j++)
    {
      scanf("%d", &y);
      mp[i][y] = true;
    }
  }
  ans = 0;
  memset(match, 0, sizeof(match));
  for (int i = 1; i <= n; i++)
  {
    memset(chw, true, sizeof(chw));
    if (find(i)) ans++;
  }
  printf("%d\n", ans);
  for (int i = 1; i <= m; i++)
  {
    if (match[i] > 0) printf("%d %d", match[i], i);
  }
  return 0;
}
```

