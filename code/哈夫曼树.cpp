// poj 3253.Fence Repair
// ������ ���ȶ��� 
// references:
// ...
/* ����������ˣ�ԭ��������˼���ڳ���ΪL��ľ�����и�Ĵ�����L���������г���ô����������������Ҫ�ĳ��ȵķ��ã����� 
   �����ڳ���Ϊ21����һ�Σ����۾���21��Ȼ���г�ʲô������Ҫ��̰���ˣ����г�13+8����ô��һ����13�ֳ�8+5��ok��
   ���г�16+5,��һ�εĴ��۾���16��...
   ���ԣ�������ľ����е�ԽСԽ��(13<16)����ô����ѡ��ԽС�����Խ�ã���ô���������ȶ�����ÿ��ѡͷ����, bingo
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

long long a[200005];
struct cmp
{
	bool operator () (int x, int y)
	{
		return x > y;
	}
};

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		priority_queue <int, vector<int>, cmp> q;
	
		long long sum=0;
		for(int i=0; i<n; i++)
		{
			cin >> a[i];
			sum += a[i];
			q.push(a[i]);
		}
		
			
		long long a, b, ans=sum;
		
		while(!q.empty())
		{
			a = q.top();
			q.pop();
			b = q.top();
			q.pop(); 
			
			if(a + b != sum)
			{
				ans += a + b;
				q.push(a+b);
			}
			else
				break;
		}
		printf("%I64d\n", ans);		//%lld->wa
	}
	
	
	
	return 0;
}
