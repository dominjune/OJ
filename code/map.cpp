// poj 2418.Hardwood Species
// stl map
// references:
// http://www.cnblogs.com/rainydays/archive/2011/05/21/2052835.html
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

const int N = 10005;	//species數量 

string s;
string species[N];
map <string, int> m;

int main()
{
	int count = 0;
	int tot = 0;
	while(getline(cin, s) && s != "")
	{
		if(m[s] == 0)
		{
			species[count++] = s;
		}
		m[s]++;	
		tot++;	//注意最後除以總數，坑 
	}
	sort(species, species + count);
	for(int i=0; i<count; i++)
	{
		printf("%s %.4lf\n", species[i].c_str(), m[species[i]] * 1.0 / tot * 100);	//string -> %s 要加上 c_str();
	}
}
