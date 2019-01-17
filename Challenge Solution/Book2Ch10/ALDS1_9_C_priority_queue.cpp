#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 2000000
#define INFTY 1 << 30
#define parent(x) x / 2
#define left(x) x * 2
#define right(x) x * 2 + 1

int H, A[MAX + 1];

void maxHeapify(int i)
{
	int l = left(i);
	int r = right(i);

	if (l > H) return;
	else if (r > H)
	{
		if (A[i] < A[l])
		{
			int temp = A[i];
			A[i] = A[l];
			A[l] = temp;
		}
		else return;
	}
	else
	{
		if (A[i] >= A[l] && A[i] >= A[r]) return;
		int large = A[l] > A[r] ? l : r;
		int temp = A[i];
		A[i] = A[large];
		A[large] = temp;
		maxHeapify(large);
	}
}

int extract()
{
	int maxv;
	if (H < 1)
		return -INFTY;
	maxv = A[1];
	A[1] = A[H--];
	maxHeapify(1);
	return maxv;
}

void increaseKey(int i, int key)
{
	if (key < A[i])
		return;
	A[i] = key;
	while (i > 1 && A[i / 2] < A[i])
	{
		swap(A[i], A[i / 2]);
		i = i / 2;
	}
}

void insert(int key)
{
	A[++H] = -INFTY;
	increaseKey(H, key);
}

int main()
{
	int key;
	char com[10];
	while (1)
	{
		scanf("%s", com);
		if (com[0] == 'e' && com[1] == 'n')
			break;
		if (com[0] == 'i')
		{
			scanf("%d", &key);
			insert(key);
		}
		else
		{
			printf("%d\n", extract());
		}
	}
	return 0;
}