// hihoCoder Week5
// #1037 : Êý×ÖÈý½ÇÐÎ

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[105][105];

int main()
{
	int n, m, i, j, ans = -1;
	for(i=1, scanf("%d", &n); i<=n; i++)
		for(j=1; j<=i && scanf("%d", &m); j++)
		{
			if(i == 1)	dp[i][j] = m;
			else	dp[i][j] = max(dp[i-1][j-1] + m, dp[i-1][j] + m);
		}
	for(int i=1; i<=n; i++)	ans = max(ans, dp[n][i]);
	printf("%d\n", ans);
	
	return 0;
} 
