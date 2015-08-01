// poj 3308.Paratroopers
// ת��Ϊ���������С��  dinic�㷨(��EK�㷨��) 
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
int graph[N][N];//��¼ͼ���ڽӾ���
int d[N];//��¼ͼ�и���Ĳ��
int n, m, ans;

bool bfs()
{
	queue <int> q;
	memset(d, -1, sizeof(d));	//�˴���ʼ��Ҫ�ر�ע�⣬���ϰ汾�ĳ�ʼ���ʹ��ںܴ�����
	d[1]=0;						//����������ͺ�������ѭ��
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
	return d[m] != -1;	//ע�ⶥ��������m����������n������ 
}

int dfs(int v, int cur_flow)
{
	int flow=0;
	if(v == m)	
		return cur_flow;
	for(int i=1; i<=m; i++)
	{
		if(graph[v][i] > 0 && d[v] + 1 == d[i] && (flow = dfs(i, min(cur_flow, graph[v][i]))))	//����һ�㲢�ѵ���� 
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
	while(bfs())	//һ��bfs�����ҵ���������·
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

