// hdu 2089. 不要62
// 数位DP 
// references:
// http://wenku.baidu.com/view/9de41d51168884868662d623.html
// http://blog.csdn.net/wangyuquanliuli/article/details/13761661 
// 还有一种超级简单的方法：
// http://blog.csdn.net/xujinsmile/article/details/7854162 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[15][15];	//第i位是数字j，有多少种情况  
int a, b;	//区间 
int digit[10];

void init()
{
	memset(dp, 0, sizeof(dp));
	memset(digit, 0, sizeof(digit));
	dp[0][0]=1;		//作用只是初始化边界 
	for(int i=1; i<=7; i++)		//1000000
	{
		for(int j=0; j<10; j++)	//第i位可能出现的数 
		{
			for(int k=0; k<10; k++)	//第i-1位可能出现的数（注意储存的时候是反的） 
			{
				if(j != 4 && !(j == 6 && k == 2))
					dp[i][j] += dp[i-1][k];
			}
		}
	}
}

int solve(int n)
{
	init();
	int len=0;
	while(n)
	{
		digit[++len] = n % 10;
		n /= 10;
	}
	int ans=0;
	for(int i=len; i>=1; i--)	//从1开始就可以了，到len，从最高位len开始 
	{
		for(int j=0; j<digit[i]; j++)
		{
			if(j != 4 && !(digit[i+1] == 6 && j == 2))
				ans += dp[i][j];
		}
		/*
			比如413，统计完最高位就结束了，因为最高位是4，后面的都不可能
			若是341，则统计完最高位，后面的还可能符合 
		*/ 
		if(digit[i] == 4 || (digit[i] == 2 && digit[i+1] == 6))		
			break;
	}
	return ans;
}

int main()
{
	while(scanf("%d%d", &a, &b) != EOF, a, b)
	{
		printf("%d\n", solve(b+1) - solve(a));
	}
	return 0;
}
