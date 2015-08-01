// 求1-1500之间的丑数，只能被2,3,5整除，所以用这三个因子作乘法就可以求出所有的丑数 
// 打表 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int ans[1555];

int main()
{
	int p2=1, p3=1, p5=1;
	ans[1]=1;
	int v2, v3, v5;
	for(int i=2; i<=1500; i++)
	{
		v2=ans[p2]*2;
		v3=ans[p3]*3;
		v5=ans[p5]*5;
		ans[i]=min(min(v2, v3), v5);
		if(ans[i] == v2)
			p2++;
		if(ans[i] == v3)
			p3++;
		if(ans[i] == v5)
			p5++;
	}
	int n;
	while(cin >> n, n)
	{
		cout << ans[n] << endl;
	}
	return 0;
}
