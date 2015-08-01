// poj 3461.Oulipo
// KMP算法 统计子串匹配次数 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;	//目标串长度 
int m;	//源串长度 
char t[10005];	//目标串 
char s[1000005];	//源串 
int next[10005];	//next数组 

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
			count++;		//每次找到匹配的子串，count++; 
			j = next[j];
		}
	}
	if(count == 0)
		return 0;	//匹配失败 
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
