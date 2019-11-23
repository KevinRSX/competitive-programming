#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;

ll edges[3];

int main()
{
  int T;
  scanf("%d", &T);
  int kase = 0;
  while (T--)
  {
    scanf("%lld%lld%lld", &edges[0], &edges[1], &edges[2]);
    sort(edges, edges + 3);
    if (edges[0] + edges[1] <= edges[2])
    {
      //printf("%lld\n", edges[0] + edges[1]);
      printf("Case %d: Invalid\n", ++kase);
    }
    else if (edges[0] == edges[1] && edges[1] == edges[2])
    {
      printf("Case %d: Equilateral\n", ++kase);
    }
    else if (edges[0] == edges[1] || edges[1] == edges[2])
    {
      printf("Case %d: Isosceles\n", ++kase);
    }
    else
    {
      printf("Case %d: Scalene\n", ++kase);
    }
  }
}
