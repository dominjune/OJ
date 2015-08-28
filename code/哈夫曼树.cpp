// poj 3253.Fence Repair
// 堆排序 优先队列 
// references:
// ...
/* 被题意坑死了，原来他的意思是在长度为L的木板上切割的代价是L，不管你切成怎么样，而不是切我需要的长度的费用！！！ 
   所以在长度为21上切一次，代价就是21，然后切成什么样就需要用贪心了，若切成13+8，那么下一次切13分成8+5就ok了
   若切成16+5,下一次的代价就是16了...
   所以，你会做的就是切的越小越好(13<16)，那么就是选择越小的相加越好，那么就是在优先队列中每次选头两个, bingo
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
