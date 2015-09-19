// lintcode 1.A + B Problem
// Medium 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        while(b)
        {
        	int carry = a & b;	//carry
	        a = a ^ b;	// add without carry
	        b = carry << 1;
        }
        return a;
    }
};


int main()
{
	int a = 1, b = 2;
	Solution sol;
	cout << sol.aplusb(a, b) << endl;
	return 0;
}
