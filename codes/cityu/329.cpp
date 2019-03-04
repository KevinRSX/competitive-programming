#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 1000 + 5
using namespace std;
int dp[maxn][maxn], n;

void lcs(char a[], char b[], int a_len, int b_len)
{
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < a_len; i++)
  {
    for (int j = 0; j < b_len; j++)
    {
      if (a[i] == b[j])
      {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      }
      else
      {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int n;
  scanf("%d\n", &n);
  while (n--)
  {
    char a[maxn], b[maxn];
    scanf("%s", a);
    scanf("%s", b);
    int a_len = strlen(a), b_len = strlen(b);
    lcs(a, b, a_len, b_len);
    printf("%d\n", a_len + b_len - dp[a_len][a_len]);
  }
  return 0;
}
