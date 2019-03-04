#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define maxn 1000 + 5
using namespace std;

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  char str[maxn];
  int n;
  scanf("%d\n", &n);
  while (n--)
  {
    cin.getline(str, maxn);
    int tot = strlen(str);
    int steps = 0, res;
    for (int i = 0; i < tot; i++)
    {
      steps += min(str[i] - 'A', 26 - (str[i] - 'A'));
    }
    res = steps + tot - 1;
    for (int i = 1; i < tot; i++)
    {
      if (str[i] == 'A')
      {
        int j;
        for (j = i + 1; str[j] == 'A' && j <= tot; j++);
        res = min(res, steps + min(2 * (i - 1) + tot - j, 2 * (tot - j) \
          + (i - 1)));
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
