#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define maxn 255
#define INF 0x3f3f3f3f
#define N 15
#define M 30

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
  #endif
  int T, kase = 0;
  scanf("%d", &T);
  while (T--)
  {
    ek.init(maxn);
    int type[N][M];
    int n, m;
    scanf("%d%d", &n, &m);
    memset(type, 0, sizeof(type));
    int s = 0, t = maxn - 1;
    for (int i = 0; i < n; i++)
    {
      int num;
      scanf("%d", &num);
      for (int j = 0; j < num; j++)
      {
        int temp;
        scanf("%d", &temp);
        type[i][temp]++;
      }
    }
    for (int i = 1; i <= m; i++)
    {
      ek.addEdge(s, i, type[0][i]);
      ek.addEdge(i, t, 1);
    }
    for (int i = 1; i < n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (type[i][j] == 0)
        {
          ek.addEdge(j, i + m, 1);
        }
        else if (type[i][j] > 1)
        {
          ek.addEdge(i + m, j, type[i][j] - 1);
        }
      }
    }
    int res = ek.MaxFlow(s, t);
    printf("Case #%d: %d\n", ++kase, res);
  }
  return 0;
}
