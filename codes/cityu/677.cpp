#include <cstdio>

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  double h, u, d, f;
  while (~scanf("%lf%lf%lf%lf", &h, &u, &d, &f))
  {
    double cur = 0;
    int day = 0;
    bool success;
    while (1)
    {
      day++;
      cur += u;
      if (cur >= h)
      {
        success = true;
        break;
      }
      if (u - d < 0)
      {
        success = false;
        day++;
        break;
      }
      cur -= d;
      u *= (f / 100);
    }
    if (success)
    {
      printf("succeeded on day %d\n", day);
    }
    else
    {
      printf("failed on day %d\n", day);
    }
  }
}
