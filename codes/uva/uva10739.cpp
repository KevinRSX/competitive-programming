#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000 + 5
using namespace std;

char str[maxn];
int dp[maxn][maxn];
bool vis[maxn][maxn];

int minop(int start, int end)
{
  if (vis[start][end]) return dp[start][end];
  if (start >= end)
  {
    dp[start][end] = 0;
    vis[start][end] = true;
    return 0;
  }
  if (str[start] == str[end])
  {
    dp[start][end] = minop(start + 1, end - 1);
    vis[start][end] = true;
  }
  else
  {
    dp[start][end] = 1 + min(minop(start + 1, end - 1), min(minop(start + 1, end), minop(start, end - 1)));
    vis[start][end] = true;
  }
  return dp[start][end];
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  int kase = 0;
  while (T--)
  {
    scanf("%s", str);
    memset(vis, 0, sizeof(vis));
    printf("Case %d: %d\n", ++kase, minop(0, strlen(str) - 1));
  }
}
