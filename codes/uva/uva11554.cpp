#include <cstdio>
#define maxn 1000005

typedef long long ll;
int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  ll *p = new ll[maxn];
  p[0] = p[1] = p[2] = p[3] = 0;
  for (ll i = 4; i <= maxn; i++)
  {
    p[i] = p[i - 1] + ((i / 2 - 1) * (i / 2) + (i / 2 - 2 + i % 2) * (i / 2 - 1 + i % 2)) / 2;
  }
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int n;
    scanf("%d", &n);
    printf("%lld\n", p[n]);
  }
  return 0;
}
