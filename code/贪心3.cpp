// poj 1456.Supermarket
// ̰�� + ���鼯 
// references:
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100005;

struct Product {
	int val;
	int ddl;
}p[N];

int vis[N];

bool cmp(Product a, Product b)
{
	return a.val > b.val;
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		int maxn = -1;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d", &p[i].val, &p[i].ddl);
		}
		sort(p, p + n, cmp);
		int ans = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=p[i].ddl; j>=1; j--)	//�Ӵ�С����Ȼ���valռ��С�� 
			{
				if(!vis[j])
				{
					vis[j] = 1;
					ans += p[i].val;
					break;
				}
			}
		}
		printf("%d\n", ans);
		
	}
	return 0;
} 
