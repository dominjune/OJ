// lintcode 419.Roman to Integer
// Medium 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        // Write your code here
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        	ans += toNumber(s[i]);
        int pre = toNumber(s[0]);
        for(int i=1; i<n; i++)
        {
        	int cur = toNumber(s[i]);
        	if(pre * 5 == cur || pre * 10 == cur)
        	{
        		ans -= pre * 2;
        	}
        	pre = cur;
        }
        return ans;
    }
    int toNumber(char ch)
    {
    	if(ch == 'I')	return 1;
    	if(ch == 'V')	return 5;
    	if(ch == 'X')	return 10;
    	if(ch == 'L')	return 50;
    	if(ch == 'C')	return 100;
    	if(ch == 'D')	return 500;
    	if(ch == 'M')	return 1000;
    }
};


int main()
{
	string s = "XCIX";
	Solution sol;
	cout << sol.romanToInt(s) << endl;
	return 0;
}
