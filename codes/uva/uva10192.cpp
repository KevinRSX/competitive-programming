#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 100 + 5
using namespace std;

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  char a[maxn], b[maxn];
  int kase = 0;
  while (cin.getline(a + 1, maxn) && a[1] != '#')
  {
    cin.getline(b + 1, maxn);
    int dp[maxn][maxn];
    memset(dp, 0, sizeof(dp));
    int len1 = strlen(a + 1), len2 = strlen(b + 1);
    for (int i = 1; i <= len1; i++)
    {
      for (int j = 1; j <= len2; j++)
      {
        if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    printf("Case #%d: you can visit at most %d cities.\n", ++kase, dp[len1][len2]);
  }
}
