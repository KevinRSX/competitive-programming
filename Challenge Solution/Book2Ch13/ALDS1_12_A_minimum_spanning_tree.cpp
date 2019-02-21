#include <cstdio>
#include <cstring>
#define MAXN (1 << 21)
int g[101][101], d[101], n;
bool vis[101];

int mst()
{
  int sum = 0;
  d[0] = 0;
  for (int j = 0; j < n; j++)
  {
    int u = -1;
    int mini = MAXN;
    for (int i = 0; i < n; i++) // take node from V-T to T
    {
      if (d[i] < mini && !vis[i])
      {
        u = i;
        mini = d[i];
      }
    }
    if (u == -1) return -1;
    sum += mini;
    vis[u] = true;
    for (int v = 0; v < n; v++) // update smallest weight
    {
      if (!vis[v] && g[u][v] >= 0 && d[v] > g[u][v])
      {
        d[v] = g[u][v];
      }
    }
  }
  return sum;
}

int main()
{
  memset(vis, false, sizeof(vis));
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    d[i] = MAXN;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &g[i][j]);
    }
  }
  printf("%d\n", mst());
}
