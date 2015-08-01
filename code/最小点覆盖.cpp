// poj 2226.Muddy Fields
// ��С�㸲��
// ת��Ϊ����ͼƥ�� �������㷨
// references:
// http://www.cnblogs.com/ZShogg/archive/2013/03/11/2954740.html
//  http://blog.csdn.net/wangjian8006/article/details/7949005
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1001;	//��ͼ֮��ֹ50??
int n, m;
int nx, ny;		//����ͼ�����Ҳ��ֶ����� 
char s[N][N];	//���� 
int graph[N][N];	//����ͼ 
int map_x[N][N], map_y[N][N];	//Ԥ�������У���������mud 
bool vis[N];
int pre[N];

int dfs(int cur)
{
    for(int i=1; i<=ny; i++)	//ny
    {
        if(!vis[i] && graph[cur][i])
        {
            vis[i]=1;
            if(pre[i] == -1 || dfs(pre[i]))
            {
                pre[i] = cur;
                return 1;
            }
        }
    }    
    return 0;
}

int hungary()
{
	int sum=0;
	for(int i=1; i<=nx; i++)	//nx
    {
        memset(vis, 0, sizeof(vis));
        sum += dfs(i);
    }
    return sum;
}

void get_bipartite()
{
	nx=0;		//����ֵ� 
	int flag;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			flag=0;
			if(s[i][j] == '*')
			{
				while(j <= m && s[i][j] == '*')
				{
					if(!flag)	nx++;
					map_x[i][j++] = nx;
					flag=1;
				}
			}
		}
	}
	
	ny=0;		//����ֵ� 
	for(int j=1; j<=m; j++)
	{
		for(int i=1; i<=n; i++)
		{
			flag=0;
			if(s[i][j] == '*')
			{
				while(i <= n && s[i][j] == '*')
				{
					if(!flag)	ny++;
					map_y[i++][j] = ny;
					flag=1;
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			int x = map_x[i][j];
			int y = map_y[i][j];
			if(x && y)	graph[x][y]=1;	//����ͼ���н������һ��ƥ����� 
		}
	}
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		memset(graph, 0, sizeof(graph));
		memset(pre, -1, sizeof(pre));
		memset(map_x, 0, sizeof(map_x));
		memset(map_y, 0, sizeof(map_y));
		
		for(int i=1; i<=n; i++)
			scanf("%s", s[i]+1);
		get_bipartite();
		
		printf("%d\n", hungary());
	}
	return 0;
}
