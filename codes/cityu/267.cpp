#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX 105
int idx[MAX][MAX], m, n, k;
int map[MAX][MAX];

int dfs(int r, int c)
{
  if (r < 0 || r >= m || c < 0 || c >= n) return 0;
  if (idx[r][c] > 0 || map[r][c] == 0) return 0;
  idx[r][c] = 1;
  return 1 + dfs(r - 1, c) + dfs(r, c - 1) \
   + dfs(r, c + 1) + dfs(r + 1, c);
}

int main()
{
  while (~scanf("%d%d%d", &m, &n, &k))
  {
    memset(map, 0, sizeof(map));
    memset(idx, 0, sizeof(idx));
    for (int i = 0; i < k; i++)
    {
      int x, y;
      scanf("%d%d", &x, &y);
      map[x - 1][y - 1] = 1;
    }
    int res = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (idx[i][j] == 0 && map[i][j] == 1)
        {
          int t_res = dfs(i, j);
          if (t_res > res)
          {
            res = t_res;
          }
        }
      }
    }
    printf("%d\n", res);
  }
}
