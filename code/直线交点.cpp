#include <bits/stdc++.h>
#define EPS 1e-6

using namespace std;

struct point {
	double x;
	double y;
	point(double _x=0, double _y=0):x(_x), y(_y){}
}cp; 

inline int dcmp( double x)
{
	if ( x < -EPS ) return -1;	//negative
	return x>EPS;	//bool: 0 or 1
}

double cross(point p0, point p1, point p2)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

//直线相交 
int LineIntersection(point p1, point p2, point p3, point p4)
{
	double u=cross(p1, p2, p3), v=cross(p2, p1, p4);
	if(dcmp(u+v))
	{
		cout << "intersects: " << endl;
		cp.x=(p3.x*v+p4.x*u)/(v+u);
		cp.y=(p3.y*v+p4.y*u)/(v+u);
		cout << cp.x << " " << cp.y << endl;
		return 1;
	}
	if(dcmp(u))	return 0;
	if(dcmp(cross(p3,p4,p1)))	return 0;
	return -1;
}

int main()
{
	point p1(0,0), p2(2,0), p3(1,1), p4(1,-1);
	LineIntersection(p1, p2, p3, p4);
	return 0;
}                         
