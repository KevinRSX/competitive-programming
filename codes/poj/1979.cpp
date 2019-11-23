#include <cstdio>
#include <cstring>
#define maxn 25

int w, h, res;
char g[maxn][maxn];
void dfs(int x, int y)
{
  g[x][y] = '#';
  res++;
  if (x - 1 >= 0 && g[x - 1][y] == '.') dfs(x - 1, y);
  if (x + 1 < h && g[x + 1][y] == '.') dfs(x + 1, y);
  if (y - 1 >= 0 && g[x][y - 1] == '.') dfs(x, y - 1);
  if (y + 1 < w && g[x][y + 1] == '.') dfs(x, y + 1);
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  while (~scanf("%d%d\n", &w, &h) && (w || h))
  {
    int x, y;
    res = 0;
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        scanf("%c", &g[i][j]);
        if (g[i][j] == '@')
        {
          x = i;
          y = j;
        }
      }
      getchar();
    }
    dfs(x, y);
    printf("%d\n", res);
  }
}
