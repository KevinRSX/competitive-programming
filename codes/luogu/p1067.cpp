#include <cstdio>

int main()
{
  int terms;
  scanf("%d", &terms);
  bool start = true;
  for (int i = terms; i > 1; i--)
  {
    int para;
    scanf("%d", &para);
    if (para == 0) continue;
    else if (para > 0)
    {
      if (start)
      {
        if (para == 1)
        {
          printf("x^%d", i);
        }
        else
        {
          printf("%dx^%d", para, i);          
        }
        start = false;
      }
      else if (para == 1)
      {
        printf("+x^%d", i);
      }
      else
      {
        printf("+%dx^%d", para, i);
      }
    }
    else
    {
      if (start) start = false;
      if (para == -1)
      {
        printf("-x^%d", i);
      }
      else
      {
        printf("-%dx^%d", -para, i);
      }
    }
  }

  int para;
  scanf("%d", &para);
  if (para > 0)
  {
    if (start)
    {
      printf("%dx", para);
      start = false;
    }
    else if (para == 1)
    {
      printf("+x");
    }
    else
    {
      printf("+%dx", para);
    }
  }
  else if (para < 0)
  {
    if (start) start = false;
    if (para == -1)
    {
      printf("-x");
    }
    else
    {
      printf("-%dx", -para);
    }
  }

  int cons;
  scanf("%d", &cons);
  if (cons > 0)
  {
    if (start)
    {
      printf("%d", cons);
      start = false;
    }
    else
    {
      printf("+%d", cons);
    }
  }
  else if (cons < 0)
  {
    printf("-%d", -cons);
  }
  printf("\n");
  return 0;
}
