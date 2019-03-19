#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

bool isprime[65];
int primelist[50], comlist[50], pcnt = 0, comcnt = 0;
void sieve()
{
  for (int i = 0; i < 65; i++)
  {
    isprime[i] = true;
  }
  isprime[0] = isprime[1] = false;
  for (int i = 2; i < 65; i++)
  {
    if (isprime[i]) primelist[pcnt++] = i;
    else comlist[comcnt++] = i;
    for (int j = 0; j < pcnt && i * primelist[j] < 65; j++)
    {
      isprime[i * primelist[j]] = false;
      if (i % primelist[j] == 0) break;
    }
  }
}
int main()
{
  #ifdef DEBUG
  freopen("out.txt", "w", stdout);
  #endif
  sieve();
  set<ull> s;
  s.insert(1);

  for (ull i = 2; i < (1<<16); i++)
  {
    int pmax = ceil((64 * log(2)) / log(i)) - 1;
    ull res = i * i * i * i;
    s.insert(res);
    for (int j = 1; comlist[j] <= pmax; j++)
    {
      for (int k = 1; k <= comlist[j] - comlist[j - 1]; k++)
      {
        res *= i;
      }
      s.insert(res);
    }
  }
  for (set<ull>::iterator i = s.begin(); i != s.end(); i++)
  {
    printf("%llu\n", *i);
  }
  return 0;
}
