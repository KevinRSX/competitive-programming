#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
int g[101][101], d[101];
bool vis[101];
int dis = 0, n;

void bfs(int u)
{
  queue<int> Q;
  Q.push(u);
  vis[u] = true;
  d[u] = 0;
  while (!Q.empty())
  {
    int tmp = Q.front();
    Q.pop();
    for (int i = 0; i < n; i++)
    {
      if (g[tmp][i] != 0 && !vis[i])
      {
        vis[i] = true;
        Q.push(i);
        d[i] = d[tmp] + 1;
      }
    }
  }
}

int main()
{
  memset(g, 0, sizeof(g));
  memset(d, -1, sizeof(d));
  memset(vis, false, sizeof(vis));
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int u, adj_num;
    scanf("%d%d", &u, &adj_num);
    while (adj_num--)
    {
      int v;
      scanf("%d", &v);
      g[u - 1][v - 1] = 1;
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
  {
    printf("%d %d\n", i + 1, d[i]);
  }
}
