#include <cstdio>
#include <algorithm>
#define MAXN 5000001
#define RADIX 1024
using namespace std;

int F[MAXN];

void storeF(int n, int Q)
{
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    F[i] = (F[i - 1] + F[i - 2]) % Q;
  }
}

void counting_sort(int exp, int n)
{
  int *temp = new int[n];
  int count[RADIX] = {0};
  for (int i = 0; i < n; i++)
  {
    count[(F[i] / exp) % RADIX]++;
  }
  for (int i = 1; i < RADIX; i++)
  {
    count[i] += count[i - 1];
  }
  for (int i = n - 1; i >= 0; i--)
  {
    temp[count[(F[i] / exp) % RADIX] - 1] = F[i];
    count[(F[i] / exp) % RADIX]--;
  }
  for (int i = 0; i < n; i++)
  {
    F[i] = temp[i];
  }
  delete[] temp;
}

void radix_sort(int n)
{
  int mx = *max_element(F, F + n);
  for (int exp = 1; mx / exp > 0; exp *= RADIX)
  {
    counting_sort(exp, n);
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int n, Q;
    scanf("%d%d", &n, &Q);
    storeF(n, Q);
    radix_sort(n + 1);
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
      res += (i * (long long)F[i]) % Q;
      res %= Q;
    }
    printf("%lld\n", res);
  }
  return 0;
}
