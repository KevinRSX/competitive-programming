#include <cstdio>
#include <list>
#include <algorithm>

#define COVER_LIST list<int>::iterator it = v.begin(); it != v.end(); it++

using namespace std;

int main()
{
	int q, x;
	char com[20];
	list <int> v;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%s", com);
		if (com[0] == 'i')	//insert
		{
			scanf("%d", &x);
			v.push_front(x);
		}
		else if (com[6] == 'L')	//deleteLast
		{
			v.pop_back();
		}
		else if (com[6] == 'F')	//deleteFirst
		{
			v.pop_front();
		}
		else if (com[0] == 'd')	//delete
		{
			scanf("%d", &x);
			for (COVER_LIST)
			{
				if (*it == x)
				{
					v.erase(it);
					break;
				}
			}
		}
	}
	int i = 0;
	for (COVER_LIST)
	{
		if (i++)
		{
			printf(" ");
		}
		printf("%d", *it);
	}
	printf("\n");
	return 0;
}