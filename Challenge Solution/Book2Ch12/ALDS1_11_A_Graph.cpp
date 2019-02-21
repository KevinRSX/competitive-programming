#include <cstdio>
#include <cstring>
int g[101][101];

int main()
{
  memset(g, 0, sizeof(g));
  int n;
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
    printf("%d", g[i][0]);
    for (int j = 1; j < n; j++)
    {
      printf(" %d", g[i][j]);
    }
    printf("\n");
  }
}
