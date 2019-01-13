#include <cstdio>
#include <cstring>
#include <algorithm>

int parent[30001], tot[30001], n, ans;

int find(int key)
{
  if (key == parent[key]) return key;
  return parent[key] = find(parent[key]);
}

void unionn(int k1, int k2)
{
  int newtot = tot[k2] + tot[k1];
  tot[k2] = newtot;
  if (newtot > ans) ans = newtot;
  parent[k1] = k2;
}

int main()
{
  freopen("in.txt", "r", stdin);
  using namespace std;
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int m;
    ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
      tot[i] = 1;
    }
    while (m--)
    {
      int a, b;
      scanf("%d%d", &a, &b);
      int g1 = find(a), g2 = find(b);
      if (g1 == g2) continue;
      else
      {
        unionn(g1, g2);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
