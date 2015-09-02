// 把一组数分成两组，求和的差的绝对值最小
// e.g. 1 2 3 4 ->  1 4 | 2 3 -> abs(1+4-(2+3)) = 0
// 取sum的一半作为其中一个背包容量，放满就行 
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
