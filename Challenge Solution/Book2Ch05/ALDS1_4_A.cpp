#include <iostream>

int linear_search(int A[], int n, int key);

int main()
{
	using namespace std;
	int n, A[10000 + 1], q, key, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> key;
		if (linear_search(A, n, key))
		{
			sum++;
		}
	}
	cout << sum << endl;
}

int linear_search(int A[], int n, int key)
{
	int i = 0;
	A[n] = key;
	while (A[i] != key)
	{
		i++;
	}
	return i != n;
}