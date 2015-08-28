/*
the length of the channel is the horizontal distance between the two villages.
The cost of the channel is the height of the lifter.
最优比率生成树
poj 2728
目标:min{∑costi/∑leni}
逼近的思想，∑costi/∑leni<=x，即 ∑(costi-x*leni)<=0    是一个单调递减函数
 即求边为costi-x*leni的 MST
 */
#include <cstdio>
#include <cstring>
#include <cmath>

const double inf = 1e20;
const int N = 1010;
const double eps = 1e-8;

struct point {
    double x,y,z;
}p[N];

int n,m;
int flag[N];
double D[N];
double len[N][N];
double cost[N][N];
double map[N][N];

double prime()
{
    int i,v,k;
    double ret=0,mi;
    for(i=1;i<=n;i++){
        flag[i]=0;
        D[i]=inf;
    }D[1]=0;flag[1]=1;v=1;
    for(k=1;k<n;k++){
        for(i=1;i<=n;i++)if(!flag[i]){
            if(map[v][i]<D[i])
                D[i]=map[v][i];
        }
        mi=inf;
        for(i=1;i<=n;i++)
            if(!flag[i]&&D[i]<mi)
                mi=D[v=i];
            flag[v]=1;
            ret+=mi;
    }
//  printf("ret=%.2lf\n",ret);
    return ret;
}
double dis(point a,point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double solve(double mid)
{
        int i,j;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                map[i][j]=map[j][i]=cost[i][j]-mid*len[i][j];
        return prime();
}
int main()
{
    int i,j,k;
    while(scanf("%d",&n),n)
    {
         for(i=1;i<=n;i++)
             scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
         for(i=1;i<=n;i++)
             for(j=i+1;j<=n;j++)
             {
                 len[i][j]=len[j][i]=dis(p[i],p[j]);
                 cost[i][j]=cost[j][i]=fabs(p[i].z-p[j].z);
             }
             double a=0,b;
             for(i=1;i<=n;i++)
                 map[i][i]=0.0;
             double l=0.0,r=100.0,mid;
             while(fabs(l-r)>eps)
             {
                 mid=(l+r)/2;
                 if(solve(mid)>eps) l=mid;
                 else r=mid;
             }
             printf("%.3lf\n",r);
              
    }
    return 0;
}  
