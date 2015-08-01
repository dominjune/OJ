// poj 3308.Paratroopers
// 转化为：最大流最小割  dinic算法(比EK算法快) 
// references:
// http://comzyh.com/blog/archives/568/
// http://blog.csdn.net/ljd4305/article/details/9999501

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;
const int N=205;
const int INF=0x3f3f3f3f;
int graph[N][N];//记录图的邻接矩阵
int d[N];//记录图中各点的层次
int n, m, ans;

bool bfs()
{
	queue <int> q;
	memset(d, -1, sizeof(d));	//此处初始化要特别注意，以上版本的初始化就存在很大问题
	d[1]=0;						//如果处理不慎就很容易死循环
	q.push(1);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int i=1; i<=m; i++)
		{
			if(d[i]==-1 && graph[v][i])
			{
				d[i] = d[v]+1;
				q.push(i);
			}
		}
	}
	return d[m] != -1;	//注意顶点数量是m！！！不是n！！！ 
}

int dfs(int v, int cur_flow)
{
	int flow=0;
	if(v == m)	
		return cur_flow;
	for(int i=1; i<=m; i++)
	{
		if(graph[v][i] > 0 && d[v] + 1 == d[i] && (flow = dfs(i, min(cur_flow, graph[v][i]))))	//是下一层并搜到汇点 
		{
			graph[v][i] -= flow;
			graph[i][v] += flow;
			return flow;		
		}
	}
	return 0;
}

//int dinic()
void dinic()
{
	int cur_flow;
	while(bfs())	//一次bfs可以找到几条增广路
	{
		while(cur_flow = dfs(1, INF))
			ans += cur_flow;
	}
	//return ans;
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		ans=0;
		int u, v, w;
		memset(graph, 0, sizeof(graph));
		for(int i=0; i<n; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			graph[u][v] += w;
		}
		dinic();
		//printf("%d\n", dinic());
		printf("%d\n", ans);
	}
	return 0;
}

