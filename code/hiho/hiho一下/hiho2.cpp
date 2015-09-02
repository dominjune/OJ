// hihoCoder Week2
// #1014 : Trie�� 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Trie {
	int next[26];
	int flag;
	int cnt;
	Trie()
	{
		memset(next, -1, sizeof(next));
		flag = 0;
		cnt = 0;
	}
}node[1000005];

char s[15];


void build(char s[], int &count)
{
	int p = 0;	//������ 
	int len = strlen(s);
	for(int i=0; i<len; i++)
	{
		 int x = s[i] - 'a';
		 if(node[p].next[x] == -1)
		 {
		 	node[p].next[x] = count++;	//������� 
		 }
		 p = node[p].next[x];
		 node[p].cnt++;		//ͳ���������� 
	}
	
}

void query(char s[])
{
	int p = 0;
	int len = strlen(s);
	for(int i=0; i<len; i++)
	{
		int x = s[i] - 'a';
		if(node[p].next[x] == -1)
		{
			printf("0\n");
			return ;
		}
		p = node[p].next[x];
	}
	printf("%d\n", node[p].cnt);
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int count = 1;
		for(int i=0; i<n; i++)
		{
			scanf("%s", s);
			build(s, count);
		}
		int m;
		scanf("%d", &m);
		for(int i=0; i<m; i++)
		{
			scanf("%s", s);
			query(s);
		}
	}
	return 0;
}
