#include <cstdio>

typedef long long ll;

bool first = true;
void printbang(ll n)
{
  if (n / ((ll)1e7) == 0)
  {
    bool blank = false;
    if (!first)
    {
      printf(" kuti");
      blank = true;
    }
    else first = false;
    if (n / ((ll)1e5) > 0)
    {
      if (blank) printf(" ");
      printf("%lld lakh", n / ((ll)1e5));
      n %= (ll)1e5;
      blank = true;
    }
    if (n / ((ll)1e3) > 0)
    {
      if (blank) printf(" ");
      printf("%lld hajar", n / ((ll)1e3));
      n %= (ll)1e3;
      blank = true;
    }
    if (n / ((ll)100) > 0)
    {
      if (blank) printf(" ");
      printf("%lld shata", n / ((ll)100));
      n %= (ll)1e2;
      blank = true;
    }
    if (n > 0)
    {
      if (blank) printf(" ");
      printf("%lld", n);
      blank = true;
    }
    return;
  }
  printbang(n / ((ll)1e7));
  printbang(n % ((ll)1e7));
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ll n;
  int kase = 0;
  while (~scanf("%lld", &n))
  {
    first = true;
    printf("%4d. ", ++kase);
    if (n) printbang(n);
    else printf("0");
    printf("\n");
  }
  return 0;
}
