// ��һ�����ֳ����飬��͵Ĳ�ľ���ֵ��С
// e.g. 1 2 3 4 ->  1 4 | 2 3 -> abs(1+4-(2+3)) = 0
// ȡsum��һ����Ϊ����һ�������������������� 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int a[25];
int dp[1000002];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		int volume = sum/2;
		int maxx=0,minn=0;
		for(int i=0;i<n;i++)
	 		for(int j=volume;j>=a[i];j--)
	 		{
	 	 		dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
	 		}
	 	maxx = dp[volume];
		minn = (int)abs(maxx-(sum-maxx));
		printf("%d\n",minn);
	}
	return 0;
}
