// sicily 1282. Computer Game
// KMP�㷨

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;	//Ŀ�괮���� 
int m;	//Դ������ 
int t[60005];	//Ŀ�괮 
int s[1000001];	//Դ�� 
int next[60005];	//next���� 

void get_next()
{
	int i = 0, j = -1;
	next[0] = -1;
	while(i < n)
	{
		if(j == -1 || t[i] == t[j])		//��Ŀ�괮����õ�next���� 
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
	return -1;	//ƥ��ʧ�� 
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
