#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 1000 + 5
#define maxm 25000 + 5

struct edge
{
  int from, to, w;
};

bool cmp(edge e1, edge e2)
{
  return e1.w < e2.w;
}

edge E[maxm];
int u[maxn], n, m;
int used_edge = 0;
vector<int> unused;

int find(int i)
{
  if (u[i] == i) return i;
  return u[i] = find(u[i]);
}

int kruskal()
{
  unused.clear();
  for (int i = 0; i < n; i++) u[i] = i;
  sort(E, E + m, cmp);
  used_edge = 0;
  int cnt = 0, tot = 0;
  for (int i = 0; i < m; i++)
  {
    used_edge++;
    int p1 = E[i].from, p2 = E[i].to;
    int w = E[i].w;
    int t1 = find(p1), t2 = find(p2);
    if (t1 != t2)
    {
      u[t1] = t2;
      cnt++;
      tot += w;
    }
    else
    {
      unused.push_back(w);
    }
    if (cnt == n - 1) return tot;
  }
  if (cnt < n - 1) return -1;
  else return n - 1;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  while (~scanf("%d%d", &n, &m) && (n || m))
  {
    for (int i = 0; i < m; i++)
    {
      int v1, v2, w;
      scanf("%d%d%d", &v1, &v2, &w);
      E[i].from = v1;
      E[i].to = v2;
      E[i].w = w;
    }
    if (m < n - 1)
    {
      printf("\\(^o^)/ pray to god\n");
    }
    else
    {
      int cost = kruskal();
      if (cost < 0)
      {
        printf("\\(^o^)/ pray to god\n");
      }
      else
      {
        printf("Min cost: %d\n", cost);
        for (vector<int>::iterator it = unused.begin(); it != unused.end(); it++)
        {
          printf("%d ", *it);
        }
        for (int i = used_edge; i < m; i++)
        {
          printf("%d", E[i].w);
          if (i < m - 1) printf(" ");
        }
        printf("\n");
      }
    }
  }
  return 0;
}
