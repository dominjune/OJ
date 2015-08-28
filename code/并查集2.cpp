// poj 1611.The Suspects
// ���鼯
// references:
// no
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30005;
int n, m;
int p[N];
int num[N];

void init()
{
	for(int i=0; i<n; i++)
	{
		p[i] = -1;
		num[i] = 1;		//��¼�õ�Ϊ���ȵĺ������ 
	}
}

int find(int x)
{
	return p[x] == -1 ? x : p[x] = find(p[x]);
}

void union_set(int u, int v)
{
	int x = find(u);
	int y = find(v);
	if(x != y)
	{
		p[x] = y;
		num[y] += num[x];	//ע�������Ǽ���x��num[]����ֻ��++;	
	}	
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF, n)
	{
		init();
		for(int i=0; i<m; i++)
		{
			int k, u, v;
			scanf("%d", &k);
			scanf("%d", &u);
			for(int j=1; j<k; j++)
			{
				scanf("%d", &v);
				union_set(u, v);	//������һ���ϲ� 
				//u = v;
			}
		}
		int x = find(0);	//�ҵ�0������ 
		printf("%d\n", num[x]);
	}
	return 0;
}
