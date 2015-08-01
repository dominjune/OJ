// poj 1061.青蛙的约会
// 扩展欧几里得
// references:
// http://www.cnblogs.com/yueshuqiao/archive/2011/08/23/2150960.html
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b, long long &x, long long &y)
{
	if(b == 0)
	{
		x = 1; 
		y = 0;
		return a;
	}
	else
	{
		long long r = gcd(b, a % b, y, x);
		y -= x * (a / b);
		return r;
	}
}

int main()
{
	long long x, y, m, n, l;
	while(scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l) != EOF)
	{
		long long a, b, xx, yy, d;	//仿佛不用判断正负 
		a = n - m;
		b = l;
		d = gcd(a, b, xx, yy);
		if((x - y) % d != 0)
			printf("Impossible\n");
		else
		{
			xx *= (x - y) / d;
			long long r = l / d;
			xx = (xx % r + r) % r;
			printf("%lld\n", xx);
		}
			
	}
	return 0;
} 
