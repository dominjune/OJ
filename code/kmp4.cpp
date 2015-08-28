// poj 1961.Period
// KMP算法 poj 2406的加強版而已  
// references:
// http://blog.csdn.net/niushuai666/article/details/6967716
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000005;

char s[N];
int next[N];
int len;

int get_next()
{
	memset(next, 0, sizeof(next));
	int i = 0, j = -1;
	next[0] = -1;
	while(i < len)
	{
		if(j == -1 || s[i] == s[j])
		{
			i++, j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int main()
{
	int k=1;
	while(scanf("%d", &len) != EOF, len)
	{
		scanf("%s", s);
		get_next();
		int ans = 1;
		int count = 0;
		printf("Test case #%d\n", k++);
		for(int i=1; i<=len; i++)
		{
			if(i % (i - next[i]) == 0)
			{
				ans = i / (i - next[i]);
				if(ans != 1)
					printf("%d %d\n", i, ans);
				
			}		
		} 
		printf("\n");
	}
	return 0;
}
