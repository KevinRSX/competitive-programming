#include <cstdio>
#include <cstring>
int g[101][101], d[101], f[101], vis[101];
int time = 0, n;

void dfs(int u)
{
  if (vis[u] != 0) return;
  vis[u] = 1;
  d[u] = ++time;
  for (int i = 0; i < n; i++)
  {
    if (g[u][i] == 1)
    {
      dfs(i);
    }
  }
  vis[u] = 2;
  f[u] = ++time;
}

int main()
{
  memset(g, 0, sizeof(g));
  memset(vis, 0, sizeof(vis));
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
  for (int i = 0; i < n; i++)
  {
    if (!vis[i]) dfs(i);
  }
  for (int i = 0; i < n; i++)
  {
    printf("%d %d %d\n", i + 1, d[i], f[i]);
  }
}
