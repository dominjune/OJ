// hdu 2089. ��Ҫ62
// ��λDP 
// references:
// http://wenku.baidu.com/view/9de41d51168884868662d623.html
// http://blog.csdn.net/wangyuquanliuli/article/details/13761661 
// ����һ�ֳ����򵥵ķ�����
// http://blog.csdn.net/xujinsmile/article/details/7854162 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[15][15];	//��iλ������j���ж��������  
int a, b;	//���� 
int digit[10];

void init()
{
	memset(dp, 0, sizeof(dp));
	memset(digit, 0, sizeof(digit));
	dp[0][0]=1;		//����ֻ�ǳ�ʼ���߽� 
	for(int i=1; i<=7; i++)		//1000000
	{
		for(int j=0; j<10; j++)	//��iλ���ܳ��ֵ��� 
		{
			for(int k=0; k<10; k++)	//��i-1λ���ܳ��ֵ�����ע�ⴢ���ʱ���Ƿ��ģ� 
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
	for(int i=len; i>=1; i--)	//��1��ʼ�Ϳ����ˣ���len�������λlen��ʼ 
	{
		for(int j=0; j<digit[i]; j++)
		{
			if(j != 4 && !(digit[i+1] == 6 && j == 2))
				ans += dp[i][j];
		}
		/*
			����413��ͳ�������λ�ͽ����ˣ���Ϊ���λ��4������Ķ�������
			����341����ͳ�������λ������Ļ����ܷ��� 
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
