#include <iostream>
#include <algorithm>

int main()
{
  using namespace std;
  int n, A[5];
  cin >> n;
  for (int i = 0; i < 5; i++)
  {
    cin >> A[i];
  }
  sort(A, A + 5);
  for (int i = 0; i < 5; i++)
  {
    cout << A[i] << ' ';
  }
  cout << endl;
  return 0;
}
