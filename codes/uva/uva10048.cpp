#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100 + 5
#define maxm 1000 + 5
#define INF 0x3f3f3f3f
using namespace std;

int dp[maxn][maxn];

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int c, s, q;
  int kase = 0;
  while (~scanf("%d%d%d", &c, &s, &q) && (c || s || q))
  {
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < s; i++)
    {
      int from, to, w;
      scanf("%d%d%d", &from, &to, &w);
      dp[from][to] = w;
      dp[to][from] = w;
    }

    for (int k = 1; k <= c; k++)
    {
      for (int i = 1; i <= c; i++)
      {
        for (int j = 1; j <= c; j++)
        {
          dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
        }
      }
    }

    if (kase > 0) printf("\n");
    printf("Case #%d\n", ++kase);
    for (int i = 0; i < q; i++)
    {
      int from, to;
      scanf("%d%d", &from, &to);
      if (dp[from][to] == INF) printf("no path\n");
      else printf("%d\n", dp[from][to]);
    }
  }
  return 0;
}
