#include <cstdio>
#include <algorithm>
#define N 100
using namespace std;

int main()
{
  int m[N + 1][N + 1], p[N + 1], n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &p[i], &p[i + 1]);
  }

  for (int i = 1; i <= n; i++) m[i][i] = 0;
  for (int l = 2; l <= n; l++)
  {
    for (int i = 1; i <= n - l + 1; i++)
    {
      int j = i + l - 1;
      m[i][j] = 1 << 21;
      for (int k = i; k <= j - 1; k++)
      {
        m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
      }
    }
  }
  printf("%d\n", m[1][n]);
  return 0;
}
