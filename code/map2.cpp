// poj 2503.Babelfish
// map
//
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
	//map <string, int> is;
	map <string, string> m;
	string s;
	while(getline(cin, s) && s != "")	//整行输入，再找空格 
	{		
		string s1, s2;	//初始化 
		int len = s.size();
		int pos = s.find(' ');
		for(int i=0; i<pos; i++)
			s1 += s[i];
		for(int i=pos+1; i<len; i++)
			s2 += s[i]; 
		//is[s2] = 1;
		m[s2] = s1;
	}
	while(cin >> s)
	{
		//if(is[s] == 1)
		if(m[s] != "")
			cout << m[s] << endl;
		else
			cout << "eh" << endl;
	}
	return 0;
}
