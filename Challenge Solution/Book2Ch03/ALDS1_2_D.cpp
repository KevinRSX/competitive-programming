#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
long long cnt;
int A[1000005];
vector<int> G;
void insertionSort(int A[], int n, int g);
void shellSort(int A[], int n);

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  cnt = 0;
  shellSort(A, n);
  cout << G.size() << endl;
  for (int i = G.size() - 1; i >= 0; i--)
  {
    printf("%d", G[i]);
    if (i)
    {
      printf(" ");
    }
  }
  printf("\n");
  printf("%lld\n", cnt);
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", A[i]);
  }
  return 0;
}

void insertionSort(int A[], int n, int g)
{
  for (int i = g; i < n; i++)
  {
    int j = i;
    while (j - g >= 0 && A[j] < A[j - g])
    {
      int temp = A[j];
      A[j] = A[j - g];
      A[j - g] = temp;
      j -= g;
      cnt++;
    }
  }
}

void shellSort(int A[], int n)
{
  for (int h = 1;;)
  {
    if (h > n)
    {
      break;
    }
    G.push_back(h);
    h = 3 * h + 1;
  }

  for (int i = G.size() - 1; i >= 0; i--)
  {
    insertionSort(A, n, G[i]);
  }
}
