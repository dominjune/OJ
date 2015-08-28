// basic
// references:
// http://www.ahathinking.com/archives/120.html

#include <iostream>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;

int max_sum(int *a, int n)
{
	int sum = 0, max_sum = -INF;
	for(int i=0; i<n; i++)
	{
		if(sum < 0)
		{
			sum = a[i];
		}
		else
		{
			sum += a[i];
		}
		if(sum > max_sum)
		{
			max_sum = sum;
		}
	}
	return max_sum;
}
int Maxsum_dp(int * arr, int size)
{
	int End[30] = {-INF};
	int All[30] = {-INF};
	End[0] = All[0] = arr[0];

	for(int i = 1; i < size; ++i)
	{
		End[i] = max(End[i-1]+arr[i],arr[i]);
		All[i] = max(End[i],All[i-1]);
	}
	return All[size-1];
}

int main()
{
	int a[] = {-1, -1, -1, -1, -1};
	printf("%d\n", Maxsum_dp(a, 5));
	printf("%d\n", max_sum(a, 5));
	return 0;
}
