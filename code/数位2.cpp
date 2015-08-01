// poj 3286.How many 0's?
// ��λdp
// references:
// http://www.cnblogs.com/zhj5chengfeng/archive/2013/03/24/2977984.html

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long radix[20];

long long solve(long long x)
{
	if(x < 0)
		return 0;
	int i=1;
	long long ans=1;
	while(i)
	{
		if(radix[i] > x)
			break;
		long long left = x / radix[i];		//���ߵ��� 
		long long right = x % radix[i-1];	//�Ұ�ߵ��� 
		long long now = (x % radix[i] - x % radix[i-1]) / radix[i-1];	//���ڵ����� 
		if(now == 0)
			ans += (left - 1) * radix[i-1] + right + 1;		//�ұ߿���ȡ0
		else
			ans += left * radix[i-1];	//ֻȡ��� 
		i++;
	}
	return ans;
}

int main()
{
	radix[0] = 1;
	for(int i=1; i<=15; i++)
		radix[i] = radix[i-1] * 10;
	long long a, b;
	while(scanf("%lld%lld", &a, &b) != EOF)
	{
		if(a == -1 && b == -1)
			break;
		printf("%lld\n", solve(b) - solve(a-1));	//ע����������� 
	}
	return 0;
} 
