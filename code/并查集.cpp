// poj 2524. Ubiquitous Religions
// 并查集 求最多有多少个祖先
// references:
// no
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int p[50005];
int ans;

void init()
{
	memset(p, -1, sizeof(p));
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
		ans--;
	}
}

int main()
{
	int n, m, k = 1;
	while(scanf("%d%d", &n, &m) != EOF, n, m)
	{
		ans = n;
		init();
		int u, v;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d", &u, &v);
			union_set(u, v);
		}
		printf("Case %d: %d\n", k++, ans);
	}
	return 0;
}
