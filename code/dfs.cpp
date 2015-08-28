// poj 2488.A Knight's Journey
// dfs + 字典序 
// http://blog.csdn.net/lyy289065406/article/details/6647666
// http://www.cnblogs.com/rainydays/archive/2011/05/22/2053574.html
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 30;

struct point {
	int x;
	int y;
}a[N];

bool vis[N][N];
int n, m;
int move_x[] = {-1, 1, -2, 2, -2, 2, -1, 1};	//注意方向顺序 
int move_y[] = {-2, -2, -1,-1, 1, 1, 2, 2};
bool flag;

void dfs(int x, int y, int cur)
{
	if(cur == n * m - 1) 
	{
		for(int i=0; i<cur; i++)
			printf("%c%d", a[i].y - 1 + 'A', a[i].x);
		printf("%c%d\n", y - 1 + 'A', x);
		flag = 1;
	}
	a[cur].x = x;	//记录路径 
	a[cur].y = y;
	for(int i=0; i<8; i++)
	{
		point temp;
		temp.x = x + move_x[i];
		temp.y = y + move_y[i];
		if(!vis[temp.x][temp.y] && temp.x >=1 && temp.x <= n && temp.y >=1 && temp.y <=m && !flag)
		{
			vis[temp.x][temp.y] = 1;
			dfs(temp.x, temp.y, cur + 1);
			vis[temp.x][temp.y] = 0;
		}
	}
}

int main()
{
	int k=1;
	int t;
	scanf("%d", &t);
	while(t--)
	{
		flag = 0;
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &m);
		printf("Scenario #%d:\n", k++);
		for(int i=1; i<=n; i++)		//暴搜 
		{
			for(int j=1; j<=m; j++)
			{
				vis[i][j] = 1;	//标记起点 
				dfs(i, j, 0);
				if(flag)
					break;
				vis[i][j] = 0;
			}
			if(flag)
				break;
		}
		if(!flag)
			printf("impossible\n");
		printf("\n");
	}
	return 0;
}
