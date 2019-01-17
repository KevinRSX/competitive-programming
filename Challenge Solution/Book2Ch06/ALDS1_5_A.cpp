#include <iostream>

int n, q, m;
int A[2001];
bool solve(int i, int m);

int main()
{
	using namespace std;
	
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> A[i];
	}
	cin >> q;
	while (q--)
	{
		cin >> m;
		if (solve(0, m))
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	return 0;
}

bool solve(int i, int m)
{
	if (m == 0)
	{
		return true;
	}
	if (i >= n)
	{
		return false;
	}
	bool res = solve(i + 1, m) || solve(i + 1, m - A[i]);
	return res;
}