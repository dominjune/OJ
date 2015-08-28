// poj 1845.Sumdiv
// 费马小定理 + 快速幂 
// references:
// http://blog.csdn.net/u013021513/article/details/47361719
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool isPrime(int x)
{
	if(x == 0 || x == 1)	return 0;
	for(int i=2; i*i<=x; i++)
		if(x % i == 0)
			return 0;
	return 1;	
}

//快速幂取模模板 
long long quick_mod(long long a, long long p)
{
	long long k = p;	//mod的数不能变 
	long long ans = 1;
	while(p)
	{
		if(p & 1)
			ans = (ans * a) % k; 
		a = (a * a) % k;
		p /= 2;
	}
	return ans;
}

int main()
{
	int a, p;
	while(scanf("%d%d", &p, &a) != EOF, p, a)
	{
		if(isPrime(p))
		{
			printf("no\n");
			continue;
		}
		
		long long ans = quick_mod(a, p);
		//printf("%lld\n", ans);
		if(ans % p == a)
		{
			printf("yes\n");
		}
		else
			printf("no\n");
	}
	return 0;
}
