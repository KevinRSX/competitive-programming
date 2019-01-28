#include <cstdio>
#include <cstring>

char stage[4][20] = { "SIMPLE", "FULLY-GROWN", "MUTAGENIC", "MUTANT" };
char org[1001];

int dfs(int start, int end)
{
  if (start == end && org[start] == 'A')
  {
    return 0;
  }

  if (org[end] == 'B' && org[end - 1] == 'A')
  {
    int res = dfs(start, end - 2);
    if (res == 3) return res;
    else return 1;
  }
  else if (org[start] == 'B' && org[end] == 'A')
  {
    int res = dfs(start + 1, end - 1);
    if (res == 3) return res;
    else return 2;
  }
  else
  {
    return 3;
  }
}

int main()
{
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%s", org);
    printf("%s\n", stage[dfs(0, strlen(org) - 1)]);
  }
  return 0;
}
