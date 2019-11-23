#include <cstdio>
#include <cstring>

int gcd(int a, int b)
{
  if (a < b) return gcd(b, a);
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int binary_to_int(char *c)
{
  int res = 0;
  int len = strlen(c);
  for (int i = 0; i < len; i++)
  {
    int digit = c[i] - '0';
    for (int j = 0; j < len - i - 1; j++)
    {
      digit <<= 1;
    }
    res += digit;
  }
  return res;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  int p = 0;
  while (T--)
  {
    char a[35], b[35];
    scanf("%s\n%s\n", a, b);
    if (gcd(binary_to_int(a), binary_to_int(b)) == 1)
    {
      printf("Pair #%d: Love is not all you need!\n", ++p);
    }
    else
    {
      printf("Pair #%d: All you need is love!\n", ++p);
    }
  }
}
