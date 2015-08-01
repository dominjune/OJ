// poj 1236.Network of Schools
// 强连通分量 
// kosaraju 算法
// 参考 
// http://www.cnblogs.com/qijinbiao/archive/2011/08/04/2127893.html
// http://www.cnblogs.com/kuangbin/archive/2011/08/07/2130277.html
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N=105;
int num[N], link[N];
bool vis[N];
int outdegree[N], indegree[N];
int n, cnt;
vector <int> graph[N], reverse_graph[N];
vector <int> v;

void dfs_1(int x)
{
	vis[x]=1;
	for(int i=0; i<graph[x].size(); i++)
	{
		if(!vis[graph[x][i]])
			dfs_1(graph[x][i]);
	}
	v.push_back(x);
}

void dfs_2(int x)
{
	num[x]=cnt;		//点x所属连通分量的编号为cnt  
	link[cnt]++;	//记录编号为cnt的连通分量中的元数个数 
	vis[x]=1;
	for(int i=0; i<reverse_graph[x].size(); i++)
	{
		if(!vis[reverse_graph[x][i]])
			dfs_2(reverse_graph[x][i]);
	}
	
}

void cal()
{
	memset(outdegree, 0, sizeof(outdegree));
	memset(indegree, 0, sizeof(indegree));
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<graph[i].size(); j++)
		{
			int x = graph[i][j];
			if(num[i] != num[x])	//编号不同，不是同一个强连通分量，并且记录哪个编号的分量有出度，入度 
			{
				outdegree[num[i]]=1;
				indegree[num[x]]=1;
			}
		}
	}
	int in=0, out=0;
	for(int i=1; i<=cnt; i++)	//统计出度为0的个数和入度为0的个数 
	{
		if(!indegree[i])
			in++;
		if(!outdegree[i])
			out++; 
	}
	printf("%d\n", in);
	if(cnt != 1)
		printf("%d\n", max(in, out));
	else
		printf("0\n");
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		memset(graph, 0, sizeof(graph));
		memset(reverse_graph, 0, sizeof(reverse_graph));
		
		for(int i=1; i<=n; i++)
		{
			int a;
			while(scanf("%d", &a) != EOF, a)
			{
				graph[i].push_back(a);
				reverse_graph[a].push_back(i);	//逆图 
			}
		}	
		for(int i=1; i<=n; i++)		//第一次dfs记录每个节点的结束时间 
		{
			if(!vis[i])
				dfs_1(i);
		}
		memset(vis, 0, sizeof(vis));
		memset(link, 0, sizeof(link));
		cnt=0;
		for(int i=v.size()-1; i>=0; i--)	//从结束时间最晚的开始第二次dfs 
		{
			if(!vis[v[i]])
			{
				cnt++;		//统计强连通分量个数 
				dfs_2(v[i]);
			}
		}
		cal();
	}
	return 0;
}
