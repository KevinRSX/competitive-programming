#include <cstdio>

struct birth
{
  char name[20];
  int birthday;
};

int main()
{
  int n;
  scanf("%d", &n);
  birth person[105];
  int young[2] = {0, 0}, old[2] = {99999999, 0};
  for (int i = 0; i < n; i++)
  {
    int m, d, y;
    scanf("%s%d%d%d", person[i].name, &d, &m, &y);
    person[i].birthday = y * 10000 + m * 100 + d;
    if (person[i].birthday < old[0])
    {
      old[1] = i;
      old[0] = person[i].birthday;
    }
    if (person[i].birthday > young[0])
    {
      young[1] = i;
      young[0] = person[i].birthday;
    }
  }
  printf("%s\n%s\n", person[young[1]].name, person[old[1]].name);
  return 0;
}
