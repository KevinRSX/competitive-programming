#include <cstdio>
#include <set>
#include <cstring>
#include <queue>

#define maxn 500
#define INFTY 0xffffff
using namespace std;

struct edge
{
  int w, to, nxt;
};

struct node
{
  int status, dist, u;
  bool operator < (const node &another) const
  {
    return dist > another.dist;
  }
};

edge E[15000];
bool vis[maxn + 5][2];
int head[maxn + 5], edgenum = 0, dist[maxn + 5][2];

void addEdge(int u, int v, int w)
{
  E[edgenum].to = v;
  E[edgenum].w = w;
  E[edgenum].nxt = head[u];
  head[u] = edgenum++;

  E[edgenum].to = u;
  E[edgenum].w = w;
  E[edgenum].nxt = head[v];
  head[v] = edgenum++;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int n, rd, kase = 1;
  while (~scanf("%d%d", &n, &rd))
  {
    for (int i = 0; i < maxn + 5; i++)
    {
      vis[i][0] = vis[i][1] = false;
      dist[i][0] = dist[i][1] = INFTY;
    }
    memset(head, -1, sizeof(head));
    for (int i = 0; i < rd; i++)
    {
      int start, end, weight;
      scanf("%d%d%d", &start, &end, &weight);
      addEdge(start, end, weight);
    }

    priority_queue<node> S;
    dist[0][0] = 0;
    S.push((node){0, 0, 0});
    while (!S.empty())
    {
      node tmp = S.top();
      S.pop();
      int u = tmp.u, ustat = tmp.status;
      for (int e = head[u]; ~e; e = E[e].nxt)
      {
        int v = E[e].to;
        int w = E[e].w;
        if (dist[v][!ustat] > w + dist[u][ustat])
        {
          dist[v][!ustat] = w + dist[u][ustat];
          S.push((node){!ustat, dist[v][!ustat], v});
        }
      }
    }
    printf("Set #%d\n", kase++);
    if (dist[n - 1][0] != INFTY)
    {
      printf("%d\n", dist[n - 1][0]);
    }
    else
    {
      printf("?\n");
    }
  }
  return 0;
}
