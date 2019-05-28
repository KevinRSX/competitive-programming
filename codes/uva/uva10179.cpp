#include <cstdio>
#include <cstring>
#include <cassert>
#define maxn 50000
#define INF 0x3f3f3f3f

bool flag[maxn];
int prime[maxn], close[2], dist[2];
int cnt = 0;
void getprime(int n)
{
  memset(flag, true, sizeof(flag));
  flag[0] = flag[1] = false;
  for (int i = 2; i <= n; i++)
  {
    if (flag[i]) prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
    {
      flag[i * prime[j]] = false;
      if (i % prime[j] == 0) break;
    }
  }
}

bool isprime(int n)
{
  if (n < maxn - 5) return flag[n];
  for (int i = 1; i < cnt && prime[i] * prime[i] <= n; i++)
  {
    if (n % prime[i] == 0) return false;
  }
  return true;
}

int main()
{
  getprime(maxn);
  int n;
  while (~scanf("%d", &n) && n)
  {
    int res = n, m = n;
    for (int i = 1; i < cnt && m > 1; i++)
    {
      if (m % prime[i] == 0)
      {
        res = res / (prime[i]) * (prime[i] - 1);
        while (m % prime[i] == 0)
        {
          m /= prime[i];
        }
      }
    }
    if (m > 1) res = res / m * (m - 1);
    printf("%d\n", res);
  }
  return 0;
}
