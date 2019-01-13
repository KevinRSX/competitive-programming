#include <iostream>
#define MAXN 100000 + 5
#define left(x) 2 * x + 1
#define right(x) 2 * x + 2
#define parent(x) (x - 1) / 2

class MaxHeap
{
private:
  int vals[MAXN];
  int size;
  int max(int &a, int &b) { return a > b ? a : b; }
public:
  MaxHeap() { size = 0; }
  int get_size() { return size; }
  int get_sum();
  int get_val(int x);
  void Insert(int key);
  void Pop();
  void Swim(int x);
  void Sink(int x);
};

void MaxHeap::Insert(int key)
{
  vals[size++] = key;
  Swim(size - 1);
}

void MaxHeap::Pop()
{
  vals[0] = vals[size - 1];
  size--;
  Sink(0);
}

void MaxHeap::Sink(int x)
{
  if (left(x) >= size) return;
  else if (right(x) >= size)
  {
    if (vals[x] >= vals[left(x)]) return;
    int temp = vals[x];
    vals[x] = vals[left(x)];
    vals[left(x)] = temp;
  }
  else
  {
    if (vals[x] >= vals[left(x)] && vals[x] >= vals[right(x)]) return;
    if (vals[left(x)] > vals[right(x)])
    {
      int temp = vals[x];
      vals[x] = vals[left(x)];
      vals[left(x)] = temp;
      Sink(left(x));
    }
    else
    {
      int temp = vals[x];
      vals[x] = vals[right(x)];
      vals[right(x)] = temp;
      Sink(right(x));
    }
  }
}

void MaxHeap::Swim(int x)
{
  if (vals[x] < vals[parent(x)] || x == 0) return;
  int temp = vals[x];
  vals[x] = vals[parent(x)];
  vals[parent(x)] = temp;
  Swim(parent(x));
}

int MaxHeap::get_sum()
{
  int s = 0;
  for (int i = 0; i < size; i++)
  {
    s += vals[i];
  }
  return s;
}

int MaxHeap::get_val(int x)
{
  return vals[x];
}

int main()
{
  //freopen("in.txt", "r", stdin);
  using namespace std;
  int cmd;
  while (cin >> cmd)
  {
    MaxHeap mh;
    cin.get();
    while (cmd--)
    {
      char order;
      cin >> order;
      if (order == 'a')
      {
        int v;
        cin >> v;
        mh.Insert(v);
      }
      else if (order == 'p')
      {
        mh.Pop();
      }
      else if (order == 'r')
      {
        cout << mh.get_sum() << endl;
      }
    }
  }
}
