// poj 1008. 滑雪
// 简单dp 一点都不简单啊
// 实际上说是记忆化搜索更合适 
// references:
// dp[i][j]为到(i,j)的最长距离或者从(i,j)出发的最长距离都行
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 105;
int n, m;
int dp[N][N];
int graph[N][N];
int move_x[] = {0, 0, 1, -1};
int move_y[] = {1, -1, 0, 0};

int dfs(int i, int j)
{
	if(dp[i][j])	
		return dp[i][j];
	dp[i][j] = 1;
	for(int k=0; k<4; k++)
	{
		int tx = i + move_x[k];
		int ty = j + move_y[k];
		if(tx >= 1 && tx <= n && ty >=1 && ty <= m)
		{
			if(graph[tx][ty] > graph[i][j] && dp[i][j] < dfs(tx, ty) + 1)
			{
				dp[i][j] = dp[tx][ty] + 1;
			}
		}
	}
	return dp[i][j];
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		memset(dp, 0 ,sizeof(dp));
		int maxn = -1;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				scanf("%d", &graph[i][j]);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
			{
				int len = dfs(i, j);
				if(maxn < len)
					maxn = len;
			}
		printf("%d\n", maxn);
	}
	return 0;
}
