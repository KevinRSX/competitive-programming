#include <iostream>
#include <cstdio>

int partition(int A[], int p, int r);
void quicksort(int A[], int p, int r);

int main()
{
	using namespace std;
	int A[100005], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	partition(A, 0, n - 1);
	quicksort(A, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	return 0;
}

int partition(int A[], int p, int r)
{
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= A[r])
		{
			i++;
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	int temp = A[r];
	A[r] = A[i + 1];
	A[i + 1] = temp;
	return i + 1;
}

void quicksort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}