// poj 2392.Space Elevator
// ת��Ϊ���ر��� 
// references:
// http://m.blog.csdn.net/blog/u010372095/42032029
// http://blog.csdn.net/u012150279/article/details/12225219
// http://www.cnblogs.com/kedebug/archive/2013/02/06/2908248.html

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
	int h;
	int a;
	int c;
}block[405];

int dp[40005];

bool cmp(node a, node b)
{
	return a.a < b.a;	
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		int ans=0;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d%d", &block[i].h, &block[i].a, &block[i].c);
			block[i].c = min(block[i].c, block[i].a / block[i].h);	//�ų�����ȫ��������� 
		}
			
		sort(block, block+n, cmp);
		// ֱ���׶��ر�����û���Ż� 
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<block[i].c; j++)		//���һ������Ʒ�����01���� 
			{
				for(int k=block[i].a; k>=block[i].h; k--)
				{
					dp[k] = max(dp[k], dp[k-block[i].h]+block[i].h);
					if(ans < dp[k])		//����ȡdp[k]�����ֵ�������������û���� 
						ans = dp[k];
				}
			} 
		}
		printf("%d\n", ans);
	}
	
	
	return 0;
}
