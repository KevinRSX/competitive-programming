#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node *left, *right;
};

Node *root = NULL;

void insert(int key)
{
  Node *x = root;
  Node *y = NULL;
  Node *in = new Node;
  in->value = key;
  in->left = in->right = NULL;
  while (x != NULL)
  {
    y = x;
    if (x->value > key)
    {
      x = x->left;
    }
    else if (x->value < key)
    {
      x = x->right;
    }
  }

  if (y == NULL) root = in;
  else
  {
    if (y->value > key) y->left = in;
    else if (y->value < key) y->right = in;
  }
}

bool search(int key)
{
  Node *p = root;
  while (p != NULL)
  {
    if (p->value == key)
    {
      return true;
    }
    else if (p->value > key)
    {
      p = p->left;
    }
    else p = p->right;
  }
  return false;
}

void inorder(Node *t)
{
  if (t == NULL) return;
  inorder(t->left);
  printf(" %d", t->value);
  inorder(t->right);
}

void preorder(Node *t)
{
  if (t == NULL) return;
  printf(" %d", t->value);
  preorder(t->left);
  preorder(t->right);
}

int main()
{
  int n, x;
  string com;
  scanf("%d", &n);

  while (n--)
  {
    cin >> com;
    if (com == "insert")
    {
      scanf("%d", &x);
      insert(x);
    }
    else if (com == "print")
    {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }
    else if (com == "find")
    {
      scanf("%d", &x);
      if (search(x)) printf("yes\n");
      else printf("no\n");
    }
  }
  return 0;
}
