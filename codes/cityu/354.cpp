#include <cstdio>

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
      int temp;
      scanf("%d", &temp);
      sum += temp % 10 + temp / 100 % 10;
      int d1 = temp / 1000, d2 = temp / 10 % 10;
      sum += (d1 * 2) / 10 + (d1 * 2) % 10;
      sum += (d2 * 2) / 10 + (d2 * 2) % 10;
    }
    if (sum % 10 == 0) printf("Valid\n");
    else printf("Invalid\n");
  }
}
