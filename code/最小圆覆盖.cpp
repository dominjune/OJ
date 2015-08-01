// ��СԲ����
// hdu 3007.Buried memory
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

struct Point { 
    double x;
	double y; 
} p[10001], o; //������Բ�� 
 
int n; 
double r;//Բ�뾶 
double eps = 1e-6; 
 
double dis(Point a, Point b) 
{ 
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y )*(a.y-b.y)); 
} 
 
Point intersection(Point u1, Point u2, Point v1, Point v2) 
{ 
    Point ans = u1; 
    double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) / 
               ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x)); 
    ans.x += (u2.x - u1.x) * t; 
    ans.y += (u2.y - u1.y) * t; 
    return ans; 
}//���߶ν��� 
 
Point circumcenter(Point a, Point b, Point c) 
{ 
    Point ua, ub, va, vb; 
    ua.x = ( a.x + b.x ) / 2; 
    ua.y = ( a.y + b.y ) / 2; 
    ub.x = ua.x - a.y + b.y;//���� ��ֱ�жϣ����߶ε��Ϊ0 
    ub.y = ua.y + a.x - b.x; 
    va.x = ( a.x + c.x ) / 2; 
    va.y = ( a.y + c.y ) / 2; 
    vb.x = va.x - a.y + c.y; 
    vb.y = va.y + a.x - c.x; 
    return intersection(ua, ub, va, vb); 
} 
//�������������ԲԲ�� 
 
Point min_center() 
{
    o = p[0]; 
    r = 0; 
    for(int i=1; i<n; i++)//׼������ĵ� 
    { 
        if(dis(p[i], o)-r > eps)//�����i���� i-1ǰ��СԲ���� 
        { 
            o = p[i];//��Բ�� 
            r = 0;//���뾶 
 
            for(int j=0; j<i; j++)//ѭ����ȷ���뾶 
            { 
                if(dis(p[j], o)-r > eps) 
                { 
                    o.x = (p[i].x + p[j].x) / 2.0; 
                    o.y = (p[i].y + p[j].y) / 2.0; 
                    r = dis( o, p[j]); 
                    for(int k = 0; k<j; k++) 
                    { 
                        if(dis(o, p[k])-r > eps)//���jǰ���е㲻���� i��jȷ����Բ������� 
                        { 
                            o = circumcenter(p[i], p[j], p[k]); 
                            r = dis(o, p[k]); 
                        } 
                    }//ѭ��������3�㣬��Ϊһ��Բ���3�������ȷ�� 
                } 
            } 
        } 
    } 
    return o; 
} 
 
int main() 
{
    while(scanf("%d", &n) != EOF, n) 
    { 
        for(int i=0; i<n; i++) 
            scanf("%lf%lf", &p[i].x, &p[i].y); 
        min_center(); 
        printf("%.2lf %.2lf %.2lf\n", o.x, o.y, r); 
    } 
    return 0; 
} 
