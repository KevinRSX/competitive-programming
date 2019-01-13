#include <cstdio>
#include <cstring>
#define MAXN 100001

int a[MAXN], presum[MAXN], mods[MAXN];

int main()
{
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  int c, n;
  while (scanf("%d%d", &c, &n) == 2 && c != 0 && n != 0)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
    }
    memset(mods, -1, sizeof(mods));
    presum[0] = a[0];
    mods[presum[0]] = 1;
    for (int i = 1; i < n; i++)
    {
      presum[i] = (a[i] + presum[i - 1]) % c;
      if (presum[i] == 0)
      {
        for (int j = 1; j < i + 1; j++)
        {
          printf("%d ", j);
        }
        printf("%d\n", i + 1);
        break;
      }
      else if (mods[presum[i]] != -1)
      {
        for (int j = mods[presum[i]] + 1; j < i + 1; j++)
        {
          printf("%d ", j);
        }
        printf("%d\n", i + 1);
        break;
      }
      else
      {
        mods[presum[i]] = i + 1;
      }
    }
  }
  return 0;
}
