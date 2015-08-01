// poj 3159. Candies
// 向前星+spfa+stack
// spfa+栈实现其实就是dfs，还加上了负环的判断 
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
const int N=300005;	//储存边的数量，因为向前星是储存边的 
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
    edge[size].next = adj[u];  //边的next指向下一条边 
    adj[u] = size++; 	//储存是第几条边 
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
	sta[top++]=s;	//模拟栈 
	while(top)
	{
		u = sta[--top];
		vis[u]=0;
		//int len=graph[u].size();
		//for(int i=0; i<len; i++)
		for(int i=adj[u]; i!=-1; i=edge[i].next)	//找相同起点的边 
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
					if(in[v] > n)	//存在一点入队次数大于总顶点数，有负环 
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
