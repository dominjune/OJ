// poj 1018.Communication System
// ��dp
// ���˱��˶����״̬�����������Լ���ģ��ü���!!! 
// references:
// http://blog.csdn.net/y990041769/article/details/23735949

#include <iostream>
#include <cstdio>

using namespace std;

int dp[1005][1005];
const int INF = 0x3f3f3f3f;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		for(int i=0; i<1005; i++)
			for(int j=0; j<1005; j++)
				dp[i][j] = INF;
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
		{
			int m;
			scanf("%d", &m);
			for(int j=1; j<=m; j++)
			{
				int b, p;
				scanf("%d%d", &b, &p);
				if(i == 1)
					dp[1][b] = min(dp[1][b], p);
				else
				{
					for(int k=0; k<1005; k++)	//�����Сһ��500Ҳ�У����ܸ������й� 
					{
						if(dp[i-1][k] != INF)	//ע����i-1����i 
						{
							if(k >= b)
								dp[i][b] = min(dp[i][b], dp[i-1][k] + p);
							else
								dp[i][k] = min(dp[i][k], dp[i-1][k] + p);
						}
					}
				}
			}
		}
		double ans = -1;
		for(int i=0; i<1005; i++)
		{
			if(dp[n][i] != INF)
			{
				double temp = i * 1.0 / dp[n][i];
				if(ans < temp)
					ans = temp;
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
} 
