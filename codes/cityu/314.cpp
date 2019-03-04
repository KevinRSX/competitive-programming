#include <cstdio>
#include <cstring>
#define maxn 100000 + 5

char s[maxn], p[maxn];
int len, next[maxn];

void getNext()
{
  int j = 0, k = -1;
  next[0] = -1;
  while (j < len - 1)
  {
    if (k == -1 || p[j] == p[k])
    {
      j++;
      k++;
      if (p[j] != p[k]) next[j] = k;
      else next[j] = next[k];
    }
    else
    {
      k = next[k];
    }
  }
}

int kmp()
{
  int i = 0, j = 0;
  while (i < len)
  {
    if (j == -1 || s[i] == p[j])
    {
      i++;
      j++;
    }
    else
    {
      j = next[j];
    }
  }
  return j;
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  while (~scanf("%s", s))
  {
    len = strlen(s);
    for (int i = len - 1; i >= 0; i--)
    {
      p[len - 1 - i] = s[i];
    }
    p[len] = '\0';
    getNext();
    printf("%s%s\n", s, p + kmp());
  }
}
