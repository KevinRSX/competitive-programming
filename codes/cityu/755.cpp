#include <cstdio>
#include <algorithm>
#include <stack>

#define MAXN 100005
typedef long long ll;
using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    ll max_area = 0;
    int len, h[MAXN];
    stack<int> mono;
    scanf("%d", &len);
    for (int i = 1; i <= len; i++)
    {
      scanf("%d", &h[i]);
    }
    mono.push(0);
    h[0] = 0;
    h[++len] = 0;
    for (int i = 1; i <= len; i++)
    {
      while (!mono.empty() && h[i] < h[mono.top()])
      {
        ll b = h[mono.top()];
        mono.pop();
        ll a = i - 1 - mono.top();
        max_area = max(max_area, a * b);
      }
      mono.push(i);
    }
    printf("%lld\n", max_area);
  }
  return 0;
}
