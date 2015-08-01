// poj 1163. The Triangle
// ����dp ����n���˹���Ȼ���Ҳ��ᣬ��������
// �����������˺���ͦˬ�� 
// references:
// no
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[105][105];

int main()
{
	int n, m;
	while(scanf("%d", &n) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=i; j++)
			{
				scanf("%d", &m);
				if(i == 1)
					dp[i][j] = m;
				else
					dp[i][j] = max(dp[i-1][j-1] + m, dp[i-1][j] + m);
			}
		}
		int ans = -1;
		for(int i=1; i<=n; i++)
		{
			if(ans < dp[n][i])
				ans = dp[n][i];
		}
		printf("%d\n", ans);
	}
	return 0;
} 
