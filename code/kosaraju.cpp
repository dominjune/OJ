// poj 1236.Network of Schools
// ǿ��ͨ���� 
// kosaraju �㷨
// �ο� 
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
	num[x]=cnt;		//��x������ͨ�����ı��Ϊcnt  
	link[cnt]++;	//��¼���Ϊcnt����ͨ�����е�Ԫ������ 
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
			if(num[i] != num[x])	//��Ų�ͬ������ͬһ��ǿ��ͨ���������Ҽ�¼�ĸ���ŵķ����г��ȣ���� 
			{
				outdegree[num[i]]=1;
				indegree[num[x]]=1;
			}
		}
	}
	int in=0, out=0;
	for(int i=1; i<=cnt; i++)	//ͳ�Ƴ���Ϊ0�ĸ��������Ϊ0�ĸ��� 
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
				reverse_graph[a].push_back(i);	//��ͼ 
			}
		}	
		for(int i=1; i<=n; i++)		//��һ��dfs��¼ÿ���ڵ�Ľ���ʱ�� 
		{
			if(!vis[i])
				dfs_1(i);
		}
		memset(vis, 0, sizeof(vis));
		memset(link, 0, sizeof(link));
		cnt=0;
		for(int i=v.size()-1; i>=0; i--)	//�ӽ���ʱ������Ŀ�ʼ�ڶ���dfs 
		{
			if(!vis[v[i]])
			{
				cnt++;		//ͳ��ǿ��ͨ�������� 
				dfs_2(v[i]);
			}
		}
		cal();
	}
	return 0;
}
