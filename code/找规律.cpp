// poj 1019.Number Sequence
// 数学题 找规律 
// references:
// 解释还是看这个，我自己都乱了: http://blog.csdn.net/lyy289065406/article/details/6648504
// (int)log10((double)i) + 1：求一个数有多少位，好像很好用啊 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 32000;
long long a[N];		//到第几位数的位数 
long long b[N];	//到第几位数的累积位数和 

void init()		//初始化a,b数组 
{
	int x = 10, cnt = 1;
	a[0] = 0;
	b[0] = 0;
	for(int i=1; i<=N; i++)
	{
		if(i < x)
			a[i] = a[i-1] + cnt;
		else
		{
			cnt++;
			a[i] = a[i-1] + cnt;
			x *= 10;
		}
		b[i] = b[i-1] + a[i];
	}
}

int check(int x)	//判断在哪一组数之后 
{
	int i = 1;
	while(b[i] < x)
	{
		i++;
	}
	return i-1;
}

int main()
{
	int t;
	init();
	scanf("%d", &t);
	while(t--)
	{	
		int n;
		scanf("%d", &n);
		int pos = check(n);		//求出n在哪一组数之后 
		int cnt = n - b[pos];	//还差多少个数 
		int len = 0, i;
		for(i=1; len < cnt; i++)
			len += (int)log10((double)i) + 1;	//还差多少位数，注意和多少个数不一样，比如10算两位数 
		printf("%d\n", (i-1) / (int)pow(10.0, len-cnt) % 10); 	//要加double 
	}
	return 0;
} 
