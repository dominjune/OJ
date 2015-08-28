// poj 1611.The Suspects
// 并查集
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
		num[i] = 1;		//记录该点为祖先的后代个数 
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
		num[y] += num[x];	//注意这里是加上x的num[]，不只是++;	
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
				union_set(u, v);	//都跟第一个合并 
				//u = v;
			}
		}
		int x = find(0);	//找到0的祖先 
		printf("%d\n", num[x]);
	}
	return 0;
}
