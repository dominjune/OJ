// lintcode 142. O(1) Check Power of 2
// Easy 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        if(n <= 0)   return 0;
        if((n & (n - 1)) == 0)	//notice the priority of operators &
        	return 1;
    	return 0;
    }
};


int main()
{
	int n = 4;
	Solution sol;
	cout << sol.checkPowerOf2(n) << endl;
	return 0;
}


