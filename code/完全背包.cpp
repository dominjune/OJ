// poj 1384. Piggy-Bank
// 完全背包 求最小价值 取负求最大价值
// 此时需注意dp数组的初始化，及初始化背包容量的价值 
// references:
// http://blog.csdn.net/zxy_snow/article/details/6023963
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a, b, c;
int dp[10005];
int w[10005];
int v[10005];

int dp_complete()
{
	for(int i=0; i<n; i++)
	{
		for(int j=w[i]; j<=c; j++)
			dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
	}
	if(-dp[c] == 100000000)
		return -1;
	return -dp[c];
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		for(int i=0; i<10005; i++)
			dp[i] = -100000000;		//初始化不同容量的价值，因为要取最大值，而且价值取负了，所以初始化要尽可能小 
		scanf("%d%d", &a, &b);
		c = b - a;
		
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d%d", &v[i], &w[i]);
			v[i] = -v[i];	//求最小价值，取负，最后求出最大价值再取负 
		}
		dp[0]=0;	//容量为0时的价值为0 
		int flag = dp_complete(); 
		if(flag == -1)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", flag);
	}
	return 0;
}
