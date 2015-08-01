// poj 2115.C Looooops
// 扩展欧几里得 同余方程 
// references:
//
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

long long f(long long k)	// 2^k
{
	long long temp = 1;
	for(int i=0; i<k; i++)
		temp *= 2;
	return temp;
}

int main()
{
	long long a, b, c, k;
	while(scanf("%lld%lld%lld%lld", &a, &b, &c, &k) != EOF, a, b, c, k)
	{
		long long aa, bb, x, y, r, d;
		aa = c;
		bb = f(k);
		//printf("%lld\n", bb);
		d = gcd(aa, bb, x, y);
		//printf("%lld\n", d);
		if((b - a) % d)
			printf("FOREVER\n");
		else
		{
			x *= (b - a) / d;
			r = bb / d;
			x = (x % r + r) % r;
			printf("%lld\n", x);
		}
	}
	return 0;
}


