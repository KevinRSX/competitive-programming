#include <iostream>

void mergeSort(int a[], int start, int end);
void merge(int a[], int start, int mid, int end);
int cnt = 0;

int main()
{
  using namespace std;
  int n;
  cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  mergeSort(a, 0, n - 1);
  for (int i = 0; i < n - 1; i++)
  {
    cout << a[i] << ' ';
  }
  cout << a[n - 1] << endl << cnt << endl;
  return 0;
}

void mergeSort(int a[], int start, int end)
{
  if (start < end)
  {
    int mid = (start + end) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);
    merge(a, start, mid, end);
  }
}

void merge(int a[], int start, int mid, int end)
{
  int len1 = mid - start + 1;
  int len2 = end - mid;
  int *L = new int[len1];
  int *R = new int[len2];
  for (int i = 0; i < len1; i++)
  {
    L[i] = a[start + i];
  }
  for (int i = 0; i < len2; i++)
  {
    R[i] = a[mid + 1 + i];
  }

  int m = 0, n = 0, k = start;
  while (m < len1 && n < len2)
  {
    cnt++;
    if (L[m] <= R[n])
    {
      a[k++] = L[m++];
    }
    else if (L[m] > R[n])
    {
      a[k++] = R[n++];
    }
  }
  while (m < len1)
  {
    cnt++;
    a[k++] = L[m++];
  }
  while (n < len2)
  {
    cnt++;
    a[k++] = R[n++];
  }
  delete[] L;
  delete[] R;
}
