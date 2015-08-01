//poj 2299
//��״���� 
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
  
int Sum(int pos)	//���±굽1����ĺ� 
{
	int sum=0;
	while(pos > 0)
	{
		sum += c[pos];
		pos -= lowbit(pos);
	}
	return sum;
}

void change(int pos, int add)	//������ͳ�Ƹ����ͣ�����c[pos] += 1; 
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
		for(int i=1; i<=n; i++)	//��ɢ�����ѣ�9,1,0,5,4����ɣ�5,2,1,4,3������Ը�����һ���� 
			hash[q[i].pos]=i;
		
		/*
			��Ϊ���������ԣ����ԴӺ��濪ʼ��ǰ����ÿ�������β�����״���飬��ǰһ�����󣨴�������ԣ���
			����͵�ʱ��պ÷��ϣ���Ϊ��ǰ׺�ͣ���������Եĸ�����������c[]���� 
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
