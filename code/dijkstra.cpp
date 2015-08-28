// poj 1502.MPI Maelstrom
// 裸的Dijkstra最短路 注意模板的准确性 
// references:
// http://blog.csdn.net/wangjian8006/article/details/7871129
// http://blog.sina.com.cn/s/blog_6f6e97490100tlmj.html
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

int n;
char s[N];
int graph[N][N];
int dis[N];
bool vis[N];

void dijkstra(int s)
{
    for(int i=1; i<=n; i++)
    {
    	dis[i] = INF;
    	vis[i] = 0;
    }
    dis[s] = 0;
    //vis[s] = 1;	//不加入集合 
    for(int i=2; i<=n; i++)
    {
    	int minn = INF;
    	int index = s;
    	for(int j=1; j<=n; j++)
    	{
    		if(!vis[j] && dis[j] < minn)
    		{
    			minn = dis[j];
    			index = j;
			}
    	}
    	vis[index] = 1;
    	
    	for(int j=1; j<=n; j++)
    	{
    		if(!vis[j] && dis[j] > minn + graph[index][j])
    			dis[j] = minn + graph[index][j];
    	}
    }
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
    	//memset(graph, 0, sizeof(graph));
    	
    	for(int i=1; i<=n; i++)
    		for(int j=1; j<=n; j++)
    		{
    			if(i != j)
    				graph[i][j] = INF;
    		}
    			
    	for(int i=2; i<=n; i++)
    	{
    		for(int j=1; j<i; j++)
    		{
    			int res = 0;
    			scanf("%s", &s);	//也可以直接用atoi把字符串转换为数字 
    			if(s[0] == 'x'); 
    			else
    			{
    				for(int k=0; k<strlen(s); k++)
    					res = res * 10 + s[k] - '0';
    				graph[i][j] = res;
    				graph[j][i] = res;
    			}
    		}
    	}
    	dijkstra(1);
    	int res = -1;
    	for(int i=1; i<=n; i++)
    	{
    		if(res < dis[i])
    			res = dis[i];
    	}
    	printf("%d\n", res);
    }
    return 0;
}

