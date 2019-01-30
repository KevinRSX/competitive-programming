#include <cstdio>

int sol[110][10], col[9], cnt = 0;
bool dup_row[9] = {0}, dup_right[15] = {0}, dup_left[15] = {0};

void dfs(int c)
{
  if (c == 9)
  {
    for (int i = 1; i <= 8; i++)
    {
      sol[cnt][i] = col[i];
    }
    cnt++;
  }

  for (int r = 1; r <= 8; r++)
  {
    int dia_left = c + r - 2, dia_right = c - r + 7;
    if (!dup_row[r] && !dup_right[dia_right] && !dup_left[dia_left])
    {
      dup_row[r] = dup_right[dia_right] = dup_left[dia_left] = true;
      col[c] = r;
      dfs(c + 1);
      dup_row[r] = dup_right[dia_right] = dup_left[dia_left] = false;
    }
  }
}

int main()
{
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  dfs(1);
  int T;
  scanf("%d", &T);
  while (T--)
  {
    printf("SOLN       COLUMN\n");
    printf(" #     ");
    for (int i = 1; i <= 8; i++) printf("%2d", i);
    printf("\n\n");
    int a, b;
    scanf("%d%d", &a, &b);
    int sol_num = 1;
    for (int i = 0; i < cnt; i++)
    {
      if (sol[i][b] == a)
      {
        printf("%2d     ", sol_num++);
        for (int j = 1; j <= 8; j++) printf("%2d", sol[i][j]);
        printf("\n");
      }
    }
    if (T > 0) printf("\n");
  }
  return 0;
}
