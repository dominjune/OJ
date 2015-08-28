// poj 2367.Genealogical tree
// Õÿ∆À≈≈–Ú
// references:
// no
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 105;
int n;

vector <int> v[N];
int indegree[N];
int ans[N];

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		int count = 0;
		memset(v, 0, sizeof(v));
		memset(indegree, 0, sizeof(indegree));
		for(int i=1; i<=n; i++)
		{
			int m;
			while(scanf("%d", &m) != EOF && m)
			{
				v[i].push_back(m);
				indegree[m]++;
			}
		}
		queue <int> q;
		for(int i=1; i<=n; i++)
		{
			if(indegree[i] == 0)
				q.push(i);
		}
		while(!q.empty())
		{
			int temp = q.front();
			ans[count++] = temp;
			q.pop();
			for(int i=0; i<v[temp].size(); i++)
			{
				if(--indegree[v[temp][i]] == 0)
					q.push(v[temp][i]);
			}
		}
		for(int i=0; i<count-1; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[count-1]);
	}
	return 0;
} 
