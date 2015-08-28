// poj 1703.Find them, Catch them
// 并查集 高级
// references:
// http://www.hankcs.com/program/cpp/poj-1703-find-them-catch-them.html 太巧妙了 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200105;

int p[N];
int n, m;

void init()
{
	for(int i=0; i<N; i++)
	{
		p[i] = -1;
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
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		scanf("%d%d", &n, &m);
		for(int i=0; i<m; i++)
		{
			getchar();
			int u, v;
			char s;
			scanf("%c%d%d", &s, &u, &v);
			if(s == 'A')
			{
				if(find(u) == find(v))
				{
					printf("In the same gang.\n");
				}
				else if(find(u) == find(v + n) || find(u + n) == find(v))
				{
					printf("In different gangs.\n");
				}
				else
					printf("Not sure yet.\n");		
			}
			else
			{
				union_set(u, v + n);
				union_set(u + n, v);
			}
		}
	}
	return 0;
} 

