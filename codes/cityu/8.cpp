#include <cstdio>
#include <cstring>

int dp[25][25], buf[25][25];  //buf: 1D, 2I, 3C
char s1[25], s2[25];

void print(int i, int j)
{
  if (i == 0 && j == 0) return;
  if (buf[i][j] == 1)
  {
    print(i - 1, j);
    printf("D%c%02d", s1[i - 1], j + 1);
  }
  else if (buf[i][j] == 2)
  {
    print(i, j - 1);
    printf("I%c%02d", s2[j - 1], j);
  }
  else if (buf[i][j] == 3)
  {
    print(i - 1, j - 1);
    printf("C%c%02d", s2[j - 1], j);
  }
  else
  {
    print(i - 1, j - 1);
  }
}

int main()
{
    while (~scanf("%s", s1))
    {
      if (s1[0] == '#')
      {
        break;
      }
      scanf("%s", s2);
      int len1 = strlen(s1), len2 = strlen(s2);
      for (int i = 0; i <= len1; i++)
      {
        for (int j = 0; j <= len2; j++)
        {
          dp[i][j] = 400;
          buf[i][j] = 0;
        }
      }
      for (int i = 0; i <= len1; i++)
      {
        dp[i][0] = i;
        buf[i][0] = 1;
      }
      for (int j = 0; j <= len2; j++)
      {
        dp[0][j] = j;
        buf[0][j] = 2;
      }

      for (int i = 1; i <= len1; i++)
      {
        for (int j = 1; j <= len2; j++)
        {
          if (s1[i - 1] == s2[j - 1])
          {
            dp[i][j] = dp[i - 1][j - 1];
          }
          else
          {
            dp[i][j] = dp[i - 1][j - 1] + 1;
            buf[i][j] = 3;
          }
          if (dp[i - 1][j] + 1 < dp[i][j])
          {
            dp[i][j] = dp[i - 1][j] + 1;
            buf[i][j] = 1;
          }
          if (dp[i][j - 1] + 1 < dp[i][j])
          {
            dp[i][j] = dp[i][j - 1] + 1;
            buf[i][j] = 2;
          }
        }
      }
      print(len1, len2);
      printf("E\n");
    }
    return 0;
}
