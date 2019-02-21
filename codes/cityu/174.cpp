#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#define maxn 1000
#define INFTY 0xffffff
using namespace std;

int G[maxn + 5][maxn + 5], cost[maxn + 5], nxt[maxn + 5][maxn + 5];

void floyd(int n)
{
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (G[i][j] > G[i][k] + G[k][j] + cost[k])
        {
          G[i][j] = G[i][k] + G[k][j] + cost[k];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif

  int T;
  scanf("%d", &T);
  cin.get();
  cin.get();
  bool print_flag = false;
  while (T--)
  {
    for (int i = 0; i < maxn + 5; i++)
    {
      for (int j = 0; j < maxn + 5; j++)
      {
        nxt[i][j] = j;
      }
    }
    string buf;
    getline(cin, buf);
    stringstream sc(buf);
    int p, n = 0;
    while (sc >> p)
    {
      G[0][n++] = p;
      if (G[0][n - 1] == -1)
      {
        G[0][n - 1] = INFTY;
      }
    }
    for (int i = 1; i <= n; i++)
    {
      getline(cin, buf);
      stringstream sc(buf);
      for (int j = 0; j < n; j++)
      {
        if (i < n)
        {
          sc >> G[i][j];
          if (G[i][j] == -1) G[i][j] = INFTY;
        }
        else sc >> cost[j];
      }
    }
    floyd(n);
    int a, b;
    getline(cin, buf);
    while (buf != "")
    {
      stringstream sc(buf);
      sc >> a >> b;
      if (print_flag)
      {
        printf("\n");
      }
      else
      {
        print_flag = true;
      }
      printf("From %d to %d :\n", a, b);
      if (a != b)
      {
        printf("Path: %d", a);
        for (int tmp = nxt[a - 1][b - 1]; tmp != b - 1; \
          tmp = nxt[tmp][b - 1])
        {
          printf("-->%d", tmp + 1);
        }
        printf("-->%d\n", b);
      }
      else
      {
        printf("Path: %d\n", a);
      }
      printf("Total cost : %d\n", G[a - 1][b - 1]);
      getline(cin, buf);
    }
  }
  return 0;
}
