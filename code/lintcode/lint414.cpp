// lintcode 414.Divide Two Integers
// Medium 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        long long a = dividend, b = divisor;
        long long ans;
        ans = a / b;
        if(ans < INT_MIN || ans > INT_MAX)
        	ans = INT_MAX;
        return ans;
    }
};

int main()
{
	
	return 0;
}

