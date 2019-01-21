#include <cstdio>

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int n, sum = 0, mark[1005];
    double avg;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &mark[i]);
      sum += mark[i];
    }
    avg = (double)sum / n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (mark[i] > avg) cnt++;
    }
    printf("%.3f%%\n", (double)cnt / n * 100);
  }
}
