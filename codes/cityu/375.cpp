#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct state
{
  int a, b, c, d;
  bool operator==(state s)
  {
    return (this->a == s.a) && (this->b == s.b) && \
      (this->c == s.c) && (this->d == s.d);
  }
};

bool vis[26][26][26][26];
int dis[26][26][26][26];
queue<state> Q;

bool finish(state s, int t)
{
  return s.a == t || s.b == t || s.c == t || s.d == t;
}

void judge_vis(state tmp, state res)
{
  if (!vis[tmp.a][tmp.b][tmp.c][tmp.d])
  {
    vis[tmp.a][tmp.b][tmp.c][tmp.d] = true;
    dis[tmp.a][tmp.b][tmp.c][tmp.d] = dis[res.a][res.b][res.c][res.d] + 1;
    Q.push(tmp);
  }
}

int main()
{
  int a, b, c, d, t;
  while (~scanf("%d%d%d%d%d", &a, &b, &c, &d, &t))
  {
    while (!Q.empty()) Q.pop();
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    state res = {0, 0, 0, 0};
    vis[0][0][0][0] = true;
    dis[0][0][0][0] = 0;
    Q.push(res);

    while (!Q.empty())
    {
      res = Q.front();
      Q.pop();
      if (finish(res, t)) break;
      //empty cup
      if (res.a > 0)
      {
        state tmp = res;
        tmp.a = 0;
        judge_vis(tmp, res);
      }
      if (res.b > 0)
      {
        state tmp = res;
        tmp.b = 0;
        judge_vis(tmp, res);
      }
      if (res.c > 0)
      {
        state tmp = res;
        tmp.c = 0;
        judge_vis(tmp, res);
      }
      if (res.d > 0)
      {
        state tmp = res;
        tmp.d = 0;
        judge_vis(tmp, res);
      }

      // fill one cup
      if (res.a < a)
      {
        state tmp = res;
        tmp.a = a;
        judge_vis(tmp, res);
      }
      if (res.b < b)
      {
        state tmp = res;
        tmp.b = b;
        judge_vis(tmp, res);
      }
      if (res.c < c)
      {
        state tmp = res;
        tmp.c = c;
        judge_vis(tmp, res);
      }
      if (res.d < d)
      {
        state tmp = res;
        tmp.d = d;
        judge_vis(tmp, res);
      }

      // pour one to another
      if (res.a > 0)
      {
        state tmp = res;
        int pour_value = min(tmp.a, b - tmp.b);
        tmp.a -= pour_value;
        tmp.b += pour_value;
        judge_vis(tmp, res);
        tmp = res;
        pour_value = min(tmp.a, c - tmp.c);
        tmp.a -= pour_value;
        tmp.c += pour_value;
        judge_vis(tmp, res);
        tmp = res;
        pour_value = min(tmp.a, d - tmp.d);
        tmp.a -= pour_value;
        tmp.d += pour_value;
        judge_vis(tmp, res);
      }

      if (res.b > 0)
      {
        state tmp = res;
        int pour_value = min(tmp.b, a - tmp.a);
        tmp.b -= pour_value;
        tmp.a += pour_value;
        judge_vis(tmp, res);
        tmp = res;
        pour_value = min(tmp.b, c - tmp.c);
        tmp.b -= pour_value;
        tmp.c += pour_value;
        judge_vis(tmp, res);
        tmp = res;
        pour_value = min(tmp.b, d - tmp.d);
        tmp.b -= pour_value;
        tmp.d += pour_value;
        judge_vis(tmp, res);
      }

      if (res.c > 0)
      {
        state tmp = res;
        int pour_value = min(tmp.c, a - tmp.a);
        tmp.c -= pour_value;
        tmp.a += pour_value;
        judge_vis(tmp, res);
        tmp = res;
        pour_value = min(tmp.c, b - tmp.b);
        tmp.c -= pour_value;
        tmp.b += pour_value;
        judge_vis(tmp, res);
        tmp = res;
        pour_value = min(tmp.c, d - tmp.d);
        tmp.c -= pour_value;
        tmp.d += pour_value;
        judge_vis(tmp, res);
      }

      if (res.d > 0)
      {
        state tmp = res;
        int pour_value = min(tmp.d, a - tmp.a);
        tmp.d -= pour_value;
        tmp.a += pour_value;
        judge_vis(tmp, res);
        tmp = res;
        pour_value = min(tmp.d, b - tmp.b);
        tmp.d -= pour_value;
        tmp.b += pour_value;
        judge_vis(tmp, res);
        tmp = res;
        pour_value = min(tmp.d, c - tmp.c);
        tmp.d -= pour_value;
        tmp.c += pour_value;
        judge_vis(tmp, res);
      }
    }
    if (finish(res, t))
    {
      printf("%d\n", dis[res.a][res.b][res.c][res.d]);
    }
    else
    {
      printf("-1\n");
    }
  }
}
