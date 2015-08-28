// poj 1041.John's trip
// ŷ����· �ڽӾ������ǵ�ͱߵĹ�ϵ
// references:
// http://blog.csdn.net/xymscau/article/details/6450657
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int graph[50][2000];	//[����][�ö���ı�] = ������һ������ 
int vis[2000];
int degree[50];
int maxEdge;
int stack[2000];
int top;

void Euler(int s)
{
	for(int i=1; i<=maxEdge; i++)
	{
		if(!vis[i] && graph[s][i])
		{
			vis[i] = 1;					
			//stack[top++] = i;	//ע��˴�����ջ�Ļ������ܻ�������
			//�����м����һ���㣬������ʼ������չ����������ŷ����·��������һ���������������������... 
			Euler(graph[s][i]);	
			stack[top++] = i;	//�������ŷ��·�ٻ��� 
		}
	}
}

int main()
{
	int x, y, z, s;
	while(scanf("%d%d", &x, &y) != EOF && x && y)
	{
		memset(degree, 0, sizeof(degree));
		memset(vis, 0, sizeof(vis));
		memset(graph, 0, sizeof(graph));
		top = 0;
		maxEdge = 0;
		scanf("%d", &z);
		graph[x][z] = y;
		graph[y][z] = x;
		degree[x]++;
		degree[y]++;
		s = min(x, y);
		maxEdge = max(maxEdge, z);
		
		bool flag = 1;
		while(scanf("%d%d", &x, &y) != EOF && x && y)
		{
			scanf("%d", &z);
			graph[x][z] = y;
			graph[y][z] = x;
			degree[x]++;
			degree[y]++;
			maxEdge = max(maxEdge, z);
		}
		
		for(int i=1; i<45; i++)
		{
			if(degree[i] % 2)
				flag = 0;
		}
		if(!flag)
		{
			printf("Round trip does not exist.\n");
			continue;
		}
		Euler(s);

		for(int i=0; i<top-1; i++)
			printf("%d ", stack[i]);
		printf("%d\n", stack[top-1]); 
	}
	return 0;
}
