#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int G[35], w[1005], price[1000];
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int n;
    scanf("%d", &n);
    memset(G, 0, sizeof G);
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", &price[i], &w[i]);
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 30; j >= w[i]; j--)
      {
        G[j] = max(G[j], G[j - w[i]] + price[i]);
      }
    }

    int people, res = 0;
    scanf("%d", &people);
    for (int i = 0; i < people; i++)
    {
      int tmp_w;
      scanf("%d", &tmp_w);
      res += G[tmp_w];
    }
    printf("%d\n", res);
  }
}
