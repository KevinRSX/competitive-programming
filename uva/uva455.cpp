#include <cstdio>
#include <cstring>
using namespace std;

bool repeat(char *str, int m)
{
  char copy[85];
  int i = 0;
  for (; i < m; i++)
  {
    copy[i] = str[i];
  }
  while (str[i] != '\0')
  {
    if (str[i] != copy[i % m]) return false;
    i++;
  }
  return true;
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    char str[85];
    scanf("%s", str);
    int len = strlen(str);
    bool k = false;
    for (int i = 1; i <= len; i++)
    {
      if (len % i == 0)
      {
        if (repeat(str, i))
        {
          printf("%d\n", i);
          k = true;
          break;
        }
      }
    }
    if (T > 0) printf("\n");
  }
  return 0;
}
