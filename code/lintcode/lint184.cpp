// lintcode 184.Largest Number
// Medium 
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string s[101];

bool cmp(string a, string b)
{
	return a + b > b + a;
}
	
class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    
    string largestNumber(vector<int> &num) {
        // write your code here      
        int n = num.size();     
        if(n == 0)	return NULL;
        for(int i=0; i<n; i++)
        {
        	int temp = num[i];
			if(temp == 0)	s[i] += '0';	//可以直接to_string(num[i])的啊???	
        	while(temp)
        	{
        		char ch = (temp % 10) + '0';
				s[i] += ch;
				temp /= 10;
        	}
        	reverse(s[i].begin(), s[i].end()); 
        }
        sort(s, s + n, cmp);
        int i = 0;
        while(i < n-1 && s[i] == "0")	//去掉前导0 
        	i++;
        string ans;
        while(i < n)
        {
        	ans += s[i];
        	i++;
        }
        return ans;
    }	
};

int main()
{
	vector <int> v;
	int a[] = {0, 0, 0};
	for(int i=0; i<3; i++)
		v.push_back(a[i]);
	Solution sol;
	cout << sol.largestNumber(v) << endl;
	return 0;
}

