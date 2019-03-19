#include <cstdio>
#include <set>
#include <utility>
typedef long long ll;
using namespace std;

int r[50], seat[50];
int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  for (int j = 1; j <= T; j++)
  {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++)
    {
      scanf("%d", &r[i]);
    }
    set< pair<int, int> > occupied;
    for (int i = 0; i < c; i++)
    {
      scanf("%d", &seat[i]);
      if (seat[i] > 1) occupied.insert(make_pair(r[i], seat[i] - 1));
      if (seat[i] < m) occupied.insert(make_pair(r[i], seat[i]));
    }
    printf("Case #%d: %lld\n", j, (ll)((ll)n * (m - 1) - (ll)(occupied.size())));
  }
  return 0;
}
