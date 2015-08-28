// poj 1320.Street Numbers
// Åå¶û·½³Ì 1+2+...+n = n + n+1 + ... + m
// references:
// http://blog.csdn.net/u013021513/article/details/47361527
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int x,y,x1=3,y1=1,px=3,py=1,d=8,i;
	for(i=0;i<10;i++){
		x=px*x1+d*py*y1;
		y=px*y1+py*x1;
		printf("%10d%10d\n",y,(x-1)/2);
		px=x;
		py=y;
	}
	return 0;
}
