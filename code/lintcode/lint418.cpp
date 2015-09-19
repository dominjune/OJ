// lintcode 418.Integer to Roman
// Medium 
#include <bits/stdc++.h>

using namespace std;

int val[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
string syb[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	
class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // Write your code here
        string roman;
        int i=12;
        while(n)
        {
        	int k = n / val[i];
    		while(k--)
    		{
    			roman += syb[i];
    			n -= val[i];
    		}
        	i--;
        	if(i < 0)	break;
        }
        return roman;
    }
};

int main()
{
	int n = 4;
	Solution sol;
	cout << sol.intToRoman(n) << endl;
	return 0;
}
