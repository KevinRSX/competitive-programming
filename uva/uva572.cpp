#include <cstdio>
#include <cstring>

const int maxn = 105;
char pic[maxn][maxn];
int m, n, idx[maxn][maxn];

void dfs(int r, int c, int id)
{
  if (r < 0 || r >= m || c < 0 || c >= n) return;
  if (idx[r][c] > 0 || pic[r][c] != '@') return;
  idx[r][c] = id;
  dfs(r - 1, c - 1, id);
  dfs(r - 1, c, id);
  dfs(r - 1, c + 1, id);
  dfs(r, c - 1, id);
  dfs(r, c + 1, id);
  dfs(r + 1, c - 1, id);
  dfs(r + 1, c, id);
  dfs(r + 1, c + 1, id);
}

int main()
{
  while (scanf("%d%d", &m, &n) == 2 && m != 0 && n != 0)
  {
    //getchar();
    for (int i = 0; i < m; i++)
    {
      scanf("%s", pic[i]);
    }
    memset(idx, 0, sizeof(idx));
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (idx[i][j] == 0 && pic[i][j] == '@')
        {
          dfs(i, j, ++cnt);
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
