// poj 2186.Popular Cows
// references: 
// byvoid: https://www.byvoid.com/blog/scc-tarjan/
// http://www.cnblogs.com/daniagger/archive/2012/06/08/2541506.html //��㣿����
// http://blog.csdn.net/lyy289065406/article/details/6764104 //����������� 
// ǿ��ͨ����tarjan�㷨 
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
    	//else if(vis[v] && dfn[v] < low[u])	//��ջ���Ԫ�أ����ҷ���low[u]�Ķ��� 
    	//	low[u] = dfn[v];
    }
    if(dfn[u] == low[u])
    {
    	cnt++;
    	do {
    		v = s.top();
    		s.pop();
    		vis[v]=0;
    		belong[v]=cnt;	//�������ڱ��Ϊcnt��ǿ��ͨ���� 
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
				outdegree[belong[i]]++;		//ͳ�Ƴ��� 
			}
		}
	}
	int out=0;	//ͳ�Ƴ���Ϊ0�ĵ�ĸ��� 
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
	if(out == 1)	//�������Ϊ0������ĸ���ǡ��Ϊ1��֤���ܻ�ӭ��ţ���ڳ���Ϊ0����һ��ǿ��ͨ�������� 
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
		init();		//��init�� 
		int u, v;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d", &u, &v);
			graph[u].push_back(v);	//����ͼ 
		}
		solve();
		cal();
	}
	
	return 0;
}
