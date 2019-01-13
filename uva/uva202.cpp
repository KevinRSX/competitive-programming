#include <cstdio>
#include <cmath>

struct less
{
  int times;
  int indexes[500];
  int remainders[500];
};
char res[65];

int main()
{
  int a, b;
  while (~scanf("%d%d", &a, &b))
  {
    int itg_part = a / b;
    int digit = 1, temp = itg_part;
    while (temp / 10 > 0)
    {
      temp /= 10;
      digit++;
    }
    for (int i = 1; i <= digit; i++)
    {
      res[i - 1] = (char)((itg_part / (int)pow(10, digit - i)) % 10 + '0');
    }
    res[digit] = '.';
    res[digit + 1] = '\0';

    int i = digit + 1, remain = a % b;
    int start;
    int end;
    less fractions[10] = {0, {-1}, {-1}};
    bool omit = false;
    if (remain == 0)
    {
      res[i] = '0';
      res[i + 1] = '\0';
      end = start = i;
    }
    else
    {
      while (1)
      {
        int quotient = (remain * 10) / b;
        remain = (remain * 10) % b;
        if (!omit && i - digit > 50)
        {
          res[i + 2] = res[i + 1] = res[i] = '.';
          res[i + 3] = ')';
          res[i + 4] = '\0';
          omit = true;
        }
        if (remain == 0 && i - digit <= 50)
        {
          res[i] = (char)(quotient + '0');
          res[i + 1] = '0';
          res[i + 2] = '\0';
          end = start = i + 1;
          break;
        }

        bool stop = false;
        for (int j = 0; j < fractions[quotient].times; j++)
        {
          if (remain == fractions[quotient].remainders[j])
          {
            stop = true;
            start = fractions[quotient].indexes[j];
            end = i - 1;
            if (i - digit <= 50)
            {
              res[i] = '\0';
            }
            break;
          }
        }
        if (stop)
        {
          break;
        }
        else if (i - digit <= 50)
        {
          res[i] = (char)(quotient + '0');
        }
        fractions[quotient].indexes[fractions[quotient].times] = i;
        fractions[quotient].remainders[fractions[quotient].times] = remain;
        fractions[quotient].times++;
        i++;
      }
    }

    printf("%d/%d = ", a, b);
    for (int j = 0; res[j] != '\0'; j++)
    {
      if (j == start)
      {
        putchar('(');
      }
      putchar(res[j]);
      if (j == end)
      {
        putchar(')');
      }
    }
    printf("\n   %d = number of digits in repeating cycle\n\n", end - start + 1);
  }
  return 0;
}
