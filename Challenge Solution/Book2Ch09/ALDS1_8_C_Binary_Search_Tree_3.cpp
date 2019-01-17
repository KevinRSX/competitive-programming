#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

struct Node
{
  int value;
  Node *right, *left, *parent;
};

Node *root;

Node *treeMin(Node *x)
{
  while (x->left != NULL) x = x->left;
  return x;
}

Node *search(int key)
{
  Node *p = root;
  while (p != NULL)
  {
    if (p->value == key)
    {
      return p;
    }
    else if (p->value > key)
    {
      p = p->left;
    }
    else p = p->right;
  }
  return NULL;
}

Node *treeSuccessor(Node *x)
{
  if (x->right != NULL) return treeMin(x->right);
  Node *y = x->parent;
  while (y != NULL && x == y->right)
  {
    x = y;
    y = y->parent;
  }
  return y;
}

void treeDelete(Node *z)
{
  Node *y;  //y: the (place of) node that is to be deleted
  Node *x;  //x: the child of y
  if (z->left == NULL || z->right == NULL)
  {
    y = z;  //case 1 or 2
  }
  else
  {
    y = treeSuccessor(z);
    z->value = y->value;
  }

  if (y->left != NULL)
  {
    x = y->left;
  }
  else
  {
    x = y->right;
  }

  if (x != NULL) x->parent = y->parent;
  if (y->parent == NULL)
  {
    root = x;
  }
  else
  {
    if (y == y->parent->left)
    {
      y->parent->left = x;
    }
    else
    {
      y->parent->right = x;
    }
  }
}

void insert(int key)
{
  Node *x = root;
  Node *y = NULL;
  Node *in = new Node;
  in->value = key;
  in->left = in->right = in->parent = NULL;
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
    in->parent = y;
    if (y->value > key)
    {
      y->left = in;
    }
    else if (y->value < key)
    {
      y->right = in;
    }
  }
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
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
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
      if (search(x) != NULL) printf("yes\n");
      else printf("no\n");
    }
    else if (com == "delete")
    {
      scanf("%d", &x);
      treeDelete(search(x));
    }
  }
  return 0;
}
