// poj 1159. Palindrome
// ��Ӷ��ٸ��ַ���ɻ��Ĵ� LCS��Ӧ��
// ������������Ż����д�ѧϰ 
// references:
// http://blog.csdn.net/lyy289065406/article/details/6648163
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s1[5005], s2[5005];
short int dp[5005][5005];	//short int����Ĳ����ռ� 

int LCS(char s1[], char s2[], int len)
{
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=len; i++)
	{
		for(int j=1; j<=len; j++)
		{
			if(s1[i-1] == s2[j-1])
				dp[i%2][j] = dp[(i-1)%2][j-1] + 1;	//��������������� 
			else
				dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
		}
	}
	return dp[len%2][len];
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		scanf("%s", s1);
		for(int i=0; i<n; i++)
			s2[i] = s1[n-i-1];
		printf("%d\n", n - LCS(s1, s2, n));
	}
	return 0;
}
