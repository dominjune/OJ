// hihoCoder Week8
// #1044 : ×´Ì¬Ñ¹Ëõ¡¤Ò»
// http://beeder.github.io/2014/12/30/hihoCoder-Problem-1044-state-compression-NO-1/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int w[1005], n, m, q;
int dp[1005][1<<12];

int CountBit(int x)
{
	int count = 0;
	while(x)
	{
		if(x & 1)
			count++;
		x /= 2;
	}
	return count;
}

int main()
{
	while(scanf("%d%d%d", &n, &m, &q) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++)
			scanf("%d", &w[i]);
	
		int maxM = 1 << m;
		for(int i=1; i<=n; i++)
		{
			for(int j=0; j<maxM; j++)
			{
				if(CountBit(j) <= q)
					dp[i][j] = max(dp[i-1][j>>1], dp[i-1][(j>>1) + (1<<(m-1))]);
				if(j&1)	dp[i][j] += w[i];
			}
		}
		int ans = -1;
		for(int i=0; i<maxM; i++)
			ans = max(ans, dp[n][i]);
		printf("%d\n", ans);
	}
	
	return 0;
}
