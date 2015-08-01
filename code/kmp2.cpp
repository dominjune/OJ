// poj 3461.Oulipo
// KMP�㷨 ͳ���Ӵ�ƥ����� 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;	//Ŀ�괮���� 
int m;	//Դ������ 
char t[10005];	//Ŀ�괮 
char s[1000005];	//Դ�� 
int next[10005];	//next���� 

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

int KMP()
{
	int count = 0;
	get_next();
	int i=0, j=0;
	while(i != m)
	{
		if(j == -1 || s[i] == t[j])
			i++, j++;
		else
			j = next[j];
		if(j == n)
		{
			count++;		//ÿ���ҵ�ƥ����Ӵ���count++; 
			j = next[j];
		}
	}
	if(count == 0)
		return 0;	//ƥ��ʧ�� 
	return count;
}

int main()
{
	int k;
	scanf("%d", &k);
	while(k--)
	{
		memset(next, 0, sizeof(next));
		scanf("%s", t);
		scanf("%s", s);
		n = strlen(t);
		m = strlen(s);
		int ans = KMP();
		printf("%d\n", ans);
	}
	return 0;
} 
