#include <cstdio>

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int n;
    scanf("%d", &n);
    if (n < 2) printf("0\n");
    else printf("%d\n", n - 2);
  }
}
