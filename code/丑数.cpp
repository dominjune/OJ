// ��1-1500֮��ĳ�����ֻ�ܱ�2,3,5�������������������������˷��Ϳ���������еĳ��� 
// ��� 
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
