// poj 1284. Primitive Roots
// Å·À­º¯Êý 
// references:
// http://blog.csdn.net/once_hnu/article/details/6302868
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int euler(int n)
{
	int res=n, a=n;
	for(int i=2; i*i<=n; i++)
	{
		if(a % i == 0)
		{
			res = res / i * (i-1);
			while(a % i == 0)
				a /= i;
		}
	}
	if(a > 1)
		res = res / a * (a-1);
	return res;
}

int main()
{
	int p;
	while(scanf("%d", &p) != EOF)
	{
		printf("%d\n", euler(p-1));
	}
	return 0;
}
