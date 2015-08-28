// poj 1041.John's trip
// 欧拉回路 邻接矩阵存的是点和边的关系
// references:
// http://blog.csdn.net/xymscau/article/details/6450657
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int graph[50][2000];	//[顶点][该顶点的边] = 到达下一个顶点 
int vis[2000];
int degree[50];
int maxEdge;
int stack[2000];
int top;

void Euler(int s)
{
	for(int i=1; i<=maxEdge; i++)
	{
		if(!vis[i] && graph[s][i])
		{
			vis[i] = 1;					
			//stack[top++] = i;	//注意此处先入栈的话，可能会遇到：
			//假设中间存在一个点，从它开始可以扩展出两条以上欧拉回路，而其中一条是连接着起点的这种情况... 
			Euler(graph[s][i]);	
			stack[top++] = i;	//最后找完欧拉路再回溯 
		}
	}
}

int main()
{
	int x, y, z, s;
	while(scanf("%d%d", &x, &y) != EOF && x && y)
	{
		memset(degree, 0, sizeof(degree));
		memset(vis, 0, sizeof(vis));
		memset(graph, 0, sizeof(graph));
		top = 0;
		maxEdge = 0;
		scanf("%d", &z);
		graph[x][z] = y;
		graph[y][z] = x;
		degree[x]++;
		degree[y]++;
		s = min(x, y);
		maxEdge = max(maxEdge, z);
		
		bool flag = 1;
		while(scanf("%d%d", &x, &y) != EOF && x && y)
		{
			scanf("%d", &z);
			graph[x][z] = y;
			graph[y][z] = x;
			degree[x]++;
			degree[y]++;
			maxEdge = max(maxEdge, z);
		}
		
		for(int i=1; i<45; i++)
		{
			if(degree[i] % 2)
				flag = 0;
		}
		if(!flag)
		{
			printf("Round trip does not exist.\n");
			continue;
		}
		Euler(s);

		for(int i=0; i<top-1; i++)
			printf("%d ", stack[i]);
		printf("%d\n", stack[top-1]); 
	}
	return 0;
}
