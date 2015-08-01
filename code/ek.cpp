// poj 1273.Drainage Ditches
// 最大流问题 EK算法 
// reference: kuangbin
// http://www.cnblogs.com/kuangbin/archive/2011/07/26/2117636.html
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N=205;
const int INF=0x3f3f3f3f;
int n, m, start, end;
int graph[N][N];
int prev[N], flow[N];

int bfs()
{
	queue <int> q;
	memset(prev, -1, sizeof(prev));	//每次清空路径 
	prev[start]=0;
	flow[start]=INF;
	q.push(start);
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		if(temp == end)
			break;
		for(int i=1; i<=m; i++)
		{
			if(i != start && prev[i] == -1 && graph[temp][i])
			{
				flow[i] = flow[temp] < graph[temp][i] ? flow[temp] : graph[temp][i];
				q.push(i);
				prev[i]=temp;	//记录路径，用于该路径的容量更新 
			}
		}
	}
	if(prev[end] == -1)		//找不到增广路径 
		return -1;
	else
		return flow[m];		//到汇点的流增量 
}

int Edmonds_Karp()
{
	int max_flow=0;
	int pre, now, step;
	while((step = bfs()) != -1)	//只需要找到一条增广路径 
	{
		max_flow += step;
		now = end;
		while(now != start)	//从汇点找回源点更新
		{
			pre = prev[now];
			graph[pre][now] -= step;
			graph[now][pre] += step;	//反向边更新
			now = pre; 
		}
	}
	return max_flow;
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		memset(graph, 0, sizeof(graph));
		
		int u, v, w;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			graph[u][v] += w;	// flow in a circle!!!
		}
		start=1;
		end=m;
		printf("%d\n", Edmonds_Karp());
	}
	return 0;
}
