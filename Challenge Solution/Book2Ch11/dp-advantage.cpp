#include <cstdio>
#include <cstring>

int n, A[50], dp[21][2001];

int solve(int i, int m)
{
  if (dp[i][m] != -1)
  {
    return dp[i][m];
  }

  if (m == 0)
    dp[i][m] = 1;
  else if (i >= n)
    dp[i][m] = 0;
  else if (solve(i + 1, m))
    dp[i][m] = 1;
  else if (solve(i + 1, m - A[i]))
    dp[i][m] = 1;
  else
    dp[i][m] = 0;

  return dp[i][m];
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  int q, m;
  scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &m);
    if (solve(0, m) != 0) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}
