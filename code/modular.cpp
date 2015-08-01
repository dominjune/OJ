// Modular equation
//模线性方程
//扩展欧几里得 求解x的个数 
// references:
// http://blog.sina.com.cn/s/blog_76eabc150100usbg.html 
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

long long a,b,n;

long long gcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    else
    {
        long long r=gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}

int main()
{
    while(~scanf("%lld %lld %lld",&a,&b,&n))
    {
        long long x,y,ans=0;
        long long d=gcd(a,n,x,y);
        if(b%d==0)
            ans=d;
        printf("%lld\n",ans);
    }
    
    return 0;
} 
