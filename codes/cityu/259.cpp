#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

bool match(char a, char b)
{
  return (a == '(' && b == ')') || (a == '[' && b == ']');
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  char str[105];
  int dp[105][105];
  int T;
  scanf("%d", &T);
  getchar();
  bool pbr = false;
  while (T--)
  {
    if (!pbr) pbr = true;
    else printf("\n");
    char str[105];
    getchar();
    cin.getline(str, 105);
    if (str[0] == '\0') printf("0\n");
    else
    {
      int n = strlen(str);
      for (int i = 0; i < n; i++)
      {
        dp[i + 1][i] = 0;
        dp[i][i] = 1;
      }
      for (int i = n - 2; i >= 0; i--)
      {
        for (int j = i + 1; j < n; j++)
        {
          dp[i][j] = j - i + 1;
          if (match(str[i], str[j])) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
          for (int k = i; k < j; k++)
          {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
          }
        }
      }
      printf("%d\n", n + dp[0][n - 1]);
    }
  }
  return 0;
}
