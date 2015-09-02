// hihocoder #1061 : Beautiful String

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1100000;
char s[N];
char c[N];
int num[N];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		memset(num, 0, sizeof(num));
		memset(c, 0, sizeof(c));
		
		int n;
		scanf("%d", &n);
		scanf("%s", s);
		int count = 0;
		c[0] = s[0];
		num[0]++;
		for(int i=1; i<n; i++)
		{
			if(s[i] == c[count])
				num[count]++;
			else
			{
				c[++count] = s[i];
				num[count]++;
			}
		}
		c[count+1] = '\0';
		bool flag = 0;
		for(int i=0; i<=count-2; i++)
		{
			if((c[i]+1 == c[i+1] && c[i+1]+1 == c[i+2]) && (num[i] >= num[i+1] && num[i+2] >= num[i+1]))
			{
				flag = 1;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
