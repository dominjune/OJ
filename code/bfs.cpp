// poj.3278 Catch That Cow
// bfs
// references:
// http://blog.csdn.net/lyy289065406/article/details/6647886
// http://blog.csdn.net/zhengnanlee/article/details/12952097
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 400015;	//ע����ΪҪ����2������Ū��� 

struct node {
	int pos;
	int count;
	node():pos(-1), count(0){}
	node(int a, int b):pos(a), count(b){}
};

bool vis[N];

int main()
{
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF)	//���ѵ����ԣ����صĵ�һ��һ������̵�·��
	{
		memset(vis, 0, sizeof(vis));
		int ans = 0x3f3f3f3f;
		queue <node> q;
		node s(a, 0);
		vis[a] = 1;
		q.push(s);
		while(!q.empty())
		{
			node temp = q.front();
			q.pop();
			if(temp.pos == b)
			{
				printf("%d\n", temp.count);
				break;
			}
			if(!vis[temp.pos + 1] && temp.pos <= b)	//����֦��ͬѧ��������n=0  k=100000����������������RE
			{
				vis[temp.pos + 1] = 1;
				node next1(temp.pos + 1, temp.count + 1);
				q.push(next1);
			}
			if(!vis[temp.pos - 1] && temp.pos > 0)
			{
				vis[temp.pos - 1] = 1;
				node next2(temp.pos - 1, temp.count + 1);
				q.push(next2);
			}
			if(!vis[temp.pos * 2] && temp.pos <= b)
			{
				vis[temp.pos * 2] = 1;
				node next3(temp.pos * 2, temp.count + 1);
				q.push(next3);
			}	
		}
	}
	return 0;
}
