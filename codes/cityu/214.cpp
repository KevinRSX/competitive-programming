#include <cstdio>
#include <algorithm>
#include <cstring>

int primelist[100001];
bool isprime[1299710];

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

int main()
{
  using namespace std;
  getprime(1299710);
  int n;
  while (~scanf("%d", &n) && n != 0)
  {
    if (isprime[n]) printf("0\n");
    else
    {
      int i = n + 1, j = n - 1;
      for (; !isprime[i]; i++);
      for (; !isprime[j]; j--);
      printf("%d\n", i - j);
    }
  }
}
