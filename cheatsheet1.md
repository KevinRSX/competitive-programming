22 Prime Path

Seive of Eratos, BFS "shortest path"

```cpp
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

bool isprime[10000], vis[10000];
int dis[10000];

void eratos(int n)
{
	for (int i = 0; i <= n; i++)
	{
		isprime[i] = true;
	}
	isprime[0] = isprime[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (isprime[i])
		{
			int j = i + i;
			while (j <= n)
			{
				isprime[j] = false;
				j += i;
			}
		}
	}
}


int main()
{
	using namespace std;
	eratos(9999);
	
	int T;
	scanf("%d", &T);
	while (T--)
	{
		queue<int> primer;
		memset(dis, -1, sizeof(dis));
		memset(vis, false, sizeof(vis));
		int start, end;
		scanf("%d%d", &start, &end);
		primer.push(start);
		vis[start] = true;
		int step = 0;
		dis[start] = step;
		while (!primer.empty())
		{
			int cur = primer.front();
			if (cur == end) break;
			step = dis[cur] + 1;
			primer.pop();
			for (int i = 10; i <= 10000; i *= 10)
			{
				int dig = (cur % i) / (i / 10);
				for (int j = -dig * (i / 10); j <= (9 - dig) * (i / 10); j += i / 10)
				{
					int change = cur + j;
					if (isprime[change] && !vis[change] && change >= 1000)
					{
						vis[change] = true;
						primer.push(change);
						dis[change] = step;
					}
				}
			}
		}
		if (dis[end] >= 0)
		{
			printf("%d\n", dis[end]);
		}
		else printf("Impossible\n");
	}
	return 0;
}
```



134 Dominos 2

DFS, adjacency list implemented by vector

```cpp
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
bool vis[10001] = { 0 };
int n, m, l, cnt;
vector<int> g[10001];

void dfs(int c)
{
  if (vis[c]) return;
  vis[c] = true;
  cnt++;
  for (int i = 0; i < g[c].size(); i++)
  {
    if (!vis[g[c][i]]) dfs(g[c][i]);
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    memset(vis, false, sizeof(vis));
    cnt = 0;
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 0; i <= 10001; i++)
    {
      g[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
      int x, y;
      scanf("%d%d", &x, &y);
      g[x].push_back(y);
    }
    for (int i = 0; i < l; i++)
    {
      int p;
      scanf("%d", &p);
      dfs(p);
    }
    printf("%d\n", cnt);
  }
  return 0;
}
```



165 Frogger

Prim, minimax

```cpp
#include <cstdio>
#include <utility>
#include <cmath>
using namespace std;
#define maxn 200
#define INFTY 0xffffff

struct point
{
  double x, y;
};

double dist(point p1, point p2)
{
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

point V[maxn + 5];
int p[maxn + 5], d[maxn + 5];
bool vis[maxn + 5];

int main()
{
  int n, kase = 1;
  while (~scanf("%d", &n) && n != 0)
  {
    for (int i = 0; i < maxn + 5; i++)
    {
      V[i].x = V[i].y = 0;
      p[i] = -1;
      vis[i] = false;
      d[i] = INFTY;
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%lf%lf", &V[i].x, &V[i].y);
    }

    d[0] = 0;
    while (true)
    {
      int mincost = INFTY, u;
      for (int i = 0; i < n; i++)
      {
        if (!vis[i] && d[i] < mincost)
        {
          mincost = d[i];
          u = i;
        }
      }

      if (mincost == INFTY) break;
      vis[u] = true;

      for (int i = 0; i < n; i++)
      {
        double tmp_d = dist(V[u], V[i]);
        if (!vis[i] && tmp_d < d[i])
        {
          d[i] = tmp_d;
          p[i] = u;
        }
      }
    }
    double fd = 0;
    for (int k = 1; p[k] != -1; k = p[k])
    {
      if (dist(V[k], V[p[k]]) > fd)
      {
        fd = dist(V[k], V[p[k]]);
      }
    }
    printf("Scenario #%d\n", kase++);
    printf("Frog Distance = %.3lf\n\n", fd);
  }
}
```



190 Equation

infix to postfix

```cpp
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

bool isdigit(char c)
{
  return (0 <= c - '0' && c - '0' <= 9);
}

int precedence(char c)
{
  if (c == '+' || c == '-') return 1;
  else if (c == '*' || c == '/') return 2;
  else return 3;
}

int main()
{
  int T;
  scanf("%d", &T);
  getchar();
  getchar();
  while (T--)
  {
    int cnt = 0;
    char temp[3], str[55];
    while (fgets(temp, 3, stdin))
    {
      if (temp[0] == '\n') break;
      str[cnt++] = temp[0];
    }
    str[cnt] = '\0';
    stack<char> s;
    for (int i = 0; str[i] != '\0'; i++)
    {
      if (isdigit(str[i]))
      {
        putchar(str[i]);
      }
      else if (s.empty() || str[i] == '(' || (precedence(str[i]) > precedence(s.top())
                        && (str[i] != ')')))
      {
        s.push(str[i]);
      }
      else if (str[i] == ')')
      {
        while (s.top() != '(' && !s.empty())
        {
          putchar(s.top());
          s.pop();
        }
        if (s.top() == '(') s.pop();
      }
      else
      {
        while (!s.empty() && precedence(str[i]) <= precedence(s.top()) && s.top() != '(')
        {
          putchar(s.top());
          s.pop();
        }
        s.push(str[i]);
      }
    }
    while (!s.empty())
    {
      putchar(s.top());
      s.pop();
    }
    printf("\n");
    if (T > 0)
    {
      printf("\n");
    }
  }
  return 0;
}
```



216 Longest Common Subsequence

```cpp
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int C[1001][1001];
int lcs(string s1, string s2)
{
	int m = s1.size();
	int n = s2.size();
	C[0][0] = 0;
	s1 = ' ' + s1;
	s2 = ' ' + s2;
	int max_lcs = 0;
	for (int i = 1; i <= m; i++)
		C[i][0] = 0;
	for (int j = 1; j <= n; j++)
		C[0][j] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i] == s2[j]) C[i][j] = C[i - 1][j - 1] + 1;
			else C[i][j] = max(C[i - 1][j], C[i][j - 1]);
			max_lcs = max(max_lcs, C[i][j]);
		}
	}
	return max_lcs;
}

int main()
{
	string s1, s2;
	while (getline(cin, s1) && getline(cin, s2))
	{
		cout << lcs(s1, s2) << endl;
	}
	return 0;
}
```



217 Coin change

full bag

```cpp
#include <cstdio>

int main()
{
  int coin[5] = { 50, 25, 10, 5, 1 };
  int dp[7490] = {0};
  dp[0] = 1;
  for (int i = 0; i < 5; i++)
  {
    for (int j = coin[i]; j <= 7490; j++)
    {
      dp[j] = dp[j - coin[i]] + dp[j];
    }
  }
  int a;
  while (~scanf("%d", &a))
  {
    printf("%d\n", dp[a]);
  }
}
```

218 SuperSale

0/1 bag

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int G[35], w[1005], price[1000];
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int n;
    scanf("%d", &n);
    memset(G, 0, sizeof G);
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", &price[i], &w[i]);
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 30; j >= w[i]; j--)
      {
        G[j] = max(G[j], G[j - w[i]] + price[i]);
      }
    }

    int people, res = 0;
    scanf("%d", &people);
    for (int i = 0; i < people; i++)
    {
      int tmp_w;
      scanf("%d", &tmp_w);
      res += G[tmp_w];
    }
    printf("%d\n", res);
  }
}
```



314 Extend to palindromes

KMP

```cpp
#include <cstdio>
#include <cstring>
#define maxn 100000 + 5

char s[maxn], p[maxn];
int len, next[maxn];

void getNext()
{
  int j = 0, k = -1;
  next[0] = -1;
  while (j < len - 1)
  {
    if (k == -1 || p[j] == p[k])
    {
      j++;
      k++;
      if (p[j] != p[k]) next[j] = k;
      else next[j] = next[k];
    }
    else
    {
      k = next[k];
    }
  }
}

int kmp()
{
  int i = 0, j = 0;
  while (i < len)
  {
    if (j == -1 || s[i] == p[j])
    {
      i++;
      j++;
    }
    else
    {
      j = next[j];
    }
  }
  return j;
}

int main()
{
  while (~scanf("%s", s))
  {
    len = strlen(s);
    for (int i = len - 1; i >= 0; i--)
    {
      p[len - 1 - i] = s[i];
    }
    p[len] = '\0';
    getNext();
    printf("%s%s\n", s, p + kmp());
  }
}
```



507 Zodiac Fever

Dijkstra with state

```cpp
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
  memset(dist,INFTY,sizeof(dist));
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
```



Combination

```c++
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

void combination(char *chset, vector<char> selected, int r, int start)
{
  if (r == 0)
  {
    for (vector<char>::iterator it = selected.begin(); it != selected.end();\
     it++)
    {
      putchar(*it);
    }
    putchar(' ');
    return;
  }

  for (int i = start; i < strlen(chset); i++)
  {
    selected.push_back(chset[i]);
    combination(chset, selected, r - 1, i + 1);
    // when i >= 3 is passed as parameter at the point r = 3, the whole
    // function will do nothing
    selected.erase(selected.end() - 1);
  }
}

int main()
{
  char chset[] = "abcde";
  vector<char> v;
  combination(chset, v, 3, 0);
  printf("\n");
  return 0;
}
```

