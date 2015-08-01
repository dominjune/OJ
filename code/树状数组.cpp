//poj 2299
//树状数组 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;  

struct node {
	int val;
	int pos;
}q[500005];

int n;
int c[500005];
int hash[500005];

bool cmp(const node &a, const node &b)
{
	return a.val < b.val;	
}

int lowbit(int x)  
{  
    return x & (-x);  
}  
  
int Sum(int pos)	//求下标到1区间的和 
{
	int sum=0;
	while(pos > 0)
	{
		sum += c[pos];
		pos -= lowbit(pos);
	}
	return sum;
}

void change(int pos, int add)	//这里是统计个数和，所以c[pos] += 1; 
{
	while(pos <= n)
	{
		c[pos] += add;
		pos += lowbit(pos);
	}
}


int main()  
{
	while(cin >> n, n)
	{
		long long ans=0;
		memset(c, 0, sizeof(c));
		for(int i=1; i<=n; i++)
		{
			cin >> q[i].val;
			q[i].pos=i;
		}
		sort(q+1, q+n+1, cmp);
		for(int i=1; i<=n; i++)	//离散化：把（9,1,0,5,4）变成（5,2,1,4,3）逆序对个数是一样的 
			hash[q[i].pos]=i;
		
		/*
			因为求的是逆序对，所以从后面开始往前，把每个数依次插入树状数组，若前一个数大（存在逆序对），
			则求和的时候刚好符合，因为是前缀和，等于逆序对的个数，并更新c[]数组 
		*/
		for(int i=n; i>=1; i--) 
		{
			ans += Sum(hash[i]);
			change(hash[i],1);
		}
		cout << ans << endl;
	}
	
    return 0;  
}  
