#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

bool isprime[10000], vis[10000];
int dis[10000];

void eratos(int n)
{
	for (int i = 0; i <= n; i++)
	{
		isprime[i] = true;
	}
	isprime[0] = isprime[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (isprime[i])
		{
			int j = i + i;
			while (j <= n)
			{
				isprime[j] = false;
				j += i;
			}
		}
	}
}


int main()
{
	using namespace std;
	eratos(9999);
	
	int T;
	scanf("%d", &T);
	while (T--)
	{
		queue<int> primer;
		memset(dis, -1, sizeof(dis));
		memset(vis, false, sizeof(vis));
		int start, end;
		scanf("%d%d", &start, &end);
		primer.push(start);
		vis[start] = true;
		int step = 0;
		dis[start] = step;
		while (!primer.empty())
		{
			int cur = primer.front();
			if (cur == end) break;
			step = dis[cur] + 1;
			primer.pop();
			for (int i = 10; i <= 10000; i *= 10)
			{
				int dig = (cur % i) / (i / 10);
				for (int j = -dig * (i / 10); j <= (9 - dig) * (i / 10); j += i / 10)
				{
					int change = cur + j;
					if (isprime[change] && !vis[change] && change >= 1000)
					{
						vis[change] = true;
						primer.push(change);
						dis[change] = step;
					}
				}
			}
		}
		if (dis[end] >= 0)
		{
			printf("%d\n", dis[end]);
		}
		else printf("Impossible\n");
	}
	return 0;
}
