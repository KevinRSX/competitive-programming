#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
bool vis[10001] = { 0 };
int n, m, l, cnt;
vector<int> g[10001];

void dfs(int c)
{
  if (vis[c]) return;
  vis[c] = true;
  cnt++;
  for (int i = 0; i < g[c].size(); i++)
  {
    if (!vis[g[c][i]]) dfs(g[c][i]);
  }
}

int main()
{
  freopen("in.txt", "r", stdin);
  int T;
  scanf("%d", &T);
  while (T--)
  {
    memset(vis, false, sizeof(vis));
    cnt = 0;
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 0; i <= 10001; i++)
    {
      g[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
      int x, y;
      scanf("%d%d", &x, &y);
      g[x].push_back(y);
    }
    //for (int i = 0; i < 2; i++) printf("%d\n", g[1][i]);
    for (int i = 0; i < l; i++)
    {
      int p;
      scanf("%d", &p);
      dfs(p);
    }
    printf("%d\n", cnt);
  }
  return 0;
}
