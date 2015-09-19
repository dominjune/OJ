// lintcode 182.Delete Digits
// Medium 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        int n = A.size();
        string ans;
        stack <char> s;
        int count = 0;
        for(int i=0; i<n; i++)
        {
        	while(!s.empty() && s.top() > A[i] && count < k)
        	{
        		s.pop();
        		count++;
        	}
        	if(A[i] != '0' || !s.empty())	//去掉前置0 
        		s.push(A[i]);
        }
        int i = 0;
        while(i < (k - count))	//去掉最后面最大的 
        {
        	s.pop();
        	i++;
        }
    	while(!s.empty())
    	{
    		ans += s.top();
    		s.pop();
    	}   
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
	//int k = 1;
	//string s = "254193";
	int k;
	string s;
	Solution sol;
	while(cin >> s >> k)
	{
		cout << sol.DeleteDigits(s, k) << endl;
	}
	return 0;
}
