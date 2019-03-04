#include <cstdio>
#include <iostream>
#include <cstring>
#define maxn 50 + 5
using namespace std;

int dp[maxn][maxn][maxn][maxn];
char g[maxn][maxn];
int row, col;

int isdonut(int x1, int y1, int x2, int y2)
{
  for (int i = x1; i <= x2; i++)
  {
    if (g[i][y1] == '.' || g[i][y2] == '.') return false;
  }
  for (int i = y1; i <= y2; i++)
  {
    if (g[x1][i] == '.' || g[x2][i] == '.') return false;
  }
  return true;
}

int donutNum(int x1, int y1, int x2, int y2)
{
  if (x2 - x1 < 2 || y2 - y1 < 2) return 0;
  int res = dp[x1][y1][x2][y2];
  if (res >= 0) return res;
  if (isdonut(x1, y1, x2, y2))
  {
    int k5 = donutNum(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
    if (k5 >= res)
    {
      res = 1 + k5;
    }
  }
  else
  {
    int k1 = donutNum(x1 + 1, y1, x2, y2);
    if (k1 > res) res = k1;
    int k2 = donutNum(x1, y1 + 1, x2, y2);
    if (k2 > res) res = k2;
    int k3 = donutNum(x1, y1, x2 - 1, y2);
    if (k3 > res) res = k3;
    int k4 = donutNum(x1, y1, x2, y2 - 1);
    if (k4 > res) res = k4;
  }
  return dp[x1][y1][x2][y2] = res;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    memset(dp, -1, sizeof(dp));
    scanf("%d\n", &row);
    for (int i = 0; i < row; i++)
    {
      cin.getline(g[i], maxn);
    }
    col = strlen(g[0]);
    printf("Case #%d: %d\n", t, donutNum(0, 0, row - 1, col - 1));
  }
  return 0;
}
