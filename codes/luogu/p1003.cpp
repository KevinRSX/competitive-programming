#include <cstdio>
#include <cstring>

int buf[10010][4];

int main()
{
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++)
  {
    scanf("%d%d%d%d", &buf[i][0], &buf[i][1], &buf[i][2], &buf[i][3]);
  }
  int x, y;
  scanf("%d%d", &x, &y);
  bool covered = false;
  for (int i = T - 1; i >= 0; i--)
  {
    if (buf[i][0] <= x && x < buf[i][0] + buf[i][2] && buf[i][1] <= y && y < buf[i][1] + buf[i][3])
    {
      covered = true;
      printf("%d\n", i + 1);
      break;
    }
  }
  if (covered == false) printf("-1\n");
  return 0;
}
