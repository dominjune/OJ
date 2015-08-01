// poj 1019.Number Sequence
// ��ѧ�� �ҹ��� 
// references:
// ���ͻ��ǿ���������Լ�������: http://blog.csdn.net/lyy289065406/article/details/6648504
// (int)log10((double)i) + 1����һ�����ж���λ������ܺ��ð� 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 32000;
long long a[N];		//���ڼ�λ����λ�� 
long long b[N];	//���ڼ�λ�����ۻ�λ���� 

void init()		//��ʼ��a,b���� 
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

int check(int x)	//�ж�����һ����֮�� 
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
		int pos = check(n);		//���n����һ����֮�� 
		int cnt = n - b[pos];	//������ٸ��� 
		int len = 0, i;
		for(i=1; len < cnt; i++)
			len += (int)log10((double)i) + 1;	//�������λ����ע��Ͷ��ٸ�����һ��������10����λ�� 
		printf("%d\n", (i-1) / (int)pow(10.0, len-cnt) % 10); 	//Ҫ��double 
	}
	return 0;
} 
