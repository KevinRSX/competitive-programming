#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define maxn 50 + 5
#define INF 0x3f3f3f3f
using namespace std;

int dp[2][maxn][maxn]; // 0 -- Y, 1 -- M

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int m;
  while (~scanf("%d\n", &m) && m)
  {
    int n = 0;
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < m; i++)
    {
      char buf[4];
      int d;
      scanf("%c %c %c %c %d\n", &buf[0], &buf[1], &buf[2], &buf[3], &d);
      n = max(n, max(buf[2] - 'A' + 1, buf[3] - 'A' + 1));
      if (buf[0] == 'Y')
      {
        int source = buf[2] - 'A', dest = buf[3] - 'A';
        dp[0][source][dest] = min(d, dp[0][source][dest]);
        if (buf[1] == 'B') dp[0][dest][source] = min(d, dp[0][dest][source]);
      }
      else
      {
        if (buf[0] == 'M')
        {
          int source = buf[2] - 'A', dest = buf[3] - 'A';
          dp[1][source][dest] = min(d, dp[1][source][dest]);
          if (buf[1] == 'B') dp[1][dest][source] = min(d, dp[1][dest][source]);
        }
      }
    }
    for (int i = 0; i < n; i++)
    {
      dp[0][i][i] = dp[1][i][i] = 0;
    }
    for (int p = 0; p <= 1; p++)
    {
      for (int k = 0; k < n; k++)
      {
        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < n; j++)
          {
            dp[p][i][j] = min(dp[p][i][j], dp[p][i][k] + dp[p][k][j]);
          }
        }
      }
    }
    char s, d;
    scanf("%c %c\n", &s, &d);
    vector<char> meets;
    int mind = INF;
    for (int i = 0; i < n; i++)
    {
      int dist = dp[0][s - 'A'][i] + dp[1][d - 'A'][i];
      if (dist < mind)
      {
        meets.clear();
        meets.push_back((char)(i + 'A'));
        mind = dist;
      }
      else if (dist == mind)
      {
        meets.push_back((char)(i + 'A'));
      }
    }
    if (mind == INF) printf("You will never meet.\n");
    else
    {
      printf("%d", mind);
      for (int i = 0; i < meets.size(); i++)
      {
        printf(" %c", meets[i]);
      }
      printf("\n");
    }
  }
}
