// poj 3624. Charm Bracelet
// ÂãµÄ01±³°ü 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int dp[15000];
int w[15000];
int v[15000];

int dp_zero_one()
{
	for(int i=0; i<n; i++)
	{
		for(int j=m; j>=w[i]; j--)
			dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
	}
	return dp[m];
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i=0; i<n; i++)
			scanf("%d%d", &w[i], &v[i]);
		printf("%d\n", dp_zero_one());
	}	
	return 0;
}
