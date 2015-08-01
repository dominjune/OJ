// poj 1014.Dividing
// 多重背包
// references:
// http://www.cnblogs.com/devil-91/archive/2012/08/18/2645643.html
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[15];
int dp[150000];
int w[150000];
int v[150000];
int mid;

void split(int &count)
{
	for(int i=1; i<=6; i++)
	{
		int k=1;
		int m=a[i];
		while(k <= m)	//二进制拆分!!! 
		{
			w[count] = k;
			v[count++] = i;
			m -= k;
			k *= 2;
		}
		if(m>0)
		{
			w[count] = m;
			v[count++] = i;
		}		
	}
}

void dp_multiple(int count)
{
	for(int i=0; i<count; i++)
	{
		int temp = v[i] * w[i];
		for(int j=mid; j>=temp; j--)	//背包容量为总价值的一半，能否装满!!! 
			dp[j] = max(dp[j], dp[j-temp]+temp);
	}
}

int main()
{
	int k=1;
	while(1)
	{
		memset(dp,0, sizeof(dp));
		int count=0;
		for(int i=1; i<=6; i++)
			scanf("%d", &a[i]);
		int sum=0;
		for(int i=1; i<=6; i++)
			sum += a[i] * i;
		if(sum == 0)
			break;
		printf("Collection #%d:\n", k++);
		
		if(sum % 2 == 1)
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		mid = sum / 2;
		split(count);
		dp_multiple(count);
		if(dp[mid] == mid)
			printf("Can be divided.\n\n");
		else
			printf("Can't be divided.\n\n");
	}
	return 0;
} 
