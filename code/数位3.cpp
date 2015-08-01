// poj 2282. The Counting Problem
// 数位dp 统计区间内各个数字出现的次数 
// references:
// http://www.cnblogs.com/pcoda/archive/2012/04/25/2470256.html

#include<cstdio>
#include<algorithm>
using namespace std;
#define lint __int64
int b[9] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };

lint count ( int n, int id )
{
    lint left, m, sum = 0;
    for ( int i = 1; i < 9; i++ )
    {
        left = n / b[i] - (id==0);
        sum += left * b[i-1];
        m = (n % b[i] - n % b[i-1]) / b[i-1]; //求出从第到高的第i位上的具体数字
        if ( m > id ) sum += b[i-1];
        else if ( m == id ) sum += n % b[i-1] + 1;
        if ( n < b[i] ) break;
    }
    return sum;
}

int main()
{
    int x, y;
    while ( scanf("%d%d",&x,&y) && (x||y) )
    {
        if ( x > y ) swap(x,y);
        for ( int i = 0; i <= 9; i++ )
            printf("%I64d ",count(y,i)-count(x-1,i));
        printf("\n");
    }
    return 0;
}
