# Programming notes -- 201901

## 1. 20190115 dp优化穷举搜索问题

### 1.1 题目 [Exhaustive Search](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A)

现有长度为n的数列A和整数m，编写程序判断A中任意几个元素相加是否能得到m。A中的每个元素只能使用一次。

### 1.2 穷举搜索

题中给定n小于20，因此可以暴搜出所有情况，判断是否要使用每一个数，复杂度$O(2^n)$

```c++
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
```



### 1.3 dp优化

穷举搜索之所以低效是因为要重复计算已存在之结果，在本题中即`solve(i, m)`是否为true，如果能用一个数组将其记录下来，每次先查看当前数组`dp[i][m]`是否为true，可减少重复调用递归的次数。填满`dp[n][m]`需要mn次操作，因此复杂度$O(2^n)$. 将小规模局部问题的解存储在内存中，等到计算大的问题时直接拿来有效利用，这就是动态规划的基本思路。完整代码如下：

```c++
#include <cstdio>
#include <cstring>

int n, A[50], dp[21][2001];

int solve(int i, int m)
{
  if (dp[i][m] != -1)
  {
    return dp[i][m];
  }

  if (m == 0)
    dp[i][m] = 1;
  else if (i >= n)
    dp[i][m] = 0;
  else if (solve(i + 1, m))
    dp[i][m] = 1;
  else if (solve(i + 1, m - A[i]))
    dp[i][m] = 1;
  else
    dp[i][m] = 0;

  return dp[i][m];
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  int q, m;
  scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &m);
    if (solve(0, m) != 0) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}

```

