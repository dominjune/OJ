// hihocoder week60
// String Matching Content Length

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2105;
char a[N], b[N];
int f[N][N], dp[N][N];

int main()
{
	while(scanf("%s%s", a, b) != EOF)
	{
		memset(f, 0, sizeof(f));
		memset(dp, 0, sizeof(dp));
		
		int n = strlen(a);
		int m = strlen(b);
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				if(a[i-1] == b[j-1])
					f[i][j] = f[i-1][j-1] + 1;	//公共后缀长度>=3
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);		//后面用到了更新后的dp[i][j] 
				if(f[i][j] >= 3)
				{
					for(int k=3; k<=f[i][j]; k++)		// O(n ^ 3)
					//if(a[i-1] == b[j-1])
						dp[i][j] = max(dp[i][j], dp[i - k][j - k] + k);
				}
			}
		}
		printf("%d\n", dp[4][7]);
	}
	return 0;
}
