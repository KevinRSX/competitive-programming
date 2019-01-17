#include <cstdio>
#define MAX 10000
#define NIL -1

struct Node
{
  int p, l, r;
};

Node T[MAX];

void preParse(int u)
{
  if (u == NIL)
  {
    return;
  }
  printf(" %d", u);
  preParse(T[u].l);
  preParse(T[u].r);
}

void inParse(int u)
{
  if (u == NIL)
  {
    return;
  }
  inParse(T[u].l);
  printf(" %d", u);
  inParse(T[u].r);
}

void postParse(int u)
{
  if (u == NIL)
  {
    return;
  }
  postParse(T[u].l);
  postParse(T[u].r);
  printf(" %d", u);
}

int main()
{
  int size;
  scanf("%d", &size);

  for (int i = 0; i < size; i++)
  {
    T[i].p = NIL;
  }

  for (int i = 0; i < size; i++)
  {
    int nd, left_child, right_child;
    scanf("%d%d%d", &nd, &left_child, &right_child);
    T[nd].l = left_child;
    T[nd].r = right_child;
    if (left_child != NIL)
    {
      T[left_child].p = nd;
    }
    if (right_child != NIL)
    {
      T[right_child].p = nd;
    }
  }

  int root;
  for (int i = 0; i < size; i++)
  {
    if (T[i].p == NIL)
    {
      root = i;
    }
  }
  
  printf("Preorder\n");
  preParse(root);
  printf("\n");
  printf("Inorder\n");
  inParse(root);
  printf("\n");
  printf("Postorder\n");
  postParse(root);
  printf("\n");

  return 0;
}
