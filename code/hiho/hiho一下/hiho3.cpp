// hihoCoder Week3
// #1015 : KMPÀ„∑®

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int m;
int nxt[10005];	
char t[10005];
char s[1000005];	


int main()
{
	int k;
	scanf("%d", &k);
	while(k--)
	{
		memset(nxt, 0, sizeof(nxt));
		scanf("%s", t);
		scanf("%s", s);
		n = strlen(t);
		m = strlen(s);
		int i = 0, j = -1;
		nxt[0] = -1;
		while(i < n)
		{
			if(j == -1 || t[i] == t[j])	
			{
				i++, j++;
				nxt[i] = j;
			}
			else
				j = nxt[j];
		}
		int count = 0;
	
		i=0, j=0;
		while(i != m)
		{
			if(j == -1 || s[i] == t[j])
				i++, j++;
			else
				j = nxt[j];
			if(j == n)
			{
				count++;		
				j = nxt[j];
			}
		}
		printf("%d\n", count);
	}
	return 0;
} 
