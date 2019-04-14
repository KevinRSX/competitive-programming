#  图的存储

## 邻接矩阵

`g[i][j]`表示i到j的一条边，缺点为机器浪费空间，并不能快速得到一个点的所有相邻点



## 邻接表

假设有n个点，则设置`vector nodes[n]`。 `vector[i]`存储第i个node的所有相邻点



## 前向星和链式前向星

### 前向星的原理

前向星是一种特殊的边集数组，存储每一条边的起点，终点， 和权值，并且按照起点大小排序，若起点相同则按照终点大小排序。

在实际操作中是使用三个数组：

- `head[i]`: 以i为起点的边集在数组中存储的第一个位置
- `len[i]`: 以i为起点的边集在数组中的长度，即i的out degree
- `w[i]`: 第i条边的权值

一个例子如下：

| 编号 | 起点 | 终点 |
| ---- | ---- | ---- |
| 1    | 1    | 2    |
| 2    | 1    | 3    |
| 3    | 1    | 5    |
| 4    | 2    | 3    |
| 5    | 3    | 4    |
| 6    | 4    | 1    |
| 7    | 4    | 5    |

此时，

`head[1] = 1`		`len[1] = 3`

`head[2] = 4`		`len[2] = 1`

`head[3] = 5`		`len[3] = 1`

`head[4] = 6`		`len[4] = 2`

这样的好处是可以快速得到并遍历相邻边，并且速度比以vector实现的邻接表要快很多。问题在于每次调用sort会浪费很多时间。链式前向星可以解决这个问题。



### 链式前向星

使用链式前向星可以避免排序。它的基础是如下结构体：

 ```c++
struct edge
{
   	int next;	// number of the next edge which has the same starting node as this
    // edge, -1 if this edge is the last one
   	int to;	 // node this edge points to
    int w;	// weight of this edge
};
 ```

另有一个数组为head，它用来表示以i为起点的第一条边的存储位置（即该边的序号）。一般初始化为-1

建边函数如下：

```c++
void add_edge(int from, int to, int w)
{
    edge[cnt].w = w;
    edge[cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt++;
}
```

edge[0].to = 2;     edge[0].next = -1;      head[1] = 0;

edge[1].to = 3;     edge[1].next = -1;      head[2] = 1;

edge[2].to = 4;     edge[2],next = -1;      head[3] = 2;

edge[3].to = 3;     edge[3].next = 0;       head[1] = 3;

edge[4].to = 1;     edge[4].next = -1;      head[4] = 4;

edge[5].to = 5;     edge[5].next = 3;       head[1] = 5;

edge[6].to = 5;     edge[6].next = 4;       head[4] = 6;

可以看出，head数组储存的实际上是最后一条输入的边，也就是每次输入的边都在链表的最前端，因此所有遍历均为倒序。

遍历以u为起点位置的边的代码是这样的

```c++
for (int i = head[u]; i != -1; i = edge[i].next)
{
    // do something
}
```



# 图的遍历

图的常用遍历算法有DFS, BFS, 和拓扑排序

## DFS

只给出常用的递归写法

```pseudocode
dfs(v)
{
    // if (vis[v]) return; optional
    vis[v] = true;
    for (each v's neighbour u)
    {
        if (!vis[u]) dfs(u);
    }
}
```



## BFS

```pseudocode
bfs(v)
{
    vis[v] = true;
    enqueue(v);
    while (queue not empty)
    {
        x = dequeue();
        for each x's neighbor u
        {
            if (!vis[u])
            {
                enqueue(u);
                vis[u] = true;
            }
        }
    }
}
```





# 最短路径

## 松弛计算

松弛计算（relaxation）是一个缩短距离的操作，对$path(u,v)​$的松弛目的在于是否可以经过u找到更短的通往v的路径

```c++
if (d[v] > d[u] + w(u, v))
    d[v] = d[u] + w(u, v);
```



## 单源最短路径

### Dijsktra's Algorithm

设图$G=(V, E)$的所有顶点的集合为$V$，起点为$s$，最短路径树中包含的顶点集合为$S$。在各计算步骤中，我们将选出最短路径树的边和顶点并将其添加至S。

对于各顶点$i$，设仅经由S内顶点的s到i的最短路径成本为$d[i]$, $i$在最短路径树中的父节点为$p[i]$.

1. 初始状态下将$S$置空。

   初始化的$s$的$d[s] = 0$, 除$s$以外，所有属于V的顶点$i$的$d[i]=\infty$

2. 循环以下处理，直至$S=V$为止。

   - 从$V-S$中选出$d[u]$最小的顶点$u$
   - 将$u$添加至$S$，同时将与$u$相邻且属于$V-S$的所有顶点$v$的松绑



该算法如果使用邻接矩阵，复杂度为$O(|V|^2)$，效率比较低

可以从如下两个方面进行优化：

1. 使用可以快速找出最小值的数据结构，如堆（heap），或C++的set
2. 用邻接表或链式前向星存图

下面给出一个用set实现的Dijsktra示例

```c++
void dijkstra(int src)
{
  set <pair <int, int> > setds;
  for (int i = 0; i < 10005; i++)
  {
    dist[i] = INF;
  }
  setds.insert(make_pair(0, src));
  dist[src] = 0;
  while (!setds.empty())
  {
    pair<int, int> tmp = *(setds.begin());		// select the point that has the smallest distance
      // to the source
    setds.erase(setds.begin());
    int u = tmp.second;
    for (int e = head[u]; ~e; e = E[e].nxt)		// traverse neighbors using foward star 			// representation
    {
      int v = E[e].to;
      int w = E[e].w;
      if (dist[v] > dist[u] + w)
      {
        if (dist[v] != INF)	// v may have been visited by another node before, when this happens
            // we can erase this value to make setds smaller
        {
          setds.erase(setds.find(make_pair(dist[v], v)));
        }
        dist[v] = dist[u] + w;
        setds.insert(make_pair(dist[v], v));
      }
    }
  }
}
```



### Bellman-Ford Algorithm

由于Dijkstra需要对每一步进行贪心，当前选取的最优解即是全局的最优解，因此如果出现负边，会使得得到的结果没有递增。所以，当存在边的权值为负的时候，Dijkstra会无法求出正确的最短路。Bellman-Ford是一个替代Dijkstra的优秀方法，他对每条边都进行松弛，重复$V-1$次（$V$为顶点数）。

由于最短路最多经历$V-1$边，而内层循环每次最少松弛一条边，那么$V-1$次循环即能完成。注意，Bellman-Ford是不可以判断负回路(negative cycle)的，但它可以通过增加一个循环来判断图中是否有负回路。

下面给出代码

```cpp
typedef struct Edge{
    int u, v;    // 起点，终点
    int weight;  // 边的权值
}Edge;

Edge edge[maxnum];     // 保存边的值
int  dist[maxnum];     // 结点到源点最小距离

int nodenum, edgenum, source;    // 结点数，边数，源点

bool Bellman_Ford()
{
    for(int i = 1; i <= nodenum - 1; ++i)
        for(int j = 1; j <= edgenum; ++j)
        {
            if (dist[edge[j].v] > dist[edge[j].u] + edge[j].weight)
            {
                dist[edge[j].v] = dist[edge[j].u] + edge[j].weight;
            }
        }
    bool flag = 1; 
    for(int i = 1; i <= edgenum; ++i)
        if(dist[edge[i].v] > dist[edge[i].u] + edge[i].weight)
        {
            flag = 0;
            break;
        }
    return flag;
}
```

不难看出复杂度为$O(|V|\cdot |E|)$。值得注意的是，如果想要用链式前向星实现这个算法，必须在edge结构体中储存每条边的起点，否则必须每个循环重新遍历每个点，效率会非常低。



## 所有点最短路

最常用的所有点最短路算法是Floyd-Warshall algorithm。这是一个基于dp的算法。

我们考虑如下dp数组：`dp[n][n][n]`，n是结点的个数，前两维代表目前求出的i到j的最短路，后一维表示目前可以经过的点的个数。

整个算法基于如下状态转移式
$$
sp(i,j,k)=\min \left \{sp(i,j,k-1),sp(i,k,k-1)+sp(k,j,k-1) \right \}
$$
举个例子：`dp[3][5][2]`表示3到5在允许经过1和2时求出的最短路，而状态转移式的意义是，从零开始，每次增加允许最短路可以经过的点的个数，直到达到n为止。那么算法可以表示如下：

```c++
for (int k = 0; k < n; k++)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j][k] = min(dp[i][j][k - 1], dp[i][k][k - 1] + dp[k][j][k - 1]);
        }
    }
}
```

但我们可以发现在这段代码中，k只和上一个状态k-1有关，所以数组的第三维可以省略，下一层可以通过上一层来计算，即优化为：

```c++
for (int k = 0; k < n; k++)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] > dp[i][k] + dp[k][j])
                dp[i][j] = dp[i][k] + dp[k][j];
        }
    }
}
```





# 最小生成树

## Prim's Algorithm

Prim's algorithm是求最小生成树的代表算法之一

简介：

1. 设图$G=(V, E)$中所有顶点的集合为$V$, 其最小生成树中顶点集合为$T$

2. 循环执行以下处理直至$T=V​$。

   在连接$T$内顶点与$V-T$内顶点的边中选取权值最小的边$(p_u,u)$，将其作为最小生成树的边，并将$u$添加至$T$.



变量

| 变量名    | 用途                                      |
| --------- | ----------------------------------------- |
| `vis[n]`  | 一个顶点是否被访问过，即是否已被添加至$T$ |
| `M[n][n]` | 邻接矩阵                                  |
| `d[n]`    | 连接 $T$ 和 $V-T$ 中顶点的权值最小的边    |

```pseudocode
prim()
	set vis array to false, d to INFTY
	d[0] = 0
	
	while true
		mincost = INFTY
        for i = 0 to n - 1
        	if !vis[i] && d[i] < mincost
        		mincost = d[i]
        		u = i
        
        if mincost == INFTY
        	break
        
        vis[u] = true
        
        for v = 0 to n - 1
        	if !vis[v] && exists edge between u, v
        		if M[u][v] < d[v]
        			d[v] = M[u][v]
```



## Kruskal's Algorithm

Prim's Algorithm是"加点"算法，而Kruskal's Algorithm是"加边"算法。

它的概念非常简单：每次选取权值最小的边，将边和边上的点添加到最小生成树中。然而，选取边的条件是该条边的两个顶点不可以同时已经在树中。

实现：

1. 用from，to， weight三个attribute来存储边
2. 先把所有边由小至大sort一遍
3. 使用并查集判断两点是否都在最小生成树中

```c++
// kruskal
#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
 
const int MAXN = 505;
const int MAXM = 250005;
int F[MAXN];	// union-find array
 
struct Edge
{
    int u,v,w;
}

Edge edge[MAXM];
 
int tol = 0;	// no. of deges
 
void addedge(int u,int v,int w)
{
    edge[tol].u=u;
    edge[tol].v=v;
    edge[tol++].w=w;
}
 
bool cmp(Edge a,Edge b)		// sort edges according to weight
{
    return a.w<b.w;
}
 
int Find(int x)
{
    if(F[x] == -1)
        return x;
    else
        return F[x] = Find(F[x]);
}
 
int Kruskal(int n)	// returns the total weight of MST, -1 if not connected
{
    memset(F,-1,sizeof(F));
    sort(edge,edge + tol,cmp);
    int cnt = 0;	// no. of edges added
    int ans = 0;
    for(int i=0;i<tol;i++)
    {
        int u=edge[i].u;
        int v=edge[i].v;
        int w=edge[i].w;
        int t1=Find(u);
        int t2=Find(v);
        if(t1 != t2)
        {
            ans+=w;
            F[t1]=t2;	// union t1 and t2
            cnt++;
        }
        if(cnt == n-1)
            break;
    }
    if(cnt < n-1)
        return -1;	// not connected
    else
        return ans;
}
```





# 来源和拓展阅读

链式前向星：https://blog.csdn.net/acdreamers/article/details/16902023

Bellman-Ford：http://www.wutianqi.com/blog/1912.html

Kruskal：https://blog.csdn.net/algzjh/article/details/52312423

挑战程序设计竞赛V2

