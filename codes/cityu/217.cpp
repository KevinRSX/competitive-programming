#include <cstdio>

int main()
{
  int coin[5] = { 50, 25, 10, 5, 1 };
  int dp[7490] = {0};
  dp[0] = 1;
  for (int i = 0; i < 5; i++)
  {
    for (int j = coin[i]; j <= 7490; j++)
    {
      dp[j] = dp[j - coin[i]] + dp[j];
    }
  }
  int a;
  while (~scanf("%d", &a))
  {
    printf("%d\n", dp[a]);
  }
}
