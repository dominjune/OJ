// lintcode 417.Valid Number
// Hard 
// http://www.cnblogs.com/TenosDoIt/p/3475305.html
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        // Write your code here
        int n = s.size();
        if(n == 0)	return 0;
        bool can_sign = 1;
        bool can_e = 0;
        bool have_e = 0;
        bool can_dot = 1;
        bool only_space = 0;
        bool is_num = 0;
        bool num_begin = 0;
        for(int i=0; i<n; i++)
        {
        	char ch = s[i];
        	if(ch == ' ')	// space
        	{
        		
        	}
        	else if(ch == '+' || ch == '-')	// sign
        	{
        		if(!can_sign)	return 0;
        		can_sign = 0;
        		num_begin = 1;
        	}
        	else if(ch == 'e')	// e
        	{
        		if(num_begin == 0)	return 0;
        		if(!can_e)	return 0;
        		have_e = 1;
        		can_e = 0;
        		is_num = 0;
        		num_begin = 1;
        		can_sign = 1;
        		can_dot = 0;
        	}
        	else if(ch == '.')	// dot
        	{
        		if(!can_dot)	return 0;
        		can_dot = 0;
        		num_begin = 1;
        		can_sign = 0;
        	}
        	else if(ch >= '0' && ch <= '9')	// num
        	{
        		is_num = 1;
        		num_begin = 1;
        		can_sign = 0;
        		if(!have_e)	can_e = 1;
        	}
        	else	// letter
        		return 0;
        }
        return is_num;
    }
};


int main()
{
	string s = "1e10";
	Solution sol;
	cout << sol.isNumber(s) << endl;
	return 0;
}
