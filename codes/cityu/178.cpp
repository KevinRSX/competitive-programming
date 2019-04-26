#include <cstdio>
#include <cstring>
#define maxn 1000 + 5

int n, k[25], match[maxn];
bool bg[maxn][maxn];
bool chw[maxn];
int nk, np;

bool find(int x)
{
  for (int j = 1; j <= np; j++)
  {
    if (chw[j] && bg[x][j])
    {
      chw[j] = false;
      if (match[j] == 0 || find(match[j]))
      {
        match[j] = x;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  while (~scanf("%d%d", &nk, &np) && (nk || np))
  {
    memset(bg, 0, sizeof(bg));
    k[0] = 0;
    for (int i = 1; i <= nk; i++)
    {
      scanf("%d", &k[i]);
    }
    for (int i = 1; i <= nk; i++)
    {
      k[i] += k[i - 1];
    }
    n = k[nk];
    for (int i = 1; i <= np; i++)
    {
      int num;
      scanf("%d", &num);
      for (int j = 0; j < num; j++)
      {
        int cat;
        scanf("%d", &cat);
        for (int p = k[cat - 1] + 1; p <= k[cat]; p++)
        {
          bg[p][i] = true;
        }
      }
    }

    memset(match, 0, sizeof(match));
    bool ans = true;
    for (int i = 1; i <= n; i++)
    {
      memset(chw, true, sizeof(chw));
      if (!find(i))
      {
        ans = false;
        break;
      }
    }
    if (!ans) printf("0\n");
    else printf("1\n");
  }
}
