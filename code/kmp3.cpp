// poj 2406.Power Strings
// KMP算法　找出組成主串的重複子串
// e.g. abababa -> ab 
// references:
// http://blog.sina.com.cn/s/blog_6635898a0100l3sd.html
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
	while(scanf("%s", s) != EOF)
	{
		if(s[0] == '.')
			break;
		len = strlen(s);
		get_next();
		int ans = 1;
		if(len % (len - next[len]) == 0)
			ans = len / (len - next[len]);
		printf("%d\n", ans);
	}
	return 0;
}
