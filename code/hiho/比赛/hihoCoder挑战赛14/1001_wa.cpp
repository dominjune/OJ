#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;


int a[50005];
string s1, s2;
int x;

int main()
{
	int t;
	while(cin >> t)
	{
		memset(a, 0, sizeof(a));
		while(t--)
		{
			cin >> s1 >> s2 >> x;
			x *= 2;
			//int len = strlen(s);
			if(s2 == "=")
			{
				a[x]++;	
			}
			else if(s2 == "<")
			{
				for(int i=0; i<x; i++)
					a[i]++;
			}
			else if(s2 == "<=")
			{
				for(int i=0; i<=x; i++)
					a[i]++;
			}
			else if(s2 == ">")
			{
				for(int i=3000; i>x; i--)
					a[i]++;
			}
			else if(s2 == ">=")
			{
				for(int i=3000; i>=x; i--)
					a[i]++;
			}
			
		}
		int ans = 0;
		for(int i=0; i<=3000; i++)
			if(ans < a[i])
				ans = a[i];
		cout << ans << endl;
	}
	return 0;
}
