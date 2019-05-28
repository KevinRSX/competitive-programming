#include <cstdio>
typedef long long ll;
int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, m;
  int kase = 0;
  while (~scanf("%d%d", &n, &m) && n && m)
  {
    ll ans = (ll)((ll)n * (ll)m * (ll)(n - 1) * (ll)(m - 1) / 4);
    printf("Case %d: %lld\n", ++kase, ans);
  }
  return 0;
}
