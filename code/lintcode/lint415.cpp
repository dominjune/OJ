// lintcode 415.Valid Palindrome
// Easy 
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
   
    // Challenge: O(n) time without extra memory.
    bool isPalindrome(string& s) {
        // Write your code here
        int n = s.size();
        if(n == 0)	return 1;
        int i = 0, j = n - 1;
        while(i < j)
        {
        	if(isChar(s[i]) && isChar(s[j]))
			{
				if(toLower(s[i]) == toLower(s[j]))
				{
					i++;
					j--;
				}
				else
					return 0;			
        	}
        	else if(isChar(s[i]) && !isChar(s[j]))
        		j--;
        	else
        		i++;
        }
        return 1;
    }
    
private:
    bool isChar(char c)
    {
    	if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'		// ||
			|| c >= '0' && c <= '9')
    		return 1;
    	return 0;
    }
    char toLower(char c)
    {
    	if(c >= 'A' && c <= 'Z')
    		c = c - 'A' + 'a';
    	return c;
    }
};


int main()
{
	string s = "ab";
	Solution sol;
	cout << sol.isPalindrome(s) << endl;
	return 0;
}
