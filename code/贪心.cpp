// poj 1328. Radar Installation
// 贪心 以岛为圆心做圆交于x轴两点，为岛的可行范围  
// references:
// http://blog.csdn.net/zhengnanlee/article/details/9613161
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

struct point {
	double left;
	double right;
}p[1005];

bool cmp(const point &a, const point &b)
{
	return a.left < b.left;
}

int main()
{
	int n, k = 1;
	double d;
	while(scanf("%d%lf", &n, &d) != EOF, n, d)
	{
		double x, y;
		int flag = 1;
		for(int i=0; i<n; i++)
		{
			scanf("%lf%lf", &x, &y);
			if(fabs(y) > d)
				flag = 0;
			p[i].left = x * 1.0 - sqrt(d * d - y * y);
			p[i].right = x * 1.0 + sqrt(d * d - y * y);
		}
		
		printf("Case %d: ", k++);
		if(!flag)
			printf("-1\n");
		else
		{
			sort(p, p + n, cmp);
			int ans = 1;
			point temp = p[0];
			for(int i=1; i<n; i++)
			{
				if(p[i].left > temp.right)
				{
					ans++;
					temp = p[i];
				}
				else if(p[i].right < temp.right)	
					temp = p[i];
				// 最后一种情况p[i].left < temp.right && p[i].right > temp.right不需要更新temp; 
			}
			printf("%d\n", ans);
		}
		
	}
	return 0;
}


