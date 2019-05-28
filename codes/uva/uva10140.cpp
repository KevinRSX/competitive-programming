// This solution is wrong!
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
    assert(prime[i] != 0);
    if (n % prime[i] == 0) return false;
  }
  return true;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  getprime(maxn - 5);
  int a, b;
  while (~scanf("%d%d", &a, &b))
  {
    int temp, maxp = 0, minp = INF;
    bool first = true;
    for (int i = a; i <= b && i > 0; i++)
    {
      if (isprime(i))
      {
        if (first)
        {
          temp = i;
          first = false;
          continue;
        }
        if (i - temp < minp)
        {
          close[0] = temp;
          close[1] = i;
          minp = i - temp;
        }
        if (i - temp > maxp)
        {
          dist[0] = temp;
          dist[1] = i;
          maxp = i - temp;
        }
        temp = i;
      }
    }
    if (maxp == 0 && minp == INF)
    {
      printf("There are no adjacent primes.\n");
    }
    else
    {
      printf("%d,%d are closest, %d,%d are most distant.\n", close[0], close[1], dist[0], dist[1]);
    }
  }
  return 0;
}
