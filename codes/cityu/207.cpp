#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <set>
#include <utility>
#define maxn 200
#define INFTY 0xffffff
using namespace std;

char places[maxn + 1][20];
int G[maxn + 1][maxn + 1], p[2][maxn + 1], d[2][maxn], n;

void dijkstra(int s, int dim)
{
  set< pair<int, int> > S;
  for (int i = 0; i < maxn; i++)
  {
    d[dim][i] = INFTY;
    p[dim][i] = -1;
  }
  d[dim][s] = 0;
  S.insert(make_pair(d[dim][s], s));

  while (!S.empty())
  {
    pair<int, int> tmp = *(S.begin());
    S.erase(S.begin());
    int u = tmp.second;
    for (int v = 0; v < n; v++)
    {
      if (G[u][v] >= 0)
      {
        if (d[dim][v] > d[dim][u] + G[u][v])
        {
          d[dim][v] = d[dim][u] + G[u][v];
          p[dim][v] = u;
          S.insert(make_pair(d[dim][v], v));
          // printf("Inserted: %d %d %s\n", d[dim][v], v, places[v]);
        }
      }
    }
  }
}

void print_path(int end, int dim)
{
  if (p[dim][end] == -1)
  {
    if (dim == 0) printf("%s", places[end]);
    return;
  }
  print_path(p[dim][end], dim);
  printf(" -> %s", places[end]);
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int edgenum;
  bool br = false;
  while (~scanf("%d", &n))
  {
    memset(p, -1, sizeof(p));
    for (int i = 0; i < maxn + 1; i++)
    {
      places[i][0] = '\0';
      for (int j = 0; j < maxn + 1; j++)
      {
        G[i][j] = -1;
      }
    }
    getchar();

    char x[20], y[20], buf[100];
    for (int i = 0; i < n; i++)
    {
      cin.getline(places[i], 100);
    }
    scanf("%d", &edgenum);
    getchar();
    int p1, p2;
    for (int i = 0; i < edgenum; i++)
    {
      cin.getline(buf, 100);
      int j;
      for (j = 0; j < strlen(buf) && buf[j] != ':'; j++)
      {
        x[j] = buf[j];
      }
      x[j++] = '\0';
      for (p1 = 0; p1 < n; p1++)
      {
        if (strcmp(x, places[p1]) == 0)
        {
          break;
        }
      }
      bool found = false;
      int yc = 0;
      while (!found)
      {
        for (; j < strlen(buf) && buf[j] != ' '; j++, yc++)
        {
          y[yc] = buf[j];
        }
        y[yc++] = '\0';
        j++;
        for (p2 = 0; p2 < n; p2++)
        {
          if (strcmp(y, places[p2]) == 0)
          {
            found = true;
            break;
          }
        }
        if (found) break;
        y[yc - 1] = ' ';
      }
      char num1[10], num2[10];
      int d1 = -1, d2 = -1;
      bool pfirst = true;
      for (yc = 0; buf[j]; j++)
      {
        if (pfirst && '0' <= buf[j] && buf[j] <= '9')
        {
          num1[yc++] = buf[j];
          if (buf[j + 1] == ' ')
          {
            num1[yc] = '\0';
            d1 = atoi(num1);
            pfirst = false;
            yc = 0;
          }
          else if (buf[j + 1] == '\0')
          {
            num1[yc] = '\0';
            d1 = atoi(num1);
            break;
          }
        }
        else if (!pfirst && '0' <= buf[j] && buf[j] <= '9')
        {
          num2[yc++] = buf[j];
          if (buf[j + 1] == '\0')
          {
            num2[yc] = '\0';
            d2 = atoi(num2);
            break;
          }
        }
      }
      G[p1][p2] = d1;
      if (d2 > 0) G[p2][p1] = d2;
      // printf("G[%d][%d] = %d   G[%d][%d] = %d\n", p1, p2, G[p1][p2], p2, p1, G[p2][p1]);
    }



    for (int i = 0; i < n; i++)
    {
      if (strcmp(places[i], "office") == 0) p1 = i;
      if (strcmp(places[i], "hall") == 0) p2 = i;
    }
    dijkstra(p1, 0);
    dijkstra(p2, 1);
    //if (!br) br = true;
    //else printf("\n");
    printf("%d\n", d[0][p2] + d[1][p1]);
    print_path(p2, 0);
    print_path(p1, 1);
    printf("\n\n");
  }
  return 0;
}
