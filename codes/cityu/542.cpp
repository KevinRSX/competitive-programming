#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 18000 + 5
#define maxt 100 + 5
int overlap[maxn];

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  while (1)
  {
    int t = 0, traffic[maxt];
    int mint = 0;
    while (~scanf("%d", &traffic[t]))
    {
      if (!traffic[t]) break;
      else
      {
        if (traffic[t] < traffic[mint]) mint = t;
        t++;
      }
    }
    if (traffic[0] == 0) break;
    memset(overlap, 0, sizeof(overlap));
    for (int i = 0; i < t; i++)
    {
      int start = (i == mint) ? traffic[i] * 2 : 0;
      int gap = traffic[i] + 5, green = start;
      for (int j = start; j <= 18000; j += gap)
      {
        while (j <= green + traffic[i] - 6)
        {
          overlap[j]++;
          j++;
        }
        green += traffic[i] * 2;
      }
    }
    int syn = -1;
    int m = overlap[0];
    for (int i = 0; i <= 18000; i++)
    {
      m = overlap[i] > m ? overlap[i] : m;
      if (overlap[i] == t)
      {
        syn = i;
        break;
      }
    }
    if (syn == -1) printf("Signals fail to synchronise in 5 hours\n");
    else
    {
      int sec = syn % 60;
      int minute = (syn % 3600) / 60;
      int hour = syn / 3600;
      printf("%02d:%02d:%02d\n", hour, minute, sec);
    }
  }
}
