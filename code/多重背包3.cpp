// poj 1742.Coins
// ���ر���
// ��˵����һ�ֺܿ�ķ������д��о� 
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
					ans++;	//ͳ���ж����ּ�ֵ 
					//if(j>ans) ans=j; ---ans������ֵ 
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
