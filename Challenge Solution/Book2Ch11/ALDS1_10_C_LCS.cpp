#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAXN 1000

int lcs(string s1, string s2)
{
  int m = s1.size();
  int n = s2.size();
  int C[MAXN + 1][MAXN + 1];
  C[0][0] = 0;
  s1 = ' ' + s1;
  s2 = ' ' + s2;
  int max_lcs = 0;
  for (int i = 1; i <= m; i++)
    C[i][0] = 0;
  for (int j = 1; j <= n; j++)
    C[0][j] = 0;
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s1[i] == s2[j]) C[i][j] = C[i - 1][j - 1] + 1;
      else C[i][j] = max(C[i - 1][j], C[i][j - 1]);
      max_lcs = max(max_lcs, C[i][j]);
    }
  }
  return max_lcs;
}

int main()
{
  string s1, s2;
  int q;
  cin >> q;
  while (q--)
  {
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
  }
  return 0;
}
