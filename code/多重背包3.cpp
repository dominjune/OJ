// poj 1742.Coins
// 多重背包
// 据说这是一种很快的方法，有待研究 
// references:
// http://blog.csdn.net/wangjian8006/article/details/7606917
// http://www.cnblogs.com/rainydays/archive/2011/06/13/2080008.html 
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
 
using namespace std;

#define N 100005

int weight[N],c[N], f[N],user[N];

int main(){
	int i,j,n,m,ans;
	while(scanf("%d%d",&n,&m) && n && m)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&weight[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&c[i]);

		memset(f,0,sizeof(f));
		f[0]=1;
		ans=0;
		for(i=1;i<=n;i++)
		{
			memset(user,0,sizeof(user));
			for(j=weight[i];j<=m;j++)
			{
				if(!f[j] && f[j-weight[i]] && user[j-weight[i]]+1<=c[i])
				{
					f[j]=1;
					user[j]=user[j-weight[i]]+1;
					ans++;	//统计有多少种价值 
					//if(j>ans) ans=j; ---ans是最大价值 
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
