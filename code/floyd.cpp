// poj 1125.Stockbroker Grapevine
// floyd�㷨 ��Դ���· 
// references:
// http://blog.csdn.net/y990041769/article/details/37955253

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;
int graph[105][105];
int n;

void floyd()
{
	for(int t=1; t<=n; t++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				graph[i][j] = min(graph[i][j], graph[i][t] + graph[t][j]);
}
int main()
{
	while(scanf("%d", &n) != EOF, n)
	{
		memset(graph, INF, sizeof(graph));
		int m;
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &m);
			while(m--)
			{
				int v, w;
				scanf("%d%d", &v, &w);
				graph[i][v] = w;
			}
		}
		
		floyd();
		
		int ans = INF;
		int index;
		for(int i=1; i<=n; i++)
		{
			int maxn = -1;
			for(int j=1; j<=n; j++)
			{
				if(i == j)	//��ʱgraph[i][j]ӦΪ0������INF 
					continue;
				if(maxn < graph[i][j])	//ѡһ����i���������е�����·���·����֤��Ϣ���� 
					maxn = graph[i][j];
			}
			if(ans > maxn)
			{
				ans = maxn;
				index = i;	//��¼ans�±� 
			}
		}
		printf("%d %d\n", index, ans);
	}
	return 0;
}
