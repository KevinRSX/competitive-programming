#include <cstdio>
#include <algorithm>
#include <cstring>

int primelist[200000];
bool isprime[1000500];

void getprime(int n)
{
  memset(isprime, true, sizeof(isprime));
  int cnt = 0;
  for (int i = 2; i <= n; i++)
  {
    if (isprime[i])
    {
      primelist[cnt++] = i;
    }
    for (int j = 0; j <= cnt && i * primelist[j] <= n; j++)
    {
      isprime[i * primelist[j]] = false;
      if (i % primelist[j] == 0) break;
    }
  }
}

int fac(int r)
{
  int sum = 0, cur = 0;
  for (int i = 0; primelist[i] <= r; i++)
  {
    if (r % primelist[i] == 0)
    {
      while (r % primelist[i] == 0)
      {
        r /= primelist[i];
      }
      cur = i;
      sum += primelist[i];
    }
  }
  sum -= primelist[cur];
  return primelist[cur] - sum;
}

int main()
{
  getprime(1000400);
  int a, b;
  while (~scanf("%d%d", &a, &b) && a != 0 && b != 0)
  {
    int ka = fac(a), kb = fac(b);
    if (ka > kb)
    {
      printf("a\n");
    }
    else
    {
      printf("b\n");
    }
  }
  return 0;
}
