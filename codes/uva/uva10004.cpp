#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define maxn 200 + 5
#define maxm 40000 + 5

struct edge
{
  int next, to, w;
};

int head[maxn], cnt = 0;
edge E[maxm];
int color[maxn];

void addEdge(int from, int to, int w)
{
  E[cnt].w = w;
  E[cnt].to = to;
  E[cnt].next = head[from];
  head[from] = cnt++;
}


bool bfs()
{
  memset(color, -1, sizeof(color));
  queue<int> Q;
  color[0] = 0;
  Q.push(0);
  while (!Q.empty())
  {
    int id = Q.front();
    Q.pop();
    for (int i = head[id]; ~i; i = E[i].next)
    {
      int u = E[i].to;
      if (color[u] == -1)
      {
        bool first = true;
        int c;
        for (int e = head[u]; ~e; e = E[e].next)
        {
          int v = E[e].to;
          if (color[v] == -1) continue;
          else if (first)
          {
            c = color[v];
            first = false;
          }
          else if (color[v] != c)
          {
            return false;
          }
        }
        color[u] = 1 - c;
        Q.push(u);
      }
    }
  }
  return true;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int n, l;
  while (~scanf("%d", &n) && n)
  {
    memset(head, -1, sizeof(head));
    cnt = 0;
    scanf("%d", &l);
    for (int i = 0; i < l; i++)
    {
      int a, b;
      scanf("%d%d", &a, &b);
      addEdge(a, b, 1);
      addEdge(b, a, 1);
    }

    if (bfs())
    {
      printf("BICOLORABLE.\n");
    }
    else
    {
      printf("NOT BICOLORABLE.\n");
    }
  }
  return 0;
}
