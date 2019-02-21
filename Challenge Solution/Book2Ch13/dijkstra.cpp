#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>


#define INF 1000000
using namespace std;

struct edge
{
  int to, nxt, w;
};

edge E[500005];
int head[10005], cnt = 0, dist[10005];
void add_edge(int u, int v, int w)
{
  E[cnt].to = v;
  E[cnt].w = w;
  E[cnt].nxt = head[u];
  head[u] = cnt++;
}

void dijkstra(int src)
{
  set <pair <int, int> > setds;
  for (int i = 0; i < 10005; i++)
  {
    dist[i] = INF;
  }
  setds.insert(make_pair(0, src));
  dist[src] = 0;
  while (!setds.empty())
  {
    pair<int, int> tmp = *(setds.begin());
    setds.erase(setds.begin());
    int u = tmp.second;
    for (int e = head[u]; ~e; e = E[e].nxt)
    {
      int v = E[e].to;
      int w = E[e].w;
      if (dist[v] > dist[u] + w)
      {
        if (dist[v] != INF)
        {
          setds.erase(setds.find(make_pair(dist[v], v)));
        }
        dist[v] = dist[u] + w;
        setds.insert(make_pair(dist[v], v));
      }
    }
  }
}

bool bellman_ford(int n)
{
  bool pos = true;
  for (int i = 0; i < 10005; i++)
  {
    dist[i] = INF;
  }
  dist[0] = 0;
  for (int j = 0; j < n - 1; j++)
  {
    for (int u = 0; u < n; u++)
    {
      for (int e = head[u]; ~e; e = E[e].nxt)
      {
        int v = E[e].to;
        int w = E[e].w;
        if (dist[v] > dist[u] + w)
        {
          dist[v] = dist[u] + w;
        }
      }
    }
  }
  for (int u = 0; u < n; u++)
  {
    for (int e = head[u]; ~e; e = E[e].nxt)
    {
      int v = E[e].to;
      int w = E[e].w;
      if (dist[v] > dist[u] + w)
      {
        pos = false;
      }
    }
  }
  return pos;
}

int main()
{
  freopen("in.txt", "r", stdin);

  memset(head, -1, sizeof(head));

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int v, deg;
    scanf("%d%d", &v, &deg);
    for (int j = 0; j < deg; j++)
    {
      int to, cost;
      scanf("%d%d", &to, &cost);
      add_edge(v, to, cost);
    }
  }

  #ifdef BELL
  if (bellman_ford(n))
  {
    for (int i = 0; i < n; i++)
    {
      printf("%d %d\n", i, dist[i]);
    }
  }
  else
  {
    printf("Exists negative cycle!\n");
  }
  #endif

  #ifdef DIJ
  dijkstra(0);
  for (int i = 0; i < n; i++)
  {
    printf("%d %d\n", i, dist[i]);
  }
  #endif
}
