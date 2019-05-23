#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#define maxn 40000
using namespace std;

int prime[maxn];
bool flag[maxn];
vector<int> factors;

void getprime(int n)
{
  memset(flag, true, sizeof(flag));
  int cnt = 0;
  for (int i = 2; i <= n; i++)
  {
    if (flag[i])
      prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
    {
      flag[i * prime[j]] = false;
      if (i % prime[j] == 0) break;
    }
  }
}

void getfactors(int n)
{
  if (n == 1) return;
  int f = -1;
  for (int i = 1; prime[i] * prime[i] <= n; i++)
  {
    if (n % prime[i] == 0)
    {
      f = prime[i];
      break;
    }
  }
  if (f == -1)
  {
    factors.push_back(n);
  }
  else
  {
    factors.push_back(f);
    getfactors(n / f);
  }
}

int digitsum(int n)
{
  if (n < 10) return n;
  return (n % 10) + digitsum(n / 10);
}

int main()
{
  getprime(maxn);
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int p;
    scanf("%d", &p);
    for (int j = p + 1; true; j++)
    {
      factors.clear();
      getfactors(j);
      if (factors[0] == j) continue;
      int dsp = digitsum(j);
      int dsf = 0;
      for (int i = 0; i < factors.size(); i++)
      {
        dsf += digitsum(factors[i]);
      }
      if (dsp == dsf)
      {
        printf("%d\n", j);
        break;
      }
    }
  }
  return 0;
}
