// poj 1144.Network
// ∏Óµ„∫Õ«≈ tarjan
// references:
// acm∫Ï È 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 105;
int edge[N][N];
int bridge[N][N], cut[N];
int low[N], dfn[N], vis[N];

void cut_bridge(int cur, int father, int dep, int n)
{
	vis[cur] = 1;
	dfn[cur] = low[cur] = dep;
	int children = 0;
	for(int i=1; i<=n; i++)
	{
		if(edge[cur][i])
		{
			if(i != father && vis[i] == 1 )
			{
				if(dfn[i] < low[cur])
					low[cur] = dfn[i];
			}
			if(vis[i] == 0)
			{
				cut_bridge(i, cur, dep+1, n);
				children++;
				if(low[i] < low[cur])
					low[cur] = low[i];
				if((father == -1 && children > 1) || (father != -1 && low[i] >= dfn[cur]))
					cut[cur] = 1;
				if(low[i] > dfn[cur])
				{
					bridge[cur][i] = bridge[i][cur] = 1;
				}
			}	
		}
	}
	vis[cur] = 2;
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF && n)
	{
		memset(dfn, 0, sizeof(dfn));
		memset(vis, 0, sizeof(vis));
		memset(low, 0, sizeof(low));
		memset(edge, 0, sizeof(edge));
		memset(bridge, 0, sizeof(bridge));
		memset(cut, 0, sizeof(cut));
		
		int u, v;
		while(scanf("%d", &u) != EOF && u)
		{
			while(getchar() != '\n')
			{
				scanf("%d", &v);
				edge[u][v] = 1;
				edge[v][u] = 1;
			}
		}
		int ans = 0;
		cut_bridge(1, -1, 0, n);
		for(int i=1; i<=n; i++)
		{
			if(cut[i])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
