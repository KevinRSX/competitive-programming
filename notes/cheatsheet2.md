Anti brute force lock

```c++
#include <cstdio>
#include <cassert>
#include <algorithm>
#define maxn 500 + 5
#define maxm 250000 + 5
using namespace std;

struct edge
{
  int from, to, w;
};

bool cmp(edge e1, edge e2)
{
  return e1.w < e2.w;
}

int digit_diff(int a, int b)
{
  if (a >= b)
  {
    return min(a - b, b - a + 10);
  }
  else
  {
    return min(b - a, a - b + 10);
  }
}

int pos_diff(int a, int b)
{
  return digit_diff(a % 10, b % 10) + digit_diff((a / 10) % 10, (b / 10) % 10) +\
    digit_diff((a / 100) % 10, (b / 100) % 10) +\
    digit_diff((a / 1000) % 10, (b / 1000) % 10);
}

int nodes[maxn], n, m, u[maxm];
edge E[maxm];

int find(int i)
{
  if (u[i] == i) return i;
  return u[i] = find(u[i]);
}

int kruskal()
{
  for (int i = 0; i < n; i++) u[i] = i;
  sort(E, E + m, cmp);
  int cnt = 0, tot = 0;
  for (int i = 0; i < m; i++)
  {
    int p1 = E[i].from, p2 = E[i].to;
    int w = E[i].w;
    int t1 = find(p1), t2 = find(p2);
    if (t1 != t2)
    {
      u[t1] = t2;
      tot += w;
      cnt++;
    }
    if (cnt == n - 1) return tot;
  }

  assert(cnt >= n-1);
  return tot;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &n);
    int min_dist = 100;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &nodes[i]);
      int tmp_diff = pos_diff(0, nodes[i]);
      if (tmp_diff < min_dist)
      {
        min_dist = tmp_diff;
      }
    }
    m = 0;
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        E[m].from = i;
        E[m].to = j;
        E[m].w = pos_diff(nodes[i], nodes[j]);
        m++;
      }
    }
    printf("%d\n", kruskal() + min_dist);
  }
  return 0;
}
```



The problem with the problem setter

```cpp
#include <cstdio>
#include <cstring>
#define maxn 1000 + 5

int n, k[25], match[maxn];
bool bg[maxn][maxn];
bool chw[maxn];
int nk, np;

bool find(int x)
{
  for (int j = 1; j <= np; j++)
  {
    if (chw[j] && bg[x][j])
    {
      chw[j] = false;
      if (match[j] == 0 || find(match[j]))
      {
        match[j] = x;
        return true;
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
  while (~scanf("%d%d", &nk, &np) && (nk || np))
  {
    memset(bg, 0, sizeof(bg));
    k[0] = 0;
    for (int i = 1; i <= nk; i++)
    {
      scanf("%d", &k[i]);
    }
    for (int i = 1; i <= nk; i++)
    {
      k[i] += k[i - 1];
    }
    n = k[nk];
    for (int i = 1; i <= np; i++)
    {
      int num;
      scanf("%d", &num);
      for (int j = 0; j < num; j++)
      {
        int cat;
        scanf("%d", &cat);
        for (int p = k[cat - 1] + 1; p <= k[cat]; p++)
        {
          bg[p][i] = true;
        }
      }
    }

    memset(match, 0, sizeof(match));
    bool ans = true;
    for (int i = 1; i <= n; i++)
    {
      memset(chw, true, sizeof(chw));
      if (!find(i))
      {
        ans = false;
        break;
      }
    }
    if (!ans) printf("0\n");
    else printf("1\n");
  }
}
```



Winger trial

```cpp
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 200 + 5
#define maxm 40000 + 5
#define INF 0x3f3f3f3f

struct Edge
{
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f) {}
};

struct Point
{
  double x, y;
};

int l, w, n, d;
double dis(Point a, Point b)
{
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct EdmondKarp
{
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  int a[maxn];
  int p[maxn];

  void init(int n)
  {
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void addEdge(int from, int to, int cap)
  {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  int maxFlow(int s, int t)
  {
    int flow = 0;
    for (;;)
    {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = INF;
      while (!Q.empty())
      {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < G[x].size(); i++)
        {
          Edge &e = edges[G[x][i]];
          if (!a[e.to] && e.cap > e.flow)
          {
            p[e.to] = G[x][i];
            a[e.to] = min(a[x], e.cap - e.flow);
            Q.push(e.to);
          }
        }
        if (a[t]) break;
      }
      if (!a[t]) break;
      for (int u = t; u != s; u = edges[p[u]].from)
      {
        edges[p[u]].flow += a[t];
        edges[p[u] ^ 1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }
};

EdmondKarp ek;

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int kase = 0;
  while (~scanf("%d%d%d%d", &l, &w, &n, &d) && (l || w || n || d))
  {
    ek.init(2 * n + 2);
    Point robot[maxn]; // 1...n: in, n+1...2n: out
    // 0: s, 2n+1: t
    for (int i = 1; i <= n; i++)
    {
      scanf("%lf%lf", &robot[i].x, &robot[i].y);
      robot[i + n].x = robot[i].x;
      robot[i + n].y = robot[i].y;
    }
    for (int i = 1; i <= n; i++)
    {
      if (w - robot[i].y <= d)
      {
        ek.addEdge(0, i, INF);
      }
      if (robot[i + n].y <= d)
      {
        ek.addEdge(i + n, 2 * n + 1, INF);
      }
      ek.addEdge(i, i + n, 1);
      for (int j = i + 1; j <= n; j++)
      {
        if (dis(robot[i], robot[j]) <= 2 * d)
        {
          ek.addEdge(i + n, j, INF);
          ek.addEdge(j + n, i, INF);
        }
      }
    }
    printf("Case %d: %d\n", ++kase, ek.maxFlow(0, 2 * n + 1));
  }
  return 0;
}
```



Area

```cpp
double area(Polygon s)
{
  double retval = 0.0;
  for (int i = 0; i < s.size(); i++)
  {
    Vector v1 = s[i], v2 = s[(i + 1) % s.size()];
    retval += 0.5 * cross(v1, v2);
  }
  return retval >= 0 ? retval : -retval;
}
```



Suffix array

```cpp
#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 1005;
using namespace std;
char s[MAXN];
int N, M, rak[MAXN], sa[MAXN], tax[MAXN], tp[MAXN], Height[MAXN];
void GetHeight()
{
    int j, k = 0;
    for(int i = 1; i <= N; i++)
    {
        if(k) k--;
        j = sa[rak[i] - 1];
        while(s[i + k] == s[j + k]) k++;
        Height[rak[i]] = k;
    }
}
void radixsort()
{
    for (int i = 0; i <= M; i++) tax[i] = 0;
    for (int i = 1; i <= N; i++) tax[rak[i]]++;
    for (int i = 1; i <= M; i++) tax[i] += tax[i - 1];
    for (int i = N; i >= 1; i--) sa[ tax[rak[tp[i]]]-- ] = tp[i];
}
void SuffixSort()
{
    M = 75;
    for (int i = 1; i <= N; i++) rak[i] = s[i] - '0' + 1, tp[i] = i;
    radixsort();
    for (int w = 1, p = 0; p < N; M = p, w <<= 1)
    {
        p = 0;
        for (int i = 1; i <= w; i++) tp[++p] = N - w + i;
        for (int i = 1; i <= N; i++) if (sa[i] > w) tp[++p] = sa[i] - w;
        radixsort();
        std::swap(tp, rak);
        rak[sa[1]] = p = 1;
        for (int i = 2; i <= N; i++)
            rak[sa[i]] = (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + w] == tp[sa[i] + w]) ? p : ++p;
    }
}
int main()
{
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    while (n--)
    {
      scanf("%s", s + 1);
      N = strlen(s + 1);
      SuffixSort();
      GetHeight();
      int len = 0, count = 0;
      for (int i = 1; i <= N; i++)
      {
        len = len > Height[i] ? len : Height[i];
      }
      if (len == 0) printf("No repetitions found!\n");
      else
      {
        for (int i = 1; i <= N; i++)
        {
          if (len == Height[i])
          {
            for (int j = 0; j < len; j++)
            {
              printf("%c", s[sa[i] + j]);
            }
            while (i <= N && len == Height[i])
            {
              i++;
              count++;
            }
            break;
          }
        }
        printf(" %d\n", count + 1);
      }
    }
    return 0;
}
```

