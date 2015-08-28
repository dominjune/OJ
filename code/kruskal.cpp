// poj 1861.Network
// kruskal mst
// references:
// no
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10005;		//顶点只是用来判断并查集的 
const int M = 150005;	//kruskal用的是边啊 
int n, m;
int cnt, ans;
int p[N];

struct Edge {
	int u;
	int v;
	int w;
}edge[M];

Edge res[M];

bool cmp(Edge a, Edge b)
{
	return a.w < b.w;	//小于啊 
}

void init()
{
	cnt = 0;
	ans = -1;
	for(int i=0; i<n; i++)
	{
		p[i] = -1;
	}
}

int find(int x)
{
	return p[x] == -1 ? x : p[x] = find(p[x]);	//搞了半天这里写错了，是-1！！！ 
}

void kruskal()	//没返回值要写成void，也是够 
{
	init();
	for(int i=0; i<m; i++)
	{
		int x = find(edge[i].u);
		int y = find(edge[i].v);
		if(x != y)
		{
			p[x] = y;
			if(ans < edge[i].w)
				ans = edge[i].w;
			res[cnt].u = edge[i].u;
			res[cnt++].v = edge[i].v;
		}
	}
	printf("%d\n", ans);
	printf("%d\n", cnt);
	for(int i=0; i<cnt; i++)
	{
		printf("%d %d\n", res[i].u, res[i].v);
	}
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		}
		sort(edge, edge + m, cmp);
		kruskal();
	}
	return 0;
}
