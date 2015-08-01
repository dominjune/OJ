// poj 3159. Candies
// ��ǰ��+spfa+stack
// spfa+ջʵ����ʵ����dfs���������˸������ж� 
// references:
// http://blog.sina.com.cn/s/blog_64018c250100ugck.html
// http://www.cnblogs.com/kuangbin/archive/2012/08/17/2644685.html 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n;
const int N=300005;	//����ߵ���������Ϊ��ǰ���Ǵ���ߵ� 
const int INF=0x3f3f3f3f;

struct node {
	int v;
	int w;
	int next;
};

node edge[N];
int adj[N];
int dis[N];
bool vis[N];
int sta[N];
int size;
int in[N];

void add_edge(int u, int v, int w)  
{  
    edge[size].v = v;  
    edge[size].w = w;  
    edge[size].next = adj[u];  //�ߵ�nextָ����һ���� 
    adj[u] = size++; 	//�����ǵڼ����� 
}

int spfa(int s)
{
	int top=0;
	int u, w, v;
	for(int i=1; i<=n; i++)
	{
		dis[i]=INF;
		vis[i]=0;
	}
	dis[s]=0;
	vis[s]=1;
	sta[top++]=s;	//ģ��ջ 
	while(top)
	{
		u = sta[--top];
		vis[u]=0;
		//int len=graph[u].size();
		//for(int i=0; i<len; i++)
		for(int i=adj[u]; i!=-1; i=edge[i].next)	//����ͬ���ı� 
		{
			//w = graph[u][i].w;
			//v = graph[u][i].v;
			v = edge[i].v;  
            w = edge[i].w; 
			if(dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				if(!vis[v])
				{
					in[v]++;
					if(in[v] > n)	//����һ����Ӵ��������ܶ��������и��� 
						return -1;
					vis[v]=1;
					sta[top++]=v;
				}
			}
		}
	}
	return dis[n];
}

int main()
{
	int m, u, v, w;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for (int i=0; i<=n; i++) 
			adj[i] = -1;  
		//memset(graph, 0, sizeof(graph));
		memset(vis, 0, sizeof(vis));
		size = 0;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, w);
			//graph[u].push_back(node(v, w));
		}
		spfa(1);
		printf("%d\n", dis[n]);
	}
	return 0;
}
