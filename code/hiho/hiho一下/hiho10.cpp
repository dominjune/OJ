// hihoCoder Week10
// #1049 : ∫Û–Ú±È¿˙
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s1[30], s2[30], s[30];

void postOrder(char s1[], char s2[], int n)
{
	if(n <= 0)	return ;
	int pos = find(s2, s2+n, s1[0]) - s2;
	postOrder(s1+1, s2, pos);
	postOrder(s1+pos+1, s2+pos+1, n-pos-1);
	printf("%c", s1[0]);
}

int main()
{
	while(scanf("%s%s", s1, s2) != EOF)
	{
		int n = strlen(s1);
		postOrder(s1, s2, n);
		printf("\n");
	}
	return 0;
}
