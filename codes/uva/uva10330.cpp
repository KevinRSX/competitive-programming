#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define maxn 200 + 5
#define INF 0x3f3f3f3f

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
};

EdmondsKarp ek;
int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n;
  while (~scanf("%d", &n))
  {
    int s = 0, t = 2 * n + 1;
    ek.init(t);
    for (int i = 1; i <= n; i++)
    {
       int cap;
       scanf("%d", &cap);
       ek.addEdge(i, i + n, cap);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
      int from, to, cap;
      scanf("%d%d%d", &from, &to, &cap);
      ek.addEdge(from + n, to, cap);
      //ek.addEdge(to + n, from, cap);
    }
    int link_s, link_t;
    scanf("%d%d", &link_s, &link_t);
    for (int i = 0; i < link_s; i++)
    {
      int in;
      scanf("%d", &in);
      ek.addEdge(s, in, INF);
    }
    for (int i = 0; i < link_t; i++)
    {
      int out;
      scanf("%d", &out);
      ek.addEdge(out + n, t, INF);
    }
    printf("%d\n", ek.MaxFlow(s, t));
  }
}
