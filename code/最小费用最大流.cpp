// poj 2195.Going Home
// ��С���������
// references:
// http://blog.csdn.net/just_water/article/details/8022955
// http://www.cnblogs.com/kane0526/archive/2013/01/17/2864324.html
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define Max 5005
#define inf 1<<28

using namespace std;

struct point
{
    int x,y;
}human[Max],house[Max];

int n,m;
int S,T;//Դ�㣬���
int cost[Max/10][Max];//����
int cap[Max/10][Max];//����
int dis[Max];
int path[Max];
bool visit[Max];
int q[Max*10];

int spfa()//���·
{
    int i,j;
    for(i=0;i<=T;i++)
    dis[i]=inf,path[i]=-1,visit[i]=0;
    dis[S]=0;
    visit[S]=1;
    int num=0,cnt=0;
    q[num++]=S;
    while(num>cnt)
    {
        int temp=q[cnt++];
        visit[temp]=0;
        for(i=0;i<=T;i++)
        {
            if(cap[temp][i]&&dis[temp]+cost[temp][i]<dis[i])
            {
                path[i]=temp;
                dis[i]=dis[temp]+cost[temp][i];
                if(!visit[i])
                {
                    q[num++]=i;
                    visit[i]=1;
                }
            }
        }
    }
    return dis[T]!=inf;
}

int minCost=0;
void getMaxFlow()//�����������
{
    int maxFlow=inf;

    while(spfa())
    {
        int pre=T;
        while(path[pre]!=-1)
        {
            maxFlow=min(maxFlow,cap[path[pre]][pre]);
            pre=path[pre];
        }
        pre=T;
        minCost+=dis[T]*maxFlow;//��С����
        while(path[pre]!=-1)//������
        {
            cap[path[pre]][pre]-=maxFlow;
            cap[pre][path[pre]]+=maxFlow;
            //minCost+=cost[path[pre]][pre]*maxFlow;
            pre=path[pre];
        }
    }
    cout<<minCost<<endl;
    return ;
}

int getdis(point x, point y)//��������֮��ķ���
{
    return (abs(x.x-y.x)+abs(y.y-x.y));
}
void build_map(int numm,int numh)//��ͼ
{
    int i,j;
    for(i=1;i<=numm;i++)//���㷿�Ӻ���֮��ķ���
    for(j=1;j<=numh;j++)
	{
        cost[i][j+numm]=getdis(human[i],house[j]);
        cost[j+numm][i]=-cost[i][j+numm];//��������������
    }
    for(i=1;i<=numm;i++)//Դ�㵽ÿ���˵�cap,cost
        cap[S][i]=1,cost[S][i]=0;
    for(i=1;i<=numh;i++)//���ӵ�����cap,cost
        cap[i+numm][T]=1;
    for(i=1;i<=numm;i++)//ÿ���˺ͷ���֮���cap
    	for(j=1;j<=numh;j++)
    		cap[i][j+numm]=1;
}
int main()
{
    int i,j,k,l;
    char x;
    while(scanf("%d%d",&n,&m),(n+m))
    {
        memset(cap,0,sizeof(cap));
        memset(cost,0,sizeof(cost));

        int numm=0,numh=0;
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            cin>>x;
            if(x=='m'){
                human[++numm].x=i;
                human[numm].y=j;
            }
            if(x=='H'){
                house[++numh].x=i;
                house[numh].y=j;
            }
        }
        S=0;
        minCost=0;
        T=numm+numh+1;//��ʵnumm==numh��������
        build_map(numm,numh);
        getMaxFlow();
        }
    return 0;
}


