// poj 2823.Sliding Window
// 单调队列 滑动窗口的最大最小值 
// references:
// http://blog.csdn.net/justmeh/article/details/5844650
// http://www.cnblogs.com/Jason-Damon/archive/2012/04/19/2457889.html

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000005;

struct node {
	int val;
	int index;
}que[N];

int a[N];
int res_max[N];
int res_min[N];

void get_max(int n, int k)
{
	int i;
    int head = 1;
	int end = 0;
    for(i=0; i<k-1; i++)  //先把前k-1个入队
    {
        while(head <= end && que[end].val <= a[i])  //队尾元素大于要插入的数，删除 
            --end;
        que[++end].val = a[i];
        que[end].index = i;
    }

    for( ; i<n; i++)
    {
        while(head <= end && que[end].val <= a[i])
            --end;
        que[++end].val = a[i];
        que[end].index = i;
        while(que[head].index < i - k  + 1)  //保证头元素的index到i是k个单位长度 
        	head++;
        res_max[i-k+1] = que[head].val;
    }
}

void get_min(int n, int k)
{
	int i;
    int head = 1;
	int end = 0;
    for(i=0; i<k-1; i++)  //先把前k-1个入队
    {
        while(head <= end && que[end].val >= a[i])  //队尾元素大于要插入的数，删除 
            --end;
        que[++end].val = a[i];
        que[end].index = i;
    }

    for( ; i<n; i++)
    {
        while(head <= end && que[end].val >= a[i])
            --end;
        que[++end].val = a[i];
        que[end].index = i;
        while(que[head].index < i - k  + 1)  //保证头元素的index到i是k个单位长度 
        	head++;
        res_min[i-k+1] = que[head].val;
    }
}

int main()
{
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF)
	{
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		get_max(n, k);
		get_min(n, k);
		for(int i=0; i<n-k; i++)
			printf("%d ", res_min[i]);
		printf("%d\n", res_min[n-k]);
		
		for(int i=0; i<n-k; i++)
			printf("%d ", res_max[i]);
		printf("%d\n", res_max[n-k]);
	}
	return 0;
}
