// 凸包 
// hdu 1392.Surround the Trees
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN=1005;
const double eps=1e-6;

int top;
struct point {
	int x;
	int y;
}p[MAXN],stackk[MAXN];

double dis(point a, point b)	//距离的平方 
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));	
}

double mult(point p1 , point p2 , point p3) // 叉积 <0 非左旋 
{
    return (p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x);
}

bool cmp(point a, point b)  
{  
	int m = mult(a, b, p[0]);  
	if(m == 0)  
		return dis(p[0],a)-dis(p[0],b)<=0?true:false;  
	else  
		return m>0?true:false;  
}

double graham(int n)
{
	int u=0;
	for(int i=1; i<n; i++)
		if(p[i].y < p[u].y || (p[i].y == p[u].y)&&(p[i].x < p[u].x))	//选y最小的，若一样则x最小 
			u=i;
	swap(p[0], p[u]);	//把选出来的赋值给p[0], swap 
	sort(p+1, p+n, cmp); 	//按其他规则排序，从1-n,除了p[0] 
	p[n]=p[0];				//闭合 
	stackk[0]=p[0], stackk[1]=p[1], stackk[2]=p[2];
	top=2;
	for(int i=3; i<=n; i++)
	{
		while(top >= 2 && mult(stackk[top-1], stackk[top], p[i]) <= 0)	//开始判断，弹出非左旋的点 
			top--;
		stackk[++top]=p[i];
	}
	//求周长 
	double len = 0;
    for(int i=0; i<top; i++) 
		len += dis(stackk[i], stackk[i+1]);
    return len;
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF, n)
	{
		memset(p, 0, sizeof(p));
		memset(stackk, 0, sizeof(stackk));
		for(int i=0; i<n; i++)
			scanf("%d%d", &p[i].x, &p[i].y);
		if(n == 1)
			printf("0.00\n");
		else if(n == 2)
			printf("%.2lf\n", dis(p[0], p[1]));
		else
			printf("%.2lf\n", graham(n));	
	}
	return 0;
}

