// sicily 1282. Computer Game
// KMP算法

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;	//目标串长度 
int m;	//源串长度 
int t[60005];	//目标串 
int s[1000001];	//源串 
int next[60005];	//next数组 

void get_next()
{
	int i = 0, j = -1;
	next[0] = -1;
	while(i < n)
	{
		if(j == -1 || t[i] == t[j])		//对目标串处理得到next数组 
		{
			i++, j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int indexOfKMP()
{
	get_next();
	int i=0, j=0;
	while(i != m)
	{
		if(j == -1 || s[i] == t[j])
			i++, j++;
		else
			j = next[j];
		if(j == n)
			return i-n;
	}
	return -1;	//匹配失败 
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		memset(next, 0, sizeof(next));
		for(int i=0; i<n; i++)
			scanf("%d", &t[i]);
		
		scanf("%d", &m);
		for(int i=0; i<m; i++)
			scanf("%d", &s[i]);
		
		int flag = indexOfKMP();
		if(flag == -1)
			printf("no solution\n");
		else
			printf("%d\n", flag);
	}
	return 0;
} 
