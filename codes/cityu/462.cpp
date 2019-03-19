#include <cstdio>
#include <cstring>
#define maxn 1000001
#define maxm 500000

bool isprime[maxn];
int primelist[maxm];
int cnt = 0;

void eratos()
{
  for (int i = 0; i < maxn; i++)
  {
    isprime[i] = true;
  }
  isprime[0] = isprime[1] = false;
  for (int i = 2; i < maxn; i++)
  {
    if (isprime[i])
    {
      primelist[cnt++] = i;
    }
    for (int j = 0; j < cnt && i * primelist[j] < maxn; j++)
    {
      isprime[i * primelist[j]] = false;
      if (i % primelist[j] == 0) break;
    }
  }
}

bool isPrime(int n)
{
  if (n < maxn) return isprime[n];
  else
  {
    for (int i = 0; i < cnt && primelist[i] * primelist[i] <= n; i++)
    {
      if (n % primelist[i] == 0) return false;
    }
  }
  return true;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  eratos();
  int a;
  while (~scanf("%d", &a))
  {
    if (a < 5)
    {
      printf("%d is not the sum of two primes!\n", a);
    }
    else
    {
      if (a & 1)
      {
        if (isPrime(a - 2))
        {
          printf("%d is the sum of %d and %d.\n", a, 2, a - 2);
        }
        else
        {
          printf("%d is not the sum of two primes!\n", a);
        }
      }
      else
      {
        int c = a / 2 - 1;
        while ((!isPrime(c) || !isPrime(a - c)) && c >= 2)
        {
          c--;
        }
        if (c >= 2)
        {
          printf("%d is the sum of %d and %d.\n", a, c, a - c);
        }
        else
        {
          printf("%d is not the sum of two primes!\n", a);
        }
      }
    }
  }
}
