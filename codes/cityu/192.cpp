#include <cstdio>

bool balance;

int calc()
{
  int wl, dl, wr, dr;
  scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
  if (wl == 0) wl = calc();
  if (wr == 0) wr = calc();
  if (wl * dl != wr * dr) balance = false;
  return wl + wr;
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    balance = true;
    calc();
    if (!balance) printf("NO\n");
    else printf("YES\n");
    if (T > 0) printf("\n");
  }
}
