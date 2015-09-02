// hihoCoder #1032 : 最长回文子串
// manacher算法
// references:
// http://www.felix021.com/blog/read.php?2040 	// picture
// http://blog.csdn.net/sdj222555/article/details/6690128
// http://blog.csdn.net/xingyeyongheng/article/details/9310555
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000005;
int p[N*2];
char str[N];
char s[N*2];
int ans;
	
void init(int len)
{
	s[0] = '$';
	s[1] = '#';
	for(int i=0; i<len; i++)
	{
		s[i * 2 + 2] = str[i];
		s[i * 2 + 3] = '#';
	}
	s[len * 2 + 2] = '\0';
	//printf("%s\n", s);
}

void manacher(int len)
{
	init(len);
	int mx = 0, id;
	for(int i=0; i<len*2+2; i++)
	{
		if(mx > i)	// >
		{
			int j = 2 * id - i;
			p[i] = min(p[j], mx - i);
		}
		else
			p[i] = 1;
		while(s[i - p[i]] == s[i + p[i]])
			p[i]++;
		if(i + p[i] > mx)
		{
			mx = i + p[i];
			id = i;
		}
		ans = max(ans, p[i] - 1);
	}	
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", str);
		ans = -1;
		int len = strlen(str);
		manacher(len);
		printf("%d\n", ans);
	}
	return 0;
} 
