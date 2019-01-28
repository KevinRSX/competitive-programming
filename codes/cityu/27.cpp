#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  freopen("in.txt", "r", stdin);
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int a, b, c, n, max_gem = 0;
    scanf("%d%d%d%d", &a, &b, &c, &n);
    for (int i = 0; i < n; i++)
    {
      vector<int> v;
      printf("i = %d\n", i);
      int next = i, gem_no = 0;
      v.push_back(next);
      while (true)
      {
        next = (a * next * next + b * next + c) % n;
        if (binary_search(v.begin(), v.end(), next))
        {
          break;
        }
        printf("next = %d\n", next);
        v.push_back(next);
        gem_no++;
      }
      if (gem_no > max_gem) max_gem = gem_no;
    }
    printf("%d\n", max_gem);
  }
}
