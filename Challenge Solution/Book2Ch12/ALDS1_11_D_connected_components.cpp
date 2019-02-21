#include <cstdio>

int parent[100001];

int find(int k)
{
  if (parent[k] == k) return k;
  return parent[k] = find(parent[k]);
}

void Union(int a, int b)
{
  int pa = find(a);
  int pb = find(b);
  parent[pa] = pb;
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
  }
  while (m--)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    Union(a, b);
  }
  int q;
  scanf("%d", &q);
  while (q--)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    if (find(a) == find(b))
    {
      printf("yes\n");
    }
    else
    {
      printf("no\n");
    }
  }
}
