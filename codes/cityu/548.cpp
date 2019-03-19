#include <cstdio>

using namespace std;
#define maxn 64 + 1

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  typedef long long ll;
  ll a, b;
  while (~scanf("%lld%lld", &a, &b))
  {
    ll d = a ^ b;
    ll t = 0;
    while (d)
    {
      d >>= 1;
      t <<= 1;
      t++;
    }
    printf("%lld\n", a | t);
  }
  return 0;
}
