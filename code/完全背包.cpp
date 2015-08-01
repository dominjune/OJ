// poj 1384. Piggy-Bank
// ��ȫ���� ����С��ֵ ȡ��������ֵ
// ��ʱ��ע��dp����ĳ�ʼ��������ʼ�����������ļ�ֵ 
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
			dp[i] = -100000000;		//��ʼ����ͬ�����ļ�ֵ����ΪҪȡ���ֵ�����Ҽ�ֵȡ���ˣ����Գ�ʼ��Ҫ������С 
		scanf("%d%d", &a, &b);
		c = b - a;
		
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d%d", &v[i], &w[i]);
			v[i] = -v[i];	//����С��ֵ��ȡ��������������ֵ��ȡ�� 
		}
		dp[0]=0;	//����Ϊ0ʱ�ļ�ֵΪ0 
		int flag = dp_complete(); 
		if(flag == -1)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", flag);
	}
	return 0;
}
