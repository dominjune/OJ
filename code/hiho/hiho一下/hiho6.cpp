// hihoCoder Week6
// #1038 : 01背包
// 超级短的01背包...
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[100005], n, m, x, y, i, j;

int main()
{
	for(i=0, scanf("%d%d", &n, &m); i<n && scanf("%d%d", &x, &y); i++)
		for(j=m; j>=x; j--)
			dp[j] = max(dp[j], dp[j-x]+y);
	printf("%d\n", dp[m]);
	return 0;
} 
