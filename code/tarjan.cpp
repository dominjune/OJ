// poj 2186.Popular Cows
// references: 
// byvoid: https://www.byvoid.com/blog/scc-tarjan/
// http://www.cnblogs.com/daniagger/archive/2012/06/08/2541506.html //割点？？？
// http://blog.csdn.net/lyy289065406/article/details/6764104 //解决其他问题 
// 强连通分量tarjan算法 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

const int N=10005;
int n, m;
vector <int> graph[N];
int dfn[N], low[N], belong[N];
int outdegree[N], indegree[N];
bool vis[N];
int tag, cnt;
stack <int> s;

void tarjan(int u)
{
   	int v;
    dfn[u]=low[u]=++tag;
    vis[u]=1;
    s.push(u);
    
    for(int i=0; i<graph[u].size(); i++)
    {
    	v = graph[u][i];
    	if(!dfn[v])		//if !vis[v]???
    	{
    		tarjan(v);
    		low[u] = min(low[u], low[v]);
    		//if(low[v] < low[u])
    		//	low[u] = low[v];
    	}
    	else if(vis[v])
    		low[u] = min(low[u], dfn[v]);
    	//else if(vis[v] && dfn[v] < low[u])	//在栈里的元素，并且符合low[u]的定义 
    	//	low[u] = dfn[v];
    }
    if(dfn[u] == low[u])
    {
    	cnt++;
    	do {
    		v = s.top();
    		s.pop();
    		vis[v]=0;
    		belong[v]=cnt;	//顶点属于编号为cnt的强连通分量 
    	}while(v != u);
    }
}

void init()
{
	cnt=tag=0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(vis, 0, sizeof(vis));
	memset(graph, 0, sizeof(graph));
	memset(belong, 0, sizeof(belong));
}
void solve()
{
    for(int i=1; i<=n; i++)
    	if(!dfn[i])
    		tarjan(i);
}

void cal()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<graph[i].size(); j++)
		{
			int v = graph[i][j];
			if(belong[i] != belong[v])
			{
				outdegree[belong[i]]++;		//统计出度 
			}
		}
	}
	int out=0;	//统计出度为0的点的个数 
	int temp=-1;
	int ans=0;
	for(int i=1; i<=cnt; i++)
	{
		if(!outdegree[i])
		{
			out++;
			temp=i;
		}
	}
	if(out == 1)	//如果出度为0的缩点的个数恰好为1，证明受欢迎的牛都在出度为0的那一个强连通分量里面 
	{
		for(int i=1; i<=n; i++)
			if(belong[i] == temp)
				ans++;
		printf("%d\n", ans);
	}
	else
		printf("0\n");
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		init();		//先init啊 
		int u, v;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d", &u, &v);
			graph[u].push_back(v);	//有向图 
		}
		solve();
		cal();
	}
	
	return 0;
}
