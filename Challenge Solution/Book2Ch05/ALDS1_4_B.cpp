#include <iostream>

int A[1000000], n;

int binarySearch(int key)
{
	int left = 0;
	int right = n;
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (A[mid] == key)
		{
			return mid;
		}
		else if (A[mid] > key)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

int main()
{
	using namespace std;
	int q, k, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> k;
		if (binarySearch(k) + 1)
		{
			sum++;
		}
	}
	cout << sum << endl;
}