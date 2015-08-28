// poj 1226.Substrings
// strstr + strncpy
// references:
// http://blog.sina.com.cn/s/blog_691ce2b70101mapk.html
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 105;
char s[N][N];
char sub[N];
char rev[N];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int len = 105;
		int index = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%s", &s[i]);
			if(len > strlen(s[i]))
			{
				len = strlen(s[i]);
				index = i;
			}
		}
		bool flag;
		int i;
		for(i=len; i>=1; i--)
		{		
			for(int j=0; j<=len-i; j++)
			{
				flag = 1;
				memset(sub, 0, sizeof(sub));
				memset(rev, 0, sizeof(rev));
				strncpy(sub, s[index]+j, i);
				//printf("%s ", sub);
				for(int k=0; k<i; k++)
					rev[k] = sub[i-k-1];
				//printf("%s\n", rev);
				for(int k=0; k<n; k++)
				{
					if(strstr(s[k], sub) == NULL && strstr(s[k], rev) == NULL)
					{
						flag = 0;
						break;
					}
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		printf("%d\n", i);
	}
	return 0;
}
