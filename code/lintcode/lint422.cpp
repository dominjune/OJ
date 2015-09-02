// lintcode 422.Length of Last Word
// Easy 
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int len = s.size();
        int i;
        string ss;
        for(i=len-1; i>=0; i--)
        	if(s[i] == ' ')
        		break;
        for(int j=i+1; j<len; j++)
        	ss += s[j];
        //cout << ss << endl;
        return ss.size();
    }
};

int main()
{
	Solution sol;
	string s = "Hello World";
	sol.lengthOfLastWord(s);
	return 0;
}
