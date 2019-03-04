#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define maxn 1000
#define INFTY 0x3f3f3f3f
using namespace std;
// not ac
struct trap
{
  char type;
  int n;
  trap() {}
  trap(char t, int num)
  {
    type = t;
    n = num;
  }
};

struct node
{
  int dist, id, pos;
  node(int d, int i, int p)
  {
    dist = d;
    id = i;
    pos = p;
  }
  bool operator<(const node &another) const
  {
    return dist > another.dist;
  }
};

trap all_traps[maxn + 5];
int dist[maxn + 5][15], G[maxn + 5][maxn + 5];
int n;

int trigger(int pos, int i)
{
  char type = all_traps[i].type;
  int v = all_traps[i].n;
  switch (type)
  {
    case '+': pos += v; break;
    case '-': pos -= v; break;
    case '*': pos *= v; break;
    case '=': pos = v; break;
    default: return pos;
  }
  if (pos > 12) pos %= 12;
  while (pos <= 0) pos += 12;
  return pos;
}

bool dijsktra(int start, int end, int init_pos, int open_pos)
{
  memset(dist,0x3f,sizeof(dist));
    printf("%d\n",dist[0][0]);
  priority_queue<node> pq;
  dist[start][init_pos] = 0;
  pq.push(node(0, start, init_pos));
  while (!pq.empty())
  {
    node tmp = pq.top();
    pq.pop();
    int pos = tmp.pos;
    int p = tmp.id;
    if (pos == open_pos && p == end)
    {
      printf("%d\n", dist[p][open_pos]);
      return true;
    }
    for (int i = 0; i <= n; i++)
    {
      int changed = trigger(pos, i);
      if (G[p][i] >= 0 && dist[i][changed] > dist[p][pos] + G[p][i])
      {
        dist[i][changed] = dist[p][pos] + G[p][i];
        pq.push(node(dist[i][changed], i, changed));
      }
    }
  }
  return false;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int edgenum, trapnum, entrance, pos, treasure, open_pos;
  while (~scanf("%d%d%d%d%d%d%d", &n, &edgenum, &trapnum, &entrance, &pos, &treasure, &open_pos))
  {
    memset(G, -1, sizeof G);
    for (int i = 0; i < maxn + 5; i++)
    {
      all_traps[i].type = all_traps[i].n = -1;
    }
    for (int i = 0; i < edgenum; i++)
    {
      int x, y, s;
      scanf("%d%d%d", &x, &y, &s);
      G[x][y] = G[y][x] = (G[x][y]==-1?s:min(G[x][y],s));
    }
    for (int i = 0; i < trapnum; i++)
    {
      int p, move;
      char t;
      scanf("%d %c %d", &p, &t, &move);
      all_traps[p].type = t;
      all_traps[p].n = move;
    }
    if (!dijsktra(entrance, treasure, pos, open_pos))
    {
      printf("Pray!\n");
    }
  }
  return 0;
}
