// lintcode 420.Count and Say
// Easy 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    //直接模拟 
    string countAndSay(int n) {
        // Write your code here
        string s = "1";
        int i = 1;
        while(i < n)
        {
        	s = getString(s);
        	i++;
        }
        return s;
    }
    
    string getString(string s)
    {
    	int count = 1;	//出现次数 
    	char pre = s[0];
    	int len = s.size();
    	string res;
    	for(int i=1; i<len; i++)
    	{
    		if(s[i] == pre)
    		{
    			count++;
    		}
    		else
    		{
    			char num = count + '0';
    			res = res + num + pre;
    			pre = s[i];	
    			count = 1;
    		}
    	}
    	char num = count + '0';
    	res = res + num + pre;
    	return res;
    }
};

int main()
{
	
	return 0;
}

