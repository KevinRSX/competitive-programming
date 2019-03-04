#include <cstdio>
#include <cstdlib>
#include <queue>
#include <utility>
#include <set>
#define maxn 100
#define INFTY 0xffffff
using namespace std;

int G[maxn + 5][maxn + 5], d[maxn + 5], levels[maxn + 5], M, N;
struct monster
{
  int dist, minlv, maxlv, u;
  monster(int d, int m1, int m2, int id)
  {
    dist = d;
    minlv = m1;
    maxlv = m2;
    u = id;
  }
  bool operator<(const monster &m) const
  {
    return dist > m.dist;
  }
};

void dijkstra()
{
  priority_queue<monster> pq;
  for (int i = 0; i <= N; i++)
  {
    d[i] = INFTY;
  }
  d[N] = 0;
  for (int i = 0; i < N; i++)
  {
    if (G[N][i] >= 0)
    {
      monster tmp(G[N][i], levels[i], levels[i], i);
      pq.push(tmp);
      d[i] = G[N][i];
    }
  }
  while (!pq.empty())
  {
    monster tmp = pq.top();
    pq.pop();
    int maxlv = tmp.maxlv, minlv = tmp.minlv;
    int u = tmp.u;
    if (u == 0)
    {
      printf("%d\n", tmp.dist);
      break;
    }
    for (int i = 0; i <= N; i++)
    {
      if (G[u][i] >= 0 && maxlv - levels[i] <= M && levels[i] - minlv <= M)
      {
        if (d[i] > tmp.dist + G[u][i])
        {
          monster another(tmp.dist + G[u][i], minlv, maxlv, i);
          if (levels[i] > maxlv) another.maxlv = levels[i];
          if (levels[i] < minlv) another.minlv = levels[i];
          pq.push(another);
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
  while (~scanf("%d%d", &M, &N))
  {
    for (int i = 0; i < maxn + 5; i++)
    {
      for (int j = 0; j < maxn + 5; j++)
      {
        G[i][j] = -1;
      }
    }
    for (int i = 0; i < N; i++)
    {
      int p, l, x;
      scanf("%d%d%d", &p, &l, &x);
      G[N][i] = p;
      levels[i] = l;
      for (int j = 0; j < x; j++)
      {
        int t, v;
        scanf("%d%d", &t, &v);
        G[t - 1][i] = v;
      }
    }
    levels[N] = -1;
    dijkstra();
  }
  return 0;
}
