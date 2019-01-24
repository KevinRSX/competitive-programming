#include <cstdio>

int g[21][21];

int main()
{
  int n, kase = 1;
  while (~scanf("%d", &n))
  {
    for (int i = 0; i < 21; i++)
    {
      for (int j = 0; j < 21; j++)
      {
        g[i][j] = 10000;
      }
    }
    for (int i = 0; i < n; i++)
    {
      int tmp;
      scanf("%d", &tmp);
      g[1][tmp] = g[tmp][1] = 1;
    }
    for (int i = 2; i < 20; i++)
    {
      scanf("%d", &n);
      for (int j = 0; j < n; j++)
      {
        int tmp;
        scanf("%d", &tmp);
        g[i][tmp] = g[tmp][i] = 1;
      }
    }

    for (int k = 0; k <= 20; k++)
      for (int i = 0; i <= 20; i++)
        for (int j = 0; j <= 20; j++)
          if (g[i][k] + g[k][j] < g[i][j])
            g[i][j] = g[i][k] + g[k][j];

    int T;
    scanf("%d", &T);
    printf("Test Set #%d\n", kase++);
    while (T--)
    {
      int p1, p2;
      scanf("%d%d", &p1, &p2);
      printf("%2d to %2d: %d\n", p1, p2, g[p1][p2]);
    }
    printf("\n");
  }
}
